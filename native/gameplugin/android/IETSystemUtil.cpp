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


#include "jni.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#endif

#define CALL_JAVA_PACKAGE "org/cocos2dx/lua/AppActivity"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace network;

int IETSystemUtil::getDebugMode() {
    return 3;
}

long IETSystemUtil::getCpuTime()
{
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    
    // log("CurrentTime MillSecond %f", (double)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000);

    return (long)tv.tv_sec * 1000 + (double)tv.tv_usec / 1000;


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
    jlong ctime;
    const char* str;
    //getMethodInfo判断java定义的类非静态函数是否存在，返回bool
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"getCpuTime","()J;");
    if(re)
    {
        log("call no-static method");
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        ctime = (jlong)minfo.env->CallObjectMethod(jobj,minfo.methodID);
      
    }
    return ctime;

}

std::string IETSystemUtil::getConfigValue(std::string key)
{
    return "";
}
std::string IETSystemUtil::getBundleId()
{
    return "";
}
std::string IETSystemUtil::getAppName()
{
    return "";
}
int IETSystemUtil::getAppVersion()
{
    return 1;
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


void IETSystemUtil::requestUrl(std::string requestType, std::string url, std::string data, const std::function<void (bool, std::string)> func)
{
    
    HttpClient::getInstance()->setTimeoutForConnect(10);
    HttpClient::getInstance()->setTimeoutForRead(10);
    HttpRequest* request = new HttpRequest();
    request->setUrl(url.c_str());
    
    CCLOG("http data %s %s",url.c_str(),data.c_str());
    if (strcmp(requestType.c_str(), "get") == 0) {
        request->setRequestType(HttpRequest::Type::GET);
    } else if (strcmp(requestType.c_str(), "post") == 0) {
        request->setRequestType(HttpRequest::Type::POST);
    } else {
        assert(false);
    }
    if (data.size() > 0) {

        request->setRequestData(data.c_str(), strlen(data.c_str()));
    }
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


std::string IETSystemUtil::getAppVersionName()
{
    
    return "";
}


int IETSystemUtil::getAppBuildNum()
{
    return 0;
}

