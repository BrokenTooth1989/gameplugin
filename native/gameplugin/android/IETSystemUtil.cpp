//
//  IETSystemUtil.cpp
//  blackjack
//
//  Created by geekgy on 8/24/16.
//
//

#include "IETSystemUtil.h"

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "network/HttpClient.h"
#include "IETAndroidBridge.h"

#include "json/document.h"  
#include "json/writer.h"  
#include "json/stringbuffer.h"  
using namespace  rapidjson; 

#include "jni.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#endif


#define JAVA_CLASS_NAME  "com.joycastle.gamepluginbase.SystemUtil"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace network;

int IETSystemUtil::getDebugMode() {
    // rapidjson::Value arr(rapidjson::kArrayType);
    // rapidjson::StringBuffer  buffer;
    // rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    // rapidjson::Document document ;
    // document.SetObject();
    // rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    // document.AddMember("json", arr, allocate);
    // document.Accept(writer);
    // auto reqData = buffer.GetString();
    // std::string isDebug = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getDebugMode",reqData);
    // int mode = isDebug=="0" ? 0 : 1;
    // return mode;
    return 3;
}

long IETSystemUtil::getCpuTime()
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    
    // log("CurrentTime MillSecond %f", (double)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000);

    return (long)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000;

}

bool IETSystemUtil::isJailbroken()
{

    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string isRoot = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"isRoot",reqData);
    bool isroot = isRoot == "0" ? true:false;
    return isroot;
}

std::string IETSystemUtil::getAppBundleId()
{

    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string bundle = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getBundleId",reqData);
    return bundle;
}

std::string IETSystemUtil::getAppName()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string appName = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getAppName",reqData);
    return appName;
}
std::string IETSystemUtil::getAppVersion()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string version = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getAppVer",reqData);
    return version;
}
std::string IETSystemUtil::getCountryCode()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string code = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getCountryCode",reqData);
    return code;
}
std::string IETSystemUtil::getLanguageCode()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string code = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getLanguageCode",reqData);
    return code;
}
std::string IETSystemUtil::getDeviceName()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string device = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getDeviceName",reqData);
    return device;
}
std::string IETSystemUtil::getSystemVersion()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string version = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getSystemVersion",reqData);
    return version;
}
std::string IETSystemUtil::getNetworkState()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string state = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getNetworkState",reqData);
    return state;
}
void IETSystemUtil::vibrate()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"vibrate",reqData);
}
void IETSystemUtil::showAlertDialog(std::string title, std::string message, std::string cancelBtnTitle, cocos2d::ValueVector otherBtnTitles, const std::function<void (int)> &func)
{}
void IETSystemUtil::showProgressDialog(std::string message, int percent)
{}
void IETSystemUtil::hideProgressDialog()
{}
void IETSystemUtil::showLoading(std::string message)
{}
void IETSystemUtil::hideLoading()
{}
void IETSystemUtil::showMessage(std::string message)
{}
void IETSystemUtil::saveImage(std::string imgPath, std::string album, const std::function<void (bool, std::string)> &func)
{}
void IETSystemUtil::sendEmail(std::string subject, cocos2d::ValueVector, std::string emailBody, const std::function<void (bool, std::string)> &func)
{
}
void IETSystemUtil::share(cocos2d::ValueVector items)
{}
void IETSystemUtil::keychainSet(std::string key, std::string value)
{}
std::string IETSystemUtil::keychainGet(std::string key)
{
    return "";
}
std::string IETSystemUtil::getPlatCfgValue(std::string key)
{
    return "";
}
void IETSystemUtil::postNotification(cocos2d::ValueMap map)
{
    rapidjson::Value msg(rapidjson::kObjectType);
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    for (auto iter = map.cbegin(); iter != map.cend(); ++iter)
    {
        msg.AddMember(iter->first.c_str(),iter->second.asString().c_str(),allocate);
    }
    arr.PushBack(msg,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"postNotification",reqData);
}

void IETSystemUtil::copyToPasteboard(std::string str)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(str.c_str(),allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"copyToClipboard",reqData);
}


int IETSystemUtil::getAppBuild()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string appbuild = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getAppBuild",reqData);
    return atoi(appbuild.c_str());
}
std::string IETSystemUtil::getDeviceModel()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string model = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getDeviceModel",reqData);
    return model;
}
std::string IETSystemUtil::getDeviceType()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string type = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getDeviceType",reqData);
    return type;
}
std::string IETSystemUtil::getSystemName()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string sysname = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getSystemName",reqData);
    return sysname;
}
std::string IETSystemUtil::getIDFV()
{
    assert(false);
    return "";
}
std::string IETSystemUtil::getIDFA()
{
    assert(false);
    return "";
}
std::string IETSystemUtil::getUUID()
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    std::string UUID = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getUDID",reqData);
    return UUID;
}
void IETSystemUtil::setBadgeNum(int num)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(num,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"setBadgeNum",reqData);
}

void IETSystemUtil::setNotificationState(bool enable)
{
    // rapidjson::Value arr(rapidjson::kArrayType);
    // rapidjson::Value msg(rapidjson::kObjectType);
    // rapidjson::StringBuffer  buffer;
    // rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    // rapidjson::Document document ;
    // document.SetObject();
    // rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    // msg.AddMember("title","hello world",allocate);
    // arr.PushBack(msg,allocate);
    // document.AddMember("json", arr, allocate);
    // document.Accept(writer);
    // auto reqData = buffer.GetString();
                                                                                    
    // IETAndroidBridge::getInstance()->callJavaMethodAsync(JAVA_CLASS_NAME,"showAlertDialog",reqData,[=](std::string resData){
    //     log("IETSystemUtil::setNotificationState:  %s", resData.c_str());
    // });
}


void IETSystemUtil::requestUrl(std::string requestType, std::string url, cocos2d::ValueMap data, const std::function<void (bool, std::string)> func)
{
    
    HttpClient::getInstance()->setTimeoutForConnect(10);
    HttpClient::getInstance()->setTimeoutForRead(10);
    HttpRequest* request = new HttpRequest();
    request->setUrl(url.c_str());
    
    CCLOG("http data %s ",url.c_str());
    if (strcmp(requestType.c_str(), "get") == 0) {
        request->setRequestType(HttpRequest::Type::GET);
    } else if (strcmp(requestType.c_str(), "post") == 0) {
        request->setRequestType(HttpRequest::Type::POST);
    } else {
        assert(false);
    }

    std::string postData = ""; 
    for (auto iter = data.cbegin(); iter != data.cend(); ++iter)
    {
        postData += iter->first.c_str();
        postData += "=";
        postData += iter->second.asString().c_str();
        postData += "&";
    }
    request->setRequestData(postData.c_str(), strlen(postData.c_str()));

    request->setResponseCallback([=](HttpClient *sender, HttpResponse *response){
        if (response == nullptr || !response->isSucceed())
        {
            func(false, "");
            return;
        }
        
        std::vector<char> *buffer = response->getResponseData();
        
        std::string bufffff(buffer->begin(),buffer->end());
        func(true, bufffff);
        
        CCLOG("response:%s",bufffff.c_str());
    });
    HttpClient::getInstance()->sendImmediate(request);
    request->release();
    
}


