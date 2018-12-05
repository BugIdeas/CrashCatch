#include <jni.h>
#include "coffeejni.h"
#include "coffeecatch.h"

JNIEXPORT jint JNICALL
Java_com_bug_ideas_crach_lib_CrashCatch_foo(JNIEnv *env, jobject instance) {

    // TODO

}


/** The potentially dangerous function. **/
jint call_dangerous_function(JNIEnv* env, jobject object) {
    // ... do dangerous things!
    return 42;
}

/** Protected function stub. **/
void foo_protected(JNIEnv* env, jobject object, jint *retcode) {
    /* Try to call 'call_dangerous_function', and raise proper Java Error upon
     * fatal error (SEGV, etc.). **/
    COFFEE_TRY_JNI(env, *retcode = call_dangerous_function(env, object));
}

/** Regular JNI entry point. **/
jint Java_com_example_android_MyNative_foo(JNIEnv* env, jobject object) {
    jint retcode = 0;
    foo_protected(env, object, &retcode);
    return retcode;
}