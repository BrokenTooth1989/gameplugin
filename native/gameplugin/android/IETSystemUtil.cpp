//
//  IETSystemUtil.cpp
//  blackjack
//
//  Created by geekgy on 8/24/16.
//
//

#include "IETSystemUtil.h"
#include "IETAndroidBridge.h"
#include "network/HttpClient.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace network;

#define SYSTEM_UTIL_CLASS_NAME  "com.joycastle.gamepluginbase.SystemUtil"

int IETSystemUtil::getDebugMode() {
    return 3;
}

std::string IETSystemUtil::getPlatCfgValue(std::string key)
{
    ValueVector reqVec;
    reqVec.push_back(Value(key));
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME, "getPlatCfgValue", reqVec);
    return resVec[0].asString();
}

std::string IETSystemUtil::getAppBundleId()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getBundleId",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getAppName()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getAppName",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getAppVersion()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getAppVersion",ValueVectorNull);
    return resVec[0].asString();
}

int IETSystemUtil::getAppBuild()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getAppBuild",ValueVectorNull);
    return resVec[0].asInt();
}

std::string IETSystemUtil::getDeviceName()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getDeviceName",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getDeviceModel()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getDeviceModel",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getDeviceType()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getDeviceType",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getSystemName()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getSystemName",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getSystemVersion()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getSystemVersion",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getIDFV()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getIDFV",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getIDFA()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getIDFA",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getUUID()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getUUID",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getCountryCode()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getCountryCode",ValueVectorNull);
    return resVec[0].asString();
}

std::string IETSystemUtil::getLanguageCode()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getLanguageCode",ValueVectorNull);
    return resVec[0].asString();
}

long IETSystemUtil::getCpuTime()
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    
    // log("CurrentTime MillSecond %f", (double)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000);

    return (long)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000;

}

std::string IETSystemUtil::getNetworkState()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"getNetworkState",ValueVectorNull);
    return resVec[0].asString();
}

void IETSystemUtil::showAlertDialog(std::string title, std::string message, std::string cancelBtnTitle, cocos2d::ValueVector otherBtnTitles, const std::function<void (int)> &func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(title));
    reqVec.push_back(Value(message));
    reqVec.push_back(Value(cancelBtnTitle));
    reqVec.push_back(Value(otherBtnTitles));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"showAlertDialog",reqVec,[=](ValueVector resVec){
        func(resVec[0].asInt());
    });
}

void IETSystemUtil::showProgressDialog(std::string message, int percent)
{
    ValueVector reqVec;
    reqVec.push_back(Value(message));
    reqVec.push_back(Value(percent));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME, "showProgressDialog", reqVec);
}

void IETSystemUtil::hideProgressDialog()
{
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME, "hideProgressDialog", ValueVectorNull);
}

void IETSystemUtil::showLoading(std::string message)
{
    ValueVector reqVec;
    reqVec.push_back(Value(message));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME, "showLoading", reqVec);
}

void IETSystemUtil::hideLoading()
{
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME, "hideLoading", ValueVectorNull);
}

void IETSystemUtil::showMessage(std::string message)
{
    ValueVector reqVec;
    reqVec.push_back(Value(message));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME, "showMessage", reqVec);
}

void IETSystemUtil::vibrate()
{
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"vibrate",ValueVectorNull);
}

void IETSystemUtil::saveImage(std::string imgPath, std::string album, const std::function<void (bool, std::string)> &func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(imgPath));
    reqVec.push_back(Value(album));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME, "saveImage", reqVec,[=](ValueVector resVec){
        func(resVec[0].asBool(), resVec[1].asString());
    });
}

void IETSystemUtil::sendEmail(std::string subject, cocos2d::ValueVector toRecipients, std::string emailBody, const std::function<void (bool, std::string)> &func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(subject));
    reqVec.push_back(Value(toRecipients));
    reqVec.push_back(Value(emailBody));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"sendEmail",reqVec,[=](ValueVector resVec){
        func(resVec[0].asBool(), resVec[1].asString());
    });
}

void IETSystemUtil::setNotificationState(bool enable)
{
    ValueVector reqVec;
    reqVec.push_back(Value(enable));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"setNotificationState",reqVec);
}

void IETSystemUtil::postNotification(cocos2d::ValueMap map)
{
    ValueVector reqVec;
    reqVec.push_back(Value(map));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"postNotification",reqVec);
}

void IETSystemUtil::setBadgeNum(int num)
{
    ValueVector reqVec;
    reqVec.push_back(Value(num));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"setBadgeNum",reqVec);
}

void IETSystemUtil::share(cocos2d::ValueVector items)
{
    ValueVector reqVec;
    reqVec.push_back(Value(items));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME, "share", reqVec);
}

void IETSystemUtil::keychainSet(std::string key, std::string value)
{
    ValueVector reqVec;
    reqVec.push_back(Value(key));
    reqVec.push_back(Value(value));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"keychainSet",reqVec);
}

std::string IETSystemUtil::keychainGet(std::string key)
{
    ValueVector reqVec;
    reqVec.push_back(Value(key));
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"keychainGet",reqVec);
    return resVec[0].asString();
}

bool IETSystemUtil::isJailbroken()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"isJailbroken",ValueVectorNull);
    return resVec[0].asBool();
}

void IETSystemUtil::copyToPasteboard(std::string str)
{
    ValueVector reqVec;
    reqVec.push_back(Value(str));
    IETAndroidBridge::getInstance()->callJavaMethod(SYSTEM_UTIL_CLASS_NAME,"copyToClipboard",reqVec);
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
