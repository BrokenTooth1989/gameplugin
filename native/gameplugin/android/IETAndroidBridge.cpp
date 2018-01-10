//
//  IETAndroidBridge.cpp
//  gameplugin
//
//  Created by geekgy on 15/9/5.
//
//

#include "IETAndroidBridge.h"
#include <jni.h>
#include "platform/android/jni/JniHelper.h"

using namespace cocos2d;

IETAndroidBridge *IETAndroidBridge::instance = nullptr;

IETAndroidBridge* IETAndroidBridge::getInstance()
{
    if (!instance)
    {
        instance = new IETAndroidBridge();
    }
    return instance;
}

std::string IETAndroidBridge::callJavaMethod(std::string className, std::string methodName, std::string reqData)
{
    return this->callJavaMethod(className, methodName, reqData, -1);
}

void IETAndroidBridge::callJavaMethodAsync(std::string className, std::string methodName, std::string reqData, std::function<void (std::string)> handler)
{
    int reqId = requestId++;
    handlerMap[reqId] = handler;
    this->callJavaMethod(className, methodName, reqData, reqId);
}

void IETAndroidBridge::handleJavaRes(int responseId, std::string resData)
{
    std::function<void (std::string)> handler = handlerMap[responseId];
    handler(resData);
    handlerMap[responseId] = nullptr;
}

std::string IETAndroidBridge::callJavaMethod(std::string className, std::string methodName, std::string reqData, int requestId)
{
    JNIEnv* env = JniHelper::getEnv();
    jclass clazz = env->FindClass("com/joycastle/gameplugin/NativeUtil");
    jmethodID method = env->GetStaticMethodID(clazz, "invokeJavaMethod", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)Ljava/lang/String;");
    jstring jclassName = env->NewStringUTF(className.c_str());
    jstring jmethodName = env->NewStringUTF(methodName.c_str());
    jstring jreqData = env->NewStringUTF(reqData.c_str());
    jstring resData_ = (jstring)(env->CallStaticObjectMethod(clazz, method, jclassName, jmethodName, jreqData, requestId));
    const char* resData = env->GetStringUTFChars((jstring)resData_, 0);
    env->DeleteLocalRef(clazz);
    env->DeleteLocalRef(jclassName);
    env->DeleteLocalRef(jmethodName);
    env->DeleteLocalRef(jreqData);
    env->ReleaseStringUTFChars(resData_, resData);
    return resData;
}

IETAndroidBridge::IETAndroidBridge()
:requestId(0)
{
}

IETAndroidBridge::~IETAndroidBridge()
{
}

JNIEXPORT void JNICALL Java_com_joycastle_gameplugin_NativeUtil_invokeCppMethod(JNIEnv *env, jclass type, jint responseId, jstring resData_)
{
    const char *resData = env->GetStringUTFChars(resData_, 0);
    IETAndroidBridge::getInstance()->handleJavaRes(responseId, resData);
    env->ReleaseStringUTFChars(resData_, resData);
}
