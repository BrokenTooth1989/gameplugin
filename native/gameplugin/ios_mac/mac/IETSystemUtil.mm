//
//  IETSystemUtil.m
//  blackjack
//
//  Created by geekgy on 8/24/16.
//
//

#include "IETSystemUtil.h"
#import "IETUtility.h"
#include <sys/sysctl.h>
#include "network/HttpClient.h"

using namespace cocos2d::network;

long IETSystemUtil::getCpuTime()
{
    struct timeval boottime;
    int mib[2] = {CTL_KERN, KERN_BOOTTIME};
    size_t size = sizeof(boottime);
    time_t now;
    time_t uptime = -1;
    (void)time(&now);
    if (sysctl(mib, 2, &boottime, &size, NULL, 0) != -1 && boottime.tv_sec != 0)
    {
        uptime = now - boottime.tv_sec;
    }
    return uptime;
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
std::string IETSystemUtil::getAppVersionName() {
    return "1.0.0";
}
int IETSystemUtil::getAppBuildNum() {
    return 1;
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
{
    CCLOG("%s", message.c_str());
}
void IETSystemUtil::vibrate()
{}
void IETSystemUtil::saveImage(std::string imgPath, std::string album, const std::function<void (bool, std::string)> &func)
{}
void IETSystemUtil::sendEmail(std::string subject, cocos2d::ValueVector, std::string emailBody, const std::function<void (bool, std::string)> &func)
{}
void IETSystemUtil::setNotificationState(bool enable)
{
    NSLog(@"setNotificationState: %@", enable?@"true":@"false");
}
void IETSystemUtil::postNotification(cocos2d::ValueMap map)
{}
void IETSystemUtil::share(cocos2d::ValueVector items)
{}
void IETSystemUtil::keychainSet(std::string key, std::string value)
{}
std::string IETSystemUtil::keychainGet(std::string key)
{
    return "";
}
void IETSystemUtil::copyToPasteboard(std::string str)
{}

void IETSystemUtil::requestUrl(std::string requestType, std::string url, std::string data, const std::function<void (bool, std::string)> &func)
{
    HttpClient::getInstance()->setTimeoutForConnect(10);
    HttpClient::getInstance()->setTimeoutForRead(10);
    HttpRequest* request = new HttpRequest();
    request->setUrl(url.c_str());
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
    });
    HttpClient::getInstance()->sendImmediate(request);
    request->release();
}
