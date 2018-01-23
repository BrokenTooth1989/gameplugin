//
//  IETAnalyticHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAnalyticHelper.h"
#include "IETAndroidBridge.h"

using namespace std;
using namespace cocos2d;

#include "json/document.h"
#include "json/writer.h"  
#include "json/stringbuffer.h"  
using namespace  rapidjson; 


#define JAVA_CLASS_NAME "com.joycastle.gameplugin.AnalyticHelper"

void initFileHandler()
{
    
}

void IETAnalyticHelper::setAccountInfo(cocos2d::ValueMap userInfo)
{   

    // rapidjson::Value msg(rapidjson::kObjectType);
    // rapidjson::Value arr(rapidjson::kArrayType);
    // rapidjson::StringBuffer  buffer;
    // rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    // rapidjson::Document document ;
    // document.SetObject();
    // rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    // for (auto iter = userInfo.cbegin(); iter != userInfo.cend(); ++iter)
    // {
    //     msg.AddMember(iter->first.c_str(),iter->second.asString().c_str(),allocate);
    // }
    // arr.PushBack(msg,allocate);
    // document.AddMember("json",arr,allocate);
    // document.Accept(writer);
    // auto reqData = buffer.GetString();

    // IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"setAccoutInfo",reqData);
}

void IETAnalyticHelper::onEvent(std::string eventId)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(eventId.c_str(),allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"onEvent",reqData);
}

void IETAnalyticHelper::onEvent(std::string eventId, std::string label)
{

    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(eventId.c_str(),allocate);
    arr.PushBack(label.c_str(),allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"onEvent",reqData);
}

void IETAnalyticHelper::onEvent(std::string eventId, cocos2d::ValueMap map)
{
 
	rapidjson::Value msg(rapidjson::kObjectType);
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    for (auto iter = map.cbegin(); iter != map.cend(); ++iter)
    {
        msg.AddMember(iter->first.c_str(),iter->second.asString().c_str(),allocate);
    }
    arr.PushBack(eventId.c_str(),allocate);
    arr.PushBack(msg,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"onEvent",reqData);
}

void IETAnalyticHelper::setLevel(int level)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(level,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"setLevel",reqData);
}

void IETAnalyticHelper::charge(std::string name, double cash, double coin, int type)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(name.c_str(),allocate);
    arr.PushBack(cash,allocate);
    arr.PushBack(coin,allocate);
    arr.PushBack(type,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"charge",reqData);
}

void IETAnalyticHelper::reward(double coin, int type)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(2.1,allocate);
    arr.PushBack(type,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"reward",reqData);
}

void IETAnalyticHelper::purchase(std::string name, int amount, double coin)
{
  
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(name.c_str(),allocate);
    arr.PushBack(amount,allocate);
    arr.PushBack(coin,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"purchase",reqData);
}

void IETAnalyticHelper::use(std::string name, int amount, double coin)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(name.c_str(),allocate);
    arr.PushBack(amount,allocate);
    arr.PushBack(coin,allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"use",reqData);
}

void IETAnalyticHelper::missionStart(std::string missionId)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(missionId.c_str(),allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"missionStart",reqData);
}

void IETAnalyticHelper::missionSuccess(std::string missionId)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(missionId.c_str(),allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"missionSuccess",reqData);
}

void IETAnalyticHelper::missionFailed(std::string missionId, std::string reason)
{
    rapidjson::Value arr(rapidjson::kArrayType);
    rapidjson::StringBuffer  buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    rapidjson::Document document ;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    arr.PushBack(missionId.c_str(),allocate);
    arr.PushBack(reason.c_str(),allocate);
    document.AddMember("json",arr,allocate);
    document.Accept(writer);
    auto reqData = buffer.GetString();

    IETAndroidBridge::getInstance()->callJavaMethod(JAVA_CLASS_NAME,"missionFailed",reqData);
}
