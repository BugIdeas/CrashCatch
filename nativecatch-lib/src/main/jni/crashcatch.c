#include <jni.h>
#include <stdlib.h>
#include <android/log.h>
#include "coffeecatch.h"

//log定义
#define  LOG    "ncc" // 这个是自定义的LOG的TAG
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG,__VA_ARGS__) // 定义LOGD类型
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG,__VA_ARGS__) // 定义LOGI类型
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG,__VA_ARGS__) // 定义LOGF类型

static char string_buffer[256];

int recurse_madness(int level) {
    static int var[] = {1, 2};
    if (level > 2000) {
        return 1 + level;
    } else {
        return recurse_madness(level + 1) * var[level];
    }
}

static __attribute__ ((noinline)) void demo(int *fault) {
    COFFEE_TRY() {
        recurse_madness(42);
        *fault = 0;
    } COFFEE_CATCH() {
        const char *const message = coffeecatch_get_message();
        LOGW("%s", message);
        *fault = 1;
    }
    COFFEE_END();
}

JNIEXPORT jint JNICALL
Java_com_bug_ideas_crash_lib_CrashCatch_foo(JNIEnv *env, jclass type) {

    int fault = 0;
    LOGW("running demo...:%i\n", fault);
    demo(&fault);
    if (fault != 0) {
        LOGW("** crash detected: %s\n", string_buffer);
        exit(EXIT_FAILURE);
    }
    LOGW("success!\n");

    return EXIT_SUCCESS;

}