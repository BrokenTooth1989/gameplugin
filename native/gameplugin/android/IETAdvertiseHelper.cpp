//
//  IETAdvertiseHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAdvertiseHelper.h"

#include "jni.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#else

#endif
#define CALL_JAVA_PACKAGE "org/cocos2dx/lua/AppActivity"
using namespace std;
using namespace cocos2d;

int IETAdvertiseHelper::showBannerAd(bool isPortrait, bool isBottom)
{
    log("showBannerAd");
    return 40;
}

void IETAdvertiseHelper::hideBannerAd()
{
    log("hideBannerAd");
}

bool IETAdvertiseHelper::isSpotAdReady()
{
    log("isSpotAdReady");
    return true;
}

bool IETAdvertiseHelper::showSpotAd(const std::function<void (bool)> &func)
{
    log("showSpotAd");
    func(true);
    return true;
}

bool IETAdvertiseHelper::isVedioReady()
{

    JniMethodInfo minfo;
    bool isHave = JniHelper::getStaticMethodInfo(minfo,
                                                 CALL_JAVA_PACKAGE,
                                                 "getJavaObj",
                                                 "()Ljava/lang/Object;");
    jobject jobj;
    if(isHave)
    {
        log("call static method");
        jobj = minfo.env->CallStaticObjectMethod(minfo.classID,minfo.methodID);
    }

     jboolean ret;
    //getMethodInfo判断java定义的类非静态函数是否存在，返回bool
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"isReadyAd","()Z");
    if(re)
    {
        log("call no-static method");
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        ret = minfo.env->CallBooleanMethod(jobj,minfo.methodID,NULL);
    }

    return ret;
}

bool IETAdvertiseHelper::showVedioAd(const std::function<void (bool)> &viewFunc, const std::function<void (bool)> &clickFunc)
{
    log("showVedioAd");

     //  //1. 获取activity静态对象
    JniMethodInfo minfo;
    bool isHave = JniHelper::getStaticMethodInfo(minfo,
                                                 CALL_JAVA_PACKAGE,
                                                 "getJavaObj",
                                                 "()Ljava/lang/Object;");
    jobject jobj;
    if(isHave)
    {
        log("call static method");
        jobj = minfo.env->CallStaticObjectMethod(minfo.classID,minfo.methodID);
    }

     jboolean ret;
    //getMethodInfo判断java定义的类非静态函数是否存在，返回bool
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"showAd","()Z");
    if(re)
    {
        log("call no-static method");
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        ret = minfo.env->CallBooleanMethod(jobj,minfo.methodID,NULL);
    }

    return ret;
}
void IETAdvertiseHelper::setVideoAdNames(cocos2d::ValueVector names)
{}
void IETAdvertiseHelper::setBannerAdName(std::string name)
{}
void IETAdvertiseHelper::setSpotAdNames(cocos2d::ValueVector names)
{}
