//
//  IETFacebookHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#import <Foundation/Foundation.h>
#include "IETFacebookHelper.h"

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
    _loginFunc = func;
}

void IETFacebookHelper::setAppLinkFunc(const std::function<void (cocos2d::ValueMap)> &func)
{
    
}

bool IETFacebookHelper::isLogin()
{
    return _isLogin;
}

void IETFacebookHelper::login()
{
    log("login");
    _isLogin = true;
    _loginFunc("fid", "EAAFlKjLxCvoBAIo9ObttpOfJGiiiVPIFxg1ZBAwXhqiVAqC7ziljuNof9GHBP86eL4lG9h5JHAbvr9jmNgryRCjgTc7MWUjyqTHeQHhRHWirG6VmzQiCgcfvnTLrbyR4GLhKRnLc19ohfa195QU6ZALF38bHvB6KILsTVbKwZDZD");
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
    ValueMap map;
    map["name"] = "John Smith";
    map["id"] = "110000";
    func(map);
}

void IETFacebookHelper::getInvitableFriends(cocos2d::ValueVector inviteTokens, int picSize, std::function<void (cocos2d::ValueMap)> &func)
{
    log("getInvitableFriends");
    func(ValueMapNull);
}

void IETFacebookHelper::getFriends(int picSize, std::function<void (cocos2d::ValueMap)> &func)
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

void IETFacebookHelper::inviteFriend(std::string appLinkURL,std::string prviewImageURL, std::function<void(bool)>& func)
{
}
