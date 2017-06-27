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
#endif

#define CALL_JAVA_PACKAGE "org/cocos2dx/lua/AppActivity"


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

    jboolean ret;
    //getMethodInfo判断java定义的类非静态函数是否存在，返回bool
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"isLoginFaceBook","()Z");
    if(re)
    {
        log("call no-static method");
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        ret = minfo.env->CallBooleanMethod(jobj,minfo.methodID);
        log("facebook islogin:%d",ret);
    }
    return ret;
}

void IETFacebookHelper::login()
{
    log("login");
    
    // _loginFunc("fid", "token");


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


    //getMethodInfo判断java定义的类非静态函数是否存在，返回bool
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"onLoginFaceBook","()V");
    if(re)
    {
        log("call no-static method");
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        minfo.env->CallVoidMethod(jobj,minfo.methodID);
    }

    _isLogin = true;
    _loginFunc(this->getUserID(), this->getAccessToken());
}

void IETFacebookHelper::logout()
{
    log("logout");
    _isLogin = false;


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
    //getMethodInfo判断java定义的类非静态函数是否存在，返回bool
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"FBLogOut","()V");
    if(re)
    {
        log("call no-static method");
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        minfo.env->CallVoidMethod(jobj,minfo.methodID);
    }

}

std::string IETFacebookHelper::getUserID()
{

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
    jstring jstr;
    const char* str;
    //getMethodInfo判断java定义的类非静态函数是否存在，返回bool
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"getFBUserId","()Ljava/lang/String;");
    if(re)
    {
        log("call no-static method");
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstr = (jstring)minfo.env->CallObjectMethod(jobj,minfo.methodID);
        str = minfo.env->GetStringUTFChars(jstr, NULL);    
        std::string ret(str);
        minfo.env->ReleaseStringUTFChars(jstr, str);//str 
        minfo.env->DeleteLocalRef(jstr);//释放jstr 
    }

    log("facebook userId:%s",str);
    return str;
}

std::string IETFacebookHelper::getAccessToken()
{

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
    jstring jstr;
    const char* str;
    //getMethodInfo判断java定义的类非静态函数是否存在，返回bool
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"getAccessToken","()Ljava/lang/String;");
    if(re)
    {
        log("call no-static method");
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstr = (jstring)minfo.env->CallObjectMethod(jobj,minfo.methodID);
        str = minfo.env->GetStringUTFChars(jstr, NULL);    
        std::string ret(str);
        minfo.env->ReleaseStringUTFChars(jstr, str);//str 
        minfo.env->DeleteLocalRef(jstr);//释放jstr 
    }

    log("facebook AccessToken:%s",str);
    return str;
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
