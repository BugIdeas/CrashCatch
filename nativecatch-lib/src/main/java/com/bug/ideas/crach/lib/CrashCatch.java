package com.bug.ideas.crach.lib;


public class CrashCatch {
    public static final String TAG = CrashCatch.class.getSimpleName();
    /** Regular JNI entry point. **/
    native int foo();
}
