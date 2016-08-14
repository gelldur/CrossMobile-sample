//
// Created by dawid on 8/9/16.
//

#include "Android.h"
#include <AppMain.h>
#include <log.h>
#include <JniObject.h>

#ifdef __cplusplus
extern "C" {
#endif

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	DLOG("onLoad #####################################################33");
	JNIEnv* env;
	if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK)
	{
		return -1;
	}

	Jni::get().onLoad(vm);

	return JNI_VERSION_1_6;
}

void Java_com_cross_mobile_CrossMobileApplication_onCreate(JNIEnv* env, jobject thiz)
{
	startApplication(0, nullptr);
}

#ifdef __cplusplus
}
#endif
