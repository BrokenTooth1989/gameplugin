//
//  IETFacebookHelper.h
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#ifndef gameplugin_IETFacebookHelper_h
#define gameplugin_IETFacebookHelper_h

#include "cocos2d.h"
#include "IETGamePluginDefine.h"

class IETFacebookHelper {
private:
    void init(){};
public:
    SINGLETON(IETFacebookHelper);
    void openFacebookPage(std::string installUrl, std::string url);
    void setLoginFunc(const std::function<void(std::string, std::string)>& func);
    void setAppLinkFunc(const std::function<void(cocos2d::ValueMap)>& func);
    bool isLogin();
    void login();
    void logout();
    std::string getUserID();
    std::string getAccessToken();
    void getUserProfile(std::string fid, int picSize, std::function<void(cocos2d::ValueMap)>& func);
    void getInvitableFriends(cocos2d::ValueVector inviteTokens, int picSize, std::function<void(cocos2d::ValueMap)>& func);
    void getFriends(int picSize, std::function<void(cocos2d::ValueMap)>& func);
    void confirmRequest(cocos2d::ValueVector fidOrTokens, std::string title, std::string msg, std::function<void(cocos2d::ValueMap)>& func);
    void queryRequest(std::function<void(cocos2d::ValueMap)>& func);
    void acceptRequest(std::string requestId, std::function<void(bool)>& func);
    void share(std::string title, std::string i, std::string caption, std::string imageUrl, std::string contentUrl, std::function<void(bool)>& func);
    void setLevel(int level);
    void getLevel(std::string fid, std::function<void(int)>& func);
};

#endif
