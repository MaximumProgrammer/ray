// Copyright 2017 The Ray Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class io_ray_runtime_gcs_GlobalStateAccessor */

#ifndef _Included_io_ray_runtime_gcs_GlobalStateAccessor
#define _Included_io_ray_runtime_gcs_GlobalStateAccessor
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeCreateGlobalStateAccessor
 * Signature: (Ljava/lang/String;Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeCreateGlobalStateAccessor(JNIEnv *,
                                                                            jobject,
                                                                            jstring,
                                                                            jstring);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeDestroyGlobalStateAccessor
 * Signature: (J)V
 */
JNIEXPORT void JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeDestroyGlobalStateAccessor(JNIEnv *,
                                                                             jobject,
                                                                             jlong);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeConnect
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeConnect(JNIEnv *, jobject, jlong);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetAllJobInfo
 * Signature: (J)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetAllJobInfo(JNIEnv *, jobject, jlong);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetNextJobID
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetNextJobID(JNIEnv *, jobject, jlong);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetAllNodeInfo
 * Signature: (J)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetAllNodeInfo(JNIEnv *, jobject,
                                                                 jlong);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetNodeResourceInfo
 * Signature: (J[B)[B
 */
JNIEXPORT jbyteArray JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetNodeResourceInfo(JNIEnv *, jobject,
                                                                      jlong, jbyteArray);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetAllActorInfo
 * Signature: (J)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetAllActorInfo(JNIEnv *, jobject,
                                                                  jlong);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetActorInfo
 * Signature: (J[B)[B
 */
JNIEXPORT jbyteArray JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetActorInfo(JNIEnv *, jobject, jlong,
                                                               jbyteArray);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetPlacementGroupInfo
 * Signature: (J[B)[B
 */
JNIEXPORT jbyteArray JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetPlacementGroupInfo(JNIEnv *, jobject,
                                                                        jlong,
                                                                        jbyteArray);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetPlacementGroupInfoByName
 * Signature: (JLjava/lang/String;Z)[B
 */
JNIEXPORT jbyteArray JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetPlacementGroupInfoByName(
    JNIEnv *, jobject, jlong, jstring, jboolean);

/*
 * Class:     io_ray_runtime_gcs_GlobalStateAccessor
 * Method:    nativeGetAllPlacementGroupInfo
 * Signature: (J)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL
Java_io_ray_runtime_gcs_GlobalStateAccessor_nativeGetAllPlacementGroupInfo(JNIEnv *,
                                                                           jobject,
                                                                           jlong);

#ifdef __cplusplus
}
#endif
#endif
