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
//    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"setLoginListener",ValueVectorNull,[=](cocos2d::ValueVector _resData){
//        log("IETFacebookHelper::setLoginFunc: async  %s", _resData.c_str());
//        rapidjson::Document readdoc;
//        readdoc.Parse<0>(_resData.c_str());
//        if(!readdoc.HasParseError() && readdoc.HasMember("userId") && readdoc.HasMember("accessToken"))
//        {
//            rapidjson::Value& idValue=readdoc["userId"];
//            rapidjson::Value& tokenValue=readdoc["accessToken"];
//            func(idValue.GetString(),tokenValue.GetString());
//        }
//    });

}

void IETFacebookHelper::setAppLinkFunc(const std::function<void (cocos2d::ValueMap)> &func)
{
    
}

bool IETFacebookHelper::isLogin()
{

//    rapidjson::Value arr(rapidjson::kArrayType);
//    rapidjson::Value msg(rapidjson::kObjectType);
//    rapidjson::StringBuffer  buffer;
//    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
//    rapidjson::Document document ;
//    document.SetObject();
//    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
//    arr.PushBack(msg,allocate);
//    document.AddMember("json", arr, allocate);
//    document.Accept(writer);
//    auto reqData = buffer.GetString();
//    std::string islogin = IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"isLogin",reqData);
//    log("facebook islogin json :%s",islogin.c_str());
//
//    rapidjson::Document readdoc;
//    readdoc.Parse<0>(islogin.c_str());
//    if(readdoc.HasParseError())
//    {
//        CCLOG("GetParseError%s\n", readdoc.GetParseError());
//    }
//    const rapidjson::Value& jsonValue=readdoc["islogin"];
//
//    return jsonValue.GetBool();
}

void IETFacebookHelper::login()
{
//    rapidjson::Value arr(rapidjson::kArrayType);
//    rapidjson::Value msg(rapidjson::kObjectType);
//    rapidjson::StringBuffer  buffer;
//    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
//    rapidjson::Document document ;
//    document.SetObject();
//    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
//    arr.PushBack(msg,allocate);
//    document.AddMember("json", arr, allocate);
//    document.Accept(writer);
//    auto reqData = buffer.GetString();
//    // std::string islogin = IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"isLogin",reqData);
//    IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"login",reqData);
//    // _isLogin = true;
//    // _loginFunc(this->getUserID(), this->getAccessToken());
}

void IETFacebookHelper::logout()
{
//    rapidjson::Value arr(rapidjson::kArrayType);
//    rapidjson::StringBuffer  buffer;
//    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
//    rapidjson::Document document ;
//    document.SetObject();
//    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
//    document.AddMember("json", arr, allocate);
//    document.Accept(writer);
//    auto reqData = buffer.GetString();
//    IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"logout",reqData);
}

std::string IETFacebookHelper::getUserID()
{
//    rapidjson::Value arr(rapidjson::kArrayType);
//    rapidjson::Value msg(rapidjson::kObjectType);
//    rapidjson::StringBuffer  buffer;
//    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
//    rapidjson::Document document ;
//    document.SetObject();
//    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
//    arr.PushBack(msg,allocate);
//    document.AddMember("json", arr, allocate);
//    document.Accept(writer);
//    auto reqData = buffer.GetString();
//
//    std::string uid = IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"getUserId",reqData);
//    log("facebook userId:%s",uid.c_str());
//
//    std::string _uid = "";
//    rapidjson::Document readdoc;
//    readdoc.Parse<0>(uid.c_str());
//    if(!readdoc.HasParseError() && readdoc.HasMember("uid"))
//    {
//        const rapidjson::Value& jsonValue=readdoc["uid"];
//        _uid = jsonValue.GetString();
//    }
//
//    return _uid;
}

std::string IETFacebookHelper::getAccessToken()
{
//    rapidjson::Value arr(rapidjson::kArrayType);
//    rapidjson::Value msg(rapidjson::kObjectType);
//    rapidjson::StringBuffer  buffer;
//    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
//    rapidjson::Document document ;
//    document.SetObject();
//    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
//    arr.PushBack(msg,allocate);
//    document.AddMember("json", arr, allocate);
//    document.Accept(writer);
//    auto reqData = buffer.GetString();
//    std::string token = IETAndroidBridge::getInstance()->callJavaMethod(FACEBOOK_HELPER_CLASS_NAME,"getAccessToken",reqData);
//    log("facebook AccessToken:%s",token.c_str());
//
//    std::string _token = "";
//    rapidjson::Document readdoc;
//    readdoc.Parse<0>(token.c_str());
//    if(!readdoc.HasParseError() && readdoc.HasMember("token"))
//    {
//        rapidjson::Value& jsonValue=readdoc["token"];
//        _token = jsonValue.GetString();
//    }
//    return _token;
}

void IETFacebookHelper::getUserProfile(std::string fid, int picSize, std::function<void (cocos2d::ValueMap)> &func)
{
//    log("IETFacebookHelper::getUserProfile:—");
//    rapidjson::Value arr(rapidjson::kArrayType);
//    rapidjson::Value msg(rapidjson::kObjectType);
//    rapidjson::StringBuffer  buffer;
//    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
//    rapidjson::Document document ;
//    document.SetObject();
//    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
//    // arr.PushBack(msg,allocate);
//    document.AddMember("json", arr, allocate);
//    document.Accept(writer);
//    auto reqData = buffer.GetString();
//    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"getUserProfile",reqData,[=](std::string _resData){
//        log("IETFacebookHelper::getUserProfile: async  %s", _resData.c_str());
//        cocos2d::ValueMap respData;
//        rapidjson::Document readdoc;
//        readdoc.Parse<0>(_resData.c_str());
//        if(!readdoc.HasParseError() && readdoc.HasMember("facebookId") && readdoc.HasMember("name"))
//        {
//            rapidjson::Value& idValue=readdoc["facebookId"];
//            respData["id"] = idValue.GetString();
//            rapidjson::Value& nameValue=readdoc["name"];
//            respData["name"] = nameValue.GetString();
//        }
//        log(" @@@ getUserProfile");
//        func(respData);
//    });
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
//    log("confirmRequest");
//    rapidjson::Value arr(rapidjson::kArrayType);
//    rapidjson::Value obj(rapidjson::kObjectType);
//    rapidjson::StringBuffer  buffer;
//    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
//    rapidjson::Document document ;
//    document.SetObject();
//    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
//    arr.PushBack(obj,allocate);
//    arr.PushBack(title.c_str(),allocate);
//    arr.PushBack(msg.c_str(),allocate);
//    document.AddMember("json", arr, allocate);
//    document.Accept(writer);
//    auto reqData = buffer.GetString();
//    IETAndroidBridge::getInstance()->callJavaMethodAsync(FACEBOOK_HELPER_CLASS_NAME,"confirmRequest",reqData,[=](std::string _resData){
//        log("IETFacebookHelper::confirmRequest: async  %s", _resData.c_str());
//        cocos2d::ValueMap respData;
//        rapidjson::Document readdoc;
//        readdoc.Parse<0>(_resData.c_str());     
//        if(!readdoc.HasParseError() && readdoc.HasMember("json"))  
//        {  
//            rapidjson::Value& jsonValue=readdoc["json"];
//            char key[20] = "tofid";
//            for (int i = 0; i < jsonValue.Size(); ++i)
//            {
//                sprintf(key,"%d",i );
//                rapidjson::Value &v = jsonValue[i];
//                respData[key] = v.GetString();
//            }
//        } 
//
//        func(respData);
//    });

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
