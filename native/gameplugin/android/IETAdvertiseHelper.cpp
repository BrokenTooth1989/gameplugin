//
//  IETAdvertiseHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAdvertiseHelper.h"
#include "IETAndroidBridge.h"
#include "jni.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#else
#endif

#include "json/document.h"  
#include "json/writer.h"  
#include "json/stringbuffer.h"  
using namespace  rapidjson; 

#define CALL_JAVA_PACKAGE "org/cocos2dx/lua/AppActivity"
using namespace std;
using namespace cocos2d;

#define JAVA_CLASS_NAME "com.joycastle.gameplugin.AdvertiseHelper"

int IETAdvertiseHelper::showBannerAd(bool isPortrait, bool isBottom)
{
        
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(isPortrait,allocate);
    arr.PushBack(isBottom,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    std::string height = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"showBannerAd",reqData);
    return atoi(height.c_str());
}

void IETAdvertiseHelper::hideBannerAd()
{
    rapidjson::Value msg(rapidjson::kObjectType);
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(msg,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"hideBannerAd",reqData);
}

bool IETAdvertiseHelper::isSpotAdReady()
{
    log("isSpotAdReady");
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"hideBannerAd",reqData);
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
    // rapidjson::Value arr(rapidjson::kArrayType);
    // rapidjson::StringBuffer  buffer;
    // rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    // rapidjson::Document document ;
    // document.SetObject();
    // rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    // document.AddMember("json",arr,allocate);
    // document.Accept(writer);
    // auto reqData = buffer.GetString();

    // std::string isReady = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"isVideoAdReady",reqData);
    // log(" IETAdvertiseHelper::isVedioReady() :%s",isReady.c_str());

    // return isReady=="true" ? true:false;

    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::Value msg(rapidjson::kObjectType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethodAsync(JAVA_CLASS_NAME,"showVideoAd",reqData,[=](std::string resData){
        log("IETSystemUtil::setNotificationState:  %s", resData.c_str());
    });

    return true;
}

bool IETAdvertiseHelper::showVedioAd(const std::function<void (bool)> &viewFunc, const std::function<void (bool)> &clickFunc)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::Value msg(rapidjson::kObjectType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    // arr.PushBack(msg,allocate);
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethodAsync(JAVA_CLASS_NAME,"showVideoAd",reqData,[=](std::string resData){
        log("IETSystemUtil::setNotificationState:  %s", resData.c_str());
    });

  
    return false;
}
void IETAdvertiseHelper::setVideoAdNames(cocos2d::ValueVector names)
{}
void IETAdvertiseHelper::setBannerAdName(std::string name)
{}
void IETAdvertiseHelper::setSpotAdNames(cocos2d::ValueVector names)
{}
