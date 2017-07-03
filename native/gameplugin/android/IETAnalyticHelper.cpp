//
//  IETAnalyticHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAnalyticHelper.h"

#include "jni.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#endif

#define CALL_JAVA_PACKAGE "org/cocos2dx/lua/AppActivity"

#include "IETTool.h"

using namespace std;
using namespace cocos2d;

void initFileHandler()
{
    
}

void IETAnalyticHelper::setAccountInfo(cocos2d::ValueMap userInfo)
{
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"setAccountInfo","(Ljava/lang/String;)V");
    log("call method setAccountInfo");

    const char* userInfoStr = IETTool::valueMapToJson(userInfo);

    log("userInfoStr: %s",userInfoStr);

    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring userInfoJ = minfo.env->NewStringUTF(userInfoStr);
        minfo.env->CallVoidMethod(jobj,minfo.methodID,userInfoJ);
        minfo.env->DeleteLocalRef(userInfoJ);
    }

  
}

void IETAnalyticHelper::onEvent(std::string eventId)
{
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"onEvent","(Ljava/lang/String;)V");
    log("call method onEvent");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同

        jstring eId = minfo.env->NewStringUTF(eventId.c_str());
        minfo.env->CallVoidMethod(jobj,minfo.methodID,eId);
        minfo.env->DeleteLocalRef(eId);
    }
}

void IETAnalyticHelper::onEvent(std::string eventId, std::string label)
{


    log("onEnent2 eventId : %s - label : %s", eventId.c_str(),label.c_str());

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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"onEvent","(Ljava/lang/String;Ljava/lang/String;)V");
    log("call method onEvent2");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring eId = minfo.env->NewStringUTF(eventId.c_str());
        jstring labelJ = minfo.env->NewStringUTF(label.c_str());

        minfo.env->CallVoidMethod(jobj,minfo.methodID,eId,labelJ);
        minfo.env->DeleteLocalRef(eId);
        minfo.env->DeleteLocalRef(labelJ);
    }
}

void IETAnalyticHelper::onEvent(std::string eventId, cocos2d::ValueMap map)
{



    const char* userInfoStr = IETTool::valueMapToJson(map);

    log("onEvent3: %s",userInfoStr);

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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"onEvent3","(Ljava/lang/String;Ljava/lang/String;)V");
    log("call method onEvent3");
    // log("map %s",map);
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring eId = minfo.env->NewStringUTF(eventId.c_str());
        jstring eMap = minfo.env->NewStringUTF(userInfoStr);
        minfo.env->CallVoidMethod(jobj,minfo.methodID,eId,eMap);
        minfo.env->DeleteLocalRef(eId);
        minfo.env->DeleteLocalRef(eMap);
    }
}

void IETAnalyticHelper::setLevel(int level)
{
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"setLevel","(I)V");
    log("call method setLevel");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        
        minfo.env->CallVoidMethod(jobj,minfo.methodID,level);
    
    }
}

void IETAnalyticHelper::charge(std::string name, double cash, double coin, int type)
{
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"charge","(Ljava/lang/String;DDI)V");
    log("call method charge");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring nameJ = minfo.env->NewStringUTF(name.c_str());
    
        minfo.env->CallVoidMethod(jobj,minfo.methodID,nameJ,cash,coin,type);
        minfo.env->DeleteLocalRef(nameJ);
     
    }
}

void IETAnalyticHelper::reward(double coin, int type)
{
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"reward","(DI)V");
    log("call method reward");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
  
        minfo.env->CallVoidMethod(jobj,minfo.methodID,coin,type);
    
    }
}

void IETAnalyticHelper::purchase(std::string name, int amount, double coin)
{
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"purchase","(Ljava/lang/String;ID)V");
    log("call method reward");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring nameJ = minfo.env->NewStringUTF(name.c_str());
     
        minfo.env->CallVoidMethod(jobj,minfo.methodID,nameJ,amount,coin);
        minfo.env->DeleteLocalRef(nameJ);
 
    }
}

void IETAnalyticHelper::use(std::string name, int amount, double coin)
{
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"use","(Ljava/lang/String;ID)V");
    log("call method reward");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring nameJ = minfo.env->NewStringUTF(name.c_str());
   
        minfo.env->CallVoidMethod(jobj,minfo.methodID,nameJ,amount,coin);
        minfo.env->DeleteLocalRef(nameJ);
       
    }
}

void IETAnalyticHelper::missionStart(std::string missionId)
{
    log("missionStart");
    log("missionId=%s", missionId.c_str());

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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"missionStart","(Ljava/lang/String;)V");
    log("call method reward");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring missionIdJ = minfo.env->NewStringUTF(missionId.c_str());
        minfo.env->CallVoidMethod(jobj,minfo.methodID,missionIdJ);
        minfo.env->DeleteLocalRef(missionIdJ);
      
    }
}

void IETAnalyticHelper::missionSuccess(std::string missionId)
{
    log("missionSuccess");
    log("missionId=%s", missionId.c_str());
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"missionSuccess","(Ljava/lang/String;)V");
    log("call method reward");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring missionIdJ = minfo.env->NewStringUTF(missionId.c_str());
        minfo.env->CallVoidMethod(jobj,minfo.methodID,missionIdJ);
        minfo.env->DeleteLocalRef(missionIdJ);
    }
}

void IETAnalyticHelper::missionFailed(std::string missionId, std::string reason)
{
    log("missionFailed");
    log("missionId=%s", missionId.c_str());
    log("reason=%s", reason.c_str());
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
    bool re = JniHelper::getMethodInfo(minfo,CALL_JAVA_PACKAGE,"missionFailed","(Ljava/lang/String;Ljava/lang/String;)V");
    log("call method reward");
    if(re)
    {
        //非静态函数调用的时候，需要的是对象，所以与静态函数调用的第一个参数不同
        jstring missionIdJ = minfo.env->NewStringUTF(missionId.c_str());
        jstring reasonJ = minfo.env->NewStringUTF(reason.c_str());
        minfo.env->CallVoidMethod(jobj,minfo.methodID,missionIdJ,reasonJ);
        minfo.env->DeleteLocalRef(missionIdJ);
        minfo.env->DeleteLocalRef(reasonJ);
    }
}
