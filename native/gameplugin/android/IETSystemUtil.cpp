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
    // std::string timeStr = IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getCpuTime","{}");
    // log("IETSystemUtil::getDebugMode:  %s",timeStr.c_str());
    return 3;
}

long IETSystemUtil::getCpuTime()
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    
    // log("CurrentTime MillSecond %f", (double)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000);

    return (long)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000;

}

// std::string IETSystemUtil::getConfigValue(std::string key)
// {
//     return "";
// }
// std::string IETSystemUtil::getBundleId()
// {
//     return "";
// }

bool IETSystemUtil::isJailbroken()
{
    return false;
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
    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"getBundleId",reqData);
    return "";
}

std::string IETSystemUtil::getAppName()
{
    return "";
}
std::string IETSystemUtil::getAppVersion()
{
    return "";
}
std::string IETSystemUtil::getCountryCode()
{
    return "";
}
std::string IETSystemUtil::getLanguageCode()
{
    return "";
}
std::string IETSystemUtil::getDeviceName()
{
    return "";
}
std::string IETSystemUtil::getSystemVersion()
{
    return "";
}
std::string IETSystemUtil::getNetworkState()
{
    return "";
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
void IETSystemUtil::vibrate()
{}
void IETSystemUtil::saveImage(std::string imgPath, std::string album, const std::function<void (bool, std::string)> &func)
{}
void IETSystemUtil::sendEmail(std::string subject, cocos2d::ValueVector, std::string emailBody, const std::function<void (bool, std::string)> &func)
{}
void IETSystemUtil::setNotificationState(bool enable)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::Value msg(rapidjson::kObjectType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    msg.AddMember("title","hello world",allocate);
    arr.PushBack(msg,allocate);
    document.AddMember("json", arr, allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();
                                                                                    
    IETAndroidBridge::getInstance()->callJavaMethodAsync(JAVA_CLASS_NAME,"showAlertDialog",reqData,[=](std::string resData){
        log("IETSystemUtil::setNotificationState:  %s", resData.c_str());
    });
}
void IETSystemUtil::postNotification(cocos2d::ValueMap map)
{}
void IETSystemUtil::share(cocos2d::ValueVector items)
{}
void IETSystemUtil::keychainSet(std::string key, std::string value)
{
}
std::string IETSystemUtil::keychainGet(std::string key)
{
    return "";
}
void IETSystemUtil::copyToPasteboard(std::string str)
{}

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

std::string IETSystemUtil::getPlatCfgValue(std::string key)
{
    return "";
}

int IETSystemUtil::getAppBuild()
{
    return 1;
}
std::string IETSystemUtil::getDeviceModel()
{
    return "";
}
std::string IETSystemUtil::getDeviceType()
{
    return "";
}
std::string IETSystemUtil::getSystemName()
{
    return "";
}
std::string IETSystemUtil::getIDFV()
{
    return "";
}
std::string IETSystemUtil::getIDFA()
{
    return "";
}
std::string IETSystemUtil::getUUID()
{
    return "";
}
void IETSystemUtil::setBadgeNum(int num)
{

}


