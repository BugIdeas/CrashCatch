package com.bug.ideas.crash.lib;


public class CrashCatch {
    public static final String TAG = CrashCatch.class.getSimpleName();

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * Regular JNI entry point.
     **/
    public static native int foo();
}
