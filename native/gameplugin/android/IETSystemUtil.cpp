//
//  IETSystemUtil.cpp
//  blackjack
//
//  Created by geekgy on 8/24/16.
//
//

#include "IETSystemUtil.h"

long IETSystemUtil::getCpuTime()
{
    return 0;
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
    
    
}


std::string IETSystemUtil::getAppVersionName()
{
    
    return "";
}


int IETSystemUtil::getAppBuildNum()
{
    return 0;
}

