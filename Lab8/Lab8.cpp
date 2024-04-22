#include <jni.h>
#include "Main.h"
#include <cmath>
#include <omp.h> // Include OpenMP header

extern "C" {

    JNIEXPORT jdouble JNICALL Java_Main_calculateMean(JNIEnv* env, jclass obj, jintArray numbers) {
        jsize len = env->GetArrayLength(numbers);
        jint* arr = env->GetIntArrayElements(numbers, 0);

        double sum = 0;
#pragma omp parallel for reduction(+:sum) // Parallel loop to calculate sum
        for (int i = 0; i < len; i++) {
            sum += arr[i];
        }

        env->ReleaseIntArrayElements(numbers, arr, 0);

        return sum / len;
    }

    JNIEXPORT jdouble JNICALL Java_Main_calculateSTDDev(JNIEnv* env, jclass obj, jintArray numbers) {
        jsize len = env->GetArrayLength(numbers);
        jint* arr = env->GetIntArrayElements(numbers, 0);

        double mean = Java_Main_calculateMean(env, obj, numbers);

        double sumSquaredDiffs = 0;
#pragma omp parallel for reduction(+:sumSquaredDiffs) // Parallel loop to calculate sum of squared differences
        for (int i = 0; i < len; i++) {
            double diff = arr[i] - mean;
            sumSquaredDiffs += diff * diff;
        }

        env->ReleaseIntArrayElements(numbers, arr, 0);

        return sqrt(sumSquaredDiffs / len);
    }

}
