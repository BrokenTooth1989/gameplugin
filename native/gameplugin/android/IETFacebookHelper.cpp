//
//  IETFacebookHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETFacebookHelper.h"

#include "cocos2d.h"
#include "IETAndroidBridge.h"

#define FACEBOOK_HELPER_CLASS_NAME "com.joycastle.my_facebook.FacebookHelper"

using namespace std;
using namespace cocos2d;

std::function<void (std::string, std::string)> _loginFunc = nullptr;
bool _isLogin = false;

void IETFacebookHelper::openFacebookPage(std::string installUrl, std::string url)
{
    log("installUrl=%s", installUrl.c_str());
    log("url=%s", url.c_str());
}

void IETFacebookHelper::setLoginFunc(const std::function<void (std::string, std::string)> &func)
{
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"setLoginFunc",ValueVectorNull,[=](cocos2d::ValueVector resVec){
        func(resVec[0].asString(),resVec[1].asString());
    });
}

void IETFacebookHelper::setAppLinkFunc(const std::function<void (cocos2d::ValueMap)> &func)
{
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"setAppLinkFunc",ValueVectorNull,[=](cocos2d::ValueVector resVec){
        func(resVec[0].asValueMap());
    });
}

bool IETFacebookHelper::isLogin()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"isLogin",ValueVectorNull);
    return resVec[0].asBool();
}

void IETFacebookHelper::login()
{
    IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"login",ValueVectorNull);
}

void IETFacebookHelper::logout()
{
    IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"logout",ValueVectorNull);
}

std::string IETFacebookHelper::getUserID()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"getUserID",ValueVectorNull);
    if(resVec.size()>0){
        return resVec[0].asString();
    }else{
        return "";
    }
}

std::string IETFacebookHelper::getAccessToken()
{
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"getAccessToken",ValueVectorNull);
    if(resVec.size()>0){
        return resVec[0].asString();
    }else{
        return "";
    }
}

void IETFacebookHelper::getUserProfile(std::string fid, int picSize, std::function<void (cocos2d::ValueMap)> &func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(fid));
    reqVec.push_back(Value(picSize));
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"getUserProfile",reqVec,[=](ValueVector resVec){
        func(resVec[0].asValueMap());
    });
}

void IETFacebookHelper::getInvitableFriends(cocos2d::ValueVector inviteTokens, int picSize, std::function<void(cocos2d::ValueMap)>& func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(inviteTokens));
    reqVec.push_back(Value(picSize));
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"getInvitableFriends",reqVec,[=](ValueVector resVec){
        func(resVec[0].asValueMap());
    });
}

void IETFacebookHelper::getFriends(int picSize, std::function<void(cocos2d::ValueMap)>& func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(picSize));
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"getFriends",reqVec,[=](ValueVector resVec){
        func(resVec[0].asValueMap());
    });
}

void IETFacebookHelper::confirmRequest(cocos2d::ValueVector fidOrTokens, std::string title, std::string msg, std::function<void (cocos2d::ValueMap)> &func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(fidOrTokens));
    reqVec.push_back(Value(title));
    reqVec.push_back(Value(msg));
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"confirmRequest",reqVec,[=](ValueVector resVec){
        func(resVec[0].asValueMap());
    });
}

void IETFacebookHelper::queryRequest(std::function<void (cocos2d::ValueMap)> &func)
{
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"queryRequest",ValueVectorNull,[=](ValueVector resVec){
        func(resVec[0].asValueMap());
    });
}

void IETFacebookHelper::acceptRequest(std::string requestId, std::function<void (bool)> &func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(requestId));
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"acceptRequest",reqVec,[=](ValueVector resVec){
        func(resVec[0].asBool());
    });
}

void IETFacebookHelper::share(std::string title, std::string description, std::string caption, std::string imageUrl, std::string contentUrl, std::function<void (bool)> &func)
{
    log("fbShare");
    log("title = %s", title.c_str());
    log("description = %s", description.c_str());
    log("caption = %s", caption.c_str());
    log("imageUrl = %s", imageUrl.c_str());
    log("contentUrl = %s", contentUrl.c_str());
    ValueVector reqVec;
    reqVec.push_back(Value(title));
    reqVec.push_back(Value(description));
    reqVec.push_back(Value(caption));
    reqVec.push_back(Value(imageUrl));
    reqVec.push_back(Value(contentUrl));
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"share",reqVec,[=](ValueVector resVec){
        func(resVec[0].asBool());
    });
}

void IETFacebookHelper::setLevel(int level)
{
    ValueVector reqVec;
    reqVec.push_back(Value(level));
    IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"setLevel",reqVec);
}

void IETFacebookHelper::getLevel(std::string fid, std::function<void (int)> &func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(fid));
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"getLevel",reqVec,[=](ValueVector resVec){
        func(resVec[0].asInt());
    });
}

void IETFacebookHelper::inviteFriend(std::string appLinkURL,std::string prviewImageURL, std::function<void(bool)>& func)
{
    ValueVector reqVec;
    reqVec.push_back(Value(appLinkURL));
    reqVec.push_back(Value(prviewImageURL));
    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"inviteFriend",reqVec,[=](ValueVector resVec){
        func(resVec[0].asBool());
    });
}
