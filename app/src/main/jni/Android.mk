LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := NativeActivityOne
LOCAL_SRC_FILES := NativeActivityOne.cpp
LOCAL_LDLIBS    := -landroid -llog

include $(BUILD_SHARED_LIBRARY)
