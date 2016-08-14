LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := native
LOCAL_SRC_FILES := ../native/hello-jni.c

LOCAL_WHOLE_STATIC_LIBRARIES += crossmobile

# for logging
LOCAL_LDLIBS    += -llog
# for native asset manager
LOCAL_LDLIBS    += -landroid

include $(BUILD_SHARED_LIBRARY)

$(call import-module,CCrossMobileLib/library/make/)
