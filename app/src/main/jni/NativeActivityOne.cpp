#include <jni.h>
#include <android/native_activity.h>

#include "mylog.h"

static void printInfo(ANativeActivity* activity) {
	LOGI(2, "internalDataPath: %s", activity->internalDataPath);
	LOGI(2, "externalDataPath: %s", activity->externalDataPath);
	jmethodID toStringMID;
	jclass activityCls = activity->env->GetObjectClass(activity->clazz);
	toStringMID = activity->env->GetMethodID(activityCls, "toString", "()Ljava/lang/String;");
	jstring activityStr = (jstring)activity->env->CallObjectMethod(activity->clazz, toStringMID);
	const char* activityCharStr = activity->env->GetStringUTFChars(activityStr, NULL);
	LOGI(2, "Activity toString: %s", activityCharStr);
	activity->env->ReleaseStringUTFChars(activityStr, activityCharStr);
	LOGI(2, "SDK version: %d", activity->sdkVersion);
}

static void onStart(ANativeActivity* activity) {
    LOGI(2, "-----onStart: %p\n", activity);
//    printInfo(activity);
}

static void onResume(ANativeActivity* activity) {
    LOGI(2, "-----onResume: %p\n", activity);
//    printInfo(activity);
}

static void* onSaveInstanceState(ANativeActivity* activity, size_t* outLen) {
    LOGI(2, "-----onSaveInstanceState: %p, %d\n", activity, *outLen);
//    printInfo(activity);
    return NULL;
}

static void onPause(ANativeActivity* activity) {
    LOGI(2, "-----onPause: %p\n", activity);
//	printInfo(activity);
}

static void onStop(ANativeActivity* activity) {
    LOGI(2, "-----onStop: %p\n", activity);
//	printInfo(activity);
}

static void onDestroy(ANativeActivity* activity) {
    LOGI(2, "-----onDestroy: %p\n", activity);
//	printInfo(activity);
}

static void onWindowFocusChanged(ANativeActivity* activity, int focused) {
    LOGI(2, "-----onWindowFocusChanged: %p -- %d\n", activity, focused);
//	printInfo(activity);
}

static void onNativeWindowCreated(ANativeActivity* activity, ANativeWindow* window) {
    LOGI(2, "-----onNativeWindowCreated: %p -- %p\n", activity, window);
//	printInfo(activity);
}

static void onNativeWindowResized(ANativeActivity* activity, ANativeWindow* window) {
    LOGI(2, "-----onNativeWindowResized: %p -- %p\n", activity, window);
//	printInfo(activity);
}

static void onNativeWindowRedrawNeeded(ANativeActivity* activity, ANativeWindow* window) {
    LOGI(2, "-----onNativeWindowRedrawNeeded: %p -- %p\n", activity, window);
//	printInfo(activity);
}

static void onNativeWindowDestroyed(ANativeActivity* activity, ANativeWindow* window) {
    LOGI(2, "-----onNativeWindowDestroyed: %p -- %p\n", activity, window);
//	printInfo(activity);
}

static void onInputQueueCreated(ANativeActivity* activity, AInputQueue* queue) {
    LOGI(2, "-----onInputQueueCreated: %p -- %p\n", activity, queue);
//	printInfo(activity);
}

static void onInputQueueDestroyed(ANativeActivity* activity, AInputQueue* queue) {
    LOGI(2, "-----onInputQueueDestroyed: %p -- %p\n", activity, queue);
//	printInfo(activity);
}

static void onContentRectChanged(ANativeActivity* activity, const ARect* rect) {
    LOGI(2, "-----onContentRectChanged: %p -- %p\n", activity, rect);
//	printInfo(activity);
}

static void onConfigurationChanged(ANativeActivity* activity) {
    LOGI(2, "-----onConfigurationChanged: %p\n", activity);
//	printInfo(activity);
}

static void onLowMemory(ANativeActivity* activity) {
    LOGI(2, "-----onLowMemory: %p\n", activity);
//	printInfo(activity);
}

void ANativeActivity_onCreate(ANativeActivity* activity,
        void* savedState, size_t savedStateSize) {
	printInfo(activity);
	LOGI(2, "-----ANativeActivity_onCreate");
	//the callbacks the Android framework will call into a native application
	//all these callbacks happen on the main thread of the app, so we'll
	//need to make sure the function doesn't block
	activity->callbacks->onStart = onStart;
	activity->callbacks->onResume = onResume;
	activity->callbacks->onSaveInstanceState = onSaveInstanceState;
	activity->callbacks->onPause = onPause;
	activity->callbacks->onStop = onStop;
	activity->callbacks->onDestroy = onDestroy;
	activity->callbacks->onWindowFocusChanged = onWindowFocusChanged;
	activity->callbacks->onNativeWindowCreated = onNativeWindowCreated;
	activity->callbacks->onNativeWindowResized = onNativeWindowResized;
	activity->callbacks->onNativeWindowRedrawNeeded = onNativeWindowRedrawNeeded;
	activity->callbacks->onNativeWindowDestroyed = onNativeWindowDestroyed;
	activity->callbacks->onInputQueueCreated = onInputQueueCreated;
	activity->callbacks->onInputQueueDestroyed = onInputQueueDestroyed;
	activity->callbacks->onContentRectChanged = onContentRectChanged;
	activity->callbacks->onConfigurationChanged = onConfigurationChanged;
	activity->callbacks->onLowMemory = onLowMemory;

	activity->instance = NULL;
}
