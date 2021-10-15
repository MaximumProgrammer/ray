import pytest

import ray
from ray.serve.backend_state import BackendVersion


def test_validation():
    # Code version must be a string.
    with pytest.raises(TypeError):
        BackendVersion(123, None)

    # Can't pass unhashable type as user config.
    with pytest.raises(TypeError):
        BackendVersion(123, set())

    # Can't pass nested unhashable type as user config.
    with pytest.raises(TypeError):
        BackendVersion(123, {"set": set()})


def test_code_version():
    v1 = BackendVersion("1", None)
    v2 = BackendVersion("1", None)
    v3 = BackendVersion("2", None)

    assert v1 == v2
    assert hash(v1) == hash(v2)
    assert v1 != v3
    assert hash(v1) != hash(v3)


def test_user_config_basic():
    v1 = BackendVersion("1", "1")
    v2 = BackendVersion("1", "1")
    v3 = BackendVersion("1", "2")

    assert v1 == v2
    assert hash(v1) == hash(v2)
    assert v1 != v3
    assert hash(v1) != hash(v3)


def test_user_config_hashable():
    v1 = BackendVersion("1", ("1", "2"))
    v2 = BackendVersion("1", ("1", "2"))
    v3 = BackendVersion("1", ("1", "3"))

    assert v1 == v2
    assert hash(v1) == hash(v2)
    assert v1 != v3
    assert hash(v1) != hash(v3)


def test_user_config_list():
    v1 = BackendVersion("1", ["1", "2"])
    v2 = BackendVersion("1", ["1", "2"])
    v3 = BackendVersion("1", ["1", "3"])

    assert v1 == v2
    assert hash(v1) == hash(v2)
    assert v1 != v3
    assert hash(v1) != hash(v3)


def test_user_config_dict_keys():
    v1 = BackendVersion("1", {"1": "1"})
    v2 = BackendVersion("1", {"1": "1"})
    v3 = BackendVersion("1", {"2": "1"})

    assert v1 == v2
    assert hash(v1) == hash(v2)
    assert v1 != v3
    assert hash(v1) != hash(v3)


def test_user_config_dict_vals():
    v1 = BackendVersion("1", {"1": "1"})
    v2 = BackendVersion("1", {"1": "1"})
    v3 = BackendVersion("1", {"1": "2"})

    assert v1 == v2
    assert hash(v1) == hash(v2)
    assert v1 != v3
    assert hash(v1) != hash(v3)


def test_user_config_nested():
    v1 = BackendVersion("1", [{"1": "2"}, {"1": "2"}])
    v2 = BackendVersion("1", [{"1": "2"}, {"1": "2"}])
    v3 = BackendVersion("1", [{"1": "2"}, {"1": "3"}])

    assert v1 == v2
    assert hash(v1) == hash(v2)
    assert v1 != v3
    assert hash(v1) != hash(v3)


def test_user_config_nested_in_hashable():
    v1 = BackendVersion("1", ([{"1": "2"}, {"1": "2"}], ))
    v2 = BackendVersion("1", ([{"1": "2"}, {"1": "2"}], ))
    v3 = BackendVersion("1", ([{"1": "2"}, {"1": "3"}], ))

    assert v1 == v2
    assert hash(v1) == hash(v2)
    assert v1 != v3
    assert hash(v1) != hash(v3)


def test_hash_consistent_across_processes(serve_instance):
    @ray.remote
    def get_version():
        return BackendVersion("1", ([{"1": "2"}, {"1": "2"}], ))

    assert len(set(ray.get([get_version.remote() for _ in range(100)]))) == 1


if __name__ == "__main__":
    import sys
    sys.exit(pytest.main(["-v", "-s", __file__]))
