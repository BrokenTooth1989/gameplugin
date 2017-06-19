//
//  IETFacebookHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETFacebookHelper.h"

#include "cocos2d.h"

#include "jni.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#else

#endif

using namespace std;
using namespace cocos2d;

std::function<void (std::string, std::string)> _loginFunc = nullptr;
bool _isLogin = false;

void IETFacebookHelper::setLoginFunc(const std::function<void (std::string, std::string)> &func)
{
    _loginFunc = func;
}

void IETFacebookHelper::setAppLinkFunc(const std::function<void (cocos2d::ValueMap)> &func)
{
    
}

void IETFacebookHelper::openFacebookPage(std::string installUrl, std::string url)
{
    log("installUrl=%s", installUrl.c_str());
    log("url=%s", url.c_str());
}

bool IETFacebookHelper::isLogin()
{
    return _isLogin;
}

void IETFacebookHelper::login()
{
    log("login");
    _isLogin = true;
    _loginFunc("fid", "token");



    //  //1. 获取activity静态对象
    // JniMethodInfo minfo;
    // bool isHave = JniHelper::getStaticMethodInfo(minfo,
    //                                              "com/omega/MyApp",
    //                                              "getJavaActivity",
    //                                              "()Ljava/lang/Object;");
    // jobject activityObj;
    // if (isHave)
    // {
    //     //调用静态函数getJavaActivity，获取java类对象。
    //     activityObj = minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
    // }

    // //2. 查找displayWebView接口，获取其函数信息，并用jobj调用
    // isHave = JniHelper::getMethodInfo(minfo,"com/omega/MyApp","displayWebView", "(IIII)V"); 

    // if (!isHave)
    // {
    //     CCLog("jni:displayWebView 函数不存在");
    // }
    // else
    // {
    //     //调用此函数
    //     jint jX = (int)tlX;
    //     jint jY = (int)tlY;
    //     jint jWidth = (int)webWidth;
    //     jint jHeight = (int)webHeight;
    //     //调用displayWebView函数，并传入参数
    //     minfo.env->CallVoidMethod(activityObj, minfo.methodID, jX, jY, jWidth, jHeight);
    // }

}

void IETFacebookHelper::logout()
{
    log("logout");
    _isLogin = false;
}

std::string IETFacebookHelper::getUserID()
{
    return "100007257579533";
}

std::string IETFacebookHelper::getAccessToken()
{
    return "token";
}

void IETFacebookHelper::getUserProfile(std::string fid, int picSize, std::function<void (cocos2d::ValueMap)> &func)
{
    log("getUserProfile");
    func(ValueMapNull);
}

void IETFacebookHelper::getInvitableFriends(cocos2d::ValueVector inviteTokens, int picSize, std::function<void(cocos2d::ValueMap)>& func)
{
    log("getInvitableFriends");
    func(ValueMapNull);
}

void IETFacebookHelper::getFriends(int picSize, std::function<void(cocos2d::ValueMap)>& func)
{
    log("getFriends");
    func(ValueMapNull);
}

void IETFacebookHelper::confirmRequest(cocos2d::ValueVector fidOrTokens, std::string title, std::string msg, std::function<void (cocos2d::ValueMap)> &func)
{
    log("confirmRequest");
    func(ValueMapNull);
}

void IETFacebookHelper::queryRequest(std::function<void (cocos2d::ValueMap)> &func)
{
    log("queryRequest");
    func(ValueMapNull);
}

void IETFacebookHelper::acceptRequest(std::string requestId, std::function<void (bool)> &func)
{
    log("acceptRequest");
    func(true);
}

void IETFacebookHelper::share(std::string title, std::string description, std::string caption, std::string imageUrl, std::string contentUrl, std::function<void (bool)> &func)
{
    log("fbShare");
    log("title = %s", title.c_str());
    log("description = %s", description.c_str());
    log("caption = %s", caption.c_str());
    log("imageUrl = %s", imageUrl.c_str());
    log("contentUrl = %s", contentUrl.c_str());
}

void IETFacebookHelper::setLevel(int level)
{
    log("setLevel");
}

void IETFacebookHelper::getLevel(std::string fid, std::function<void (int)> &func)
{
    log("getLevel");
    func(5);
}
