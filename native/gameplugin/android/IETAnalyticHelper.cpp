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

#define ANALYTIC_HELPER_CLASS_NAME "com.joycastle.gameplugin.AnalyticHelper"

void IETAnalyticHelper::setAccountInfo(cocos2d::ValueMap userInfo)
{
    ValueVector reqVec;
    reqVec.push_back(Value(userInfo));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME, "setAccoutInfo", reqVec);
}

void IETAnalyticHelper::onEvent(std::string eventId)
{
    ValueVector reqVec;
    reqVec.push_back(Value(eventId));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME,"onEvent",reqVec);
}

void IETAnalyticHelper::onEvent(std::string eventId, std::string label)
{
    ValueVector reqVec;
    reqVec.push_back(Value(eventId));
    reqVec.push_back(Value(label));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME,"onEvent",reqVec);
}

void IETAnalyticHelper::onEvent(std::string eventId, cocos2d::ValueMap map)
{
    ValueVector reqVec;
    reqVec.push_back(Value(eventId));
    reqVec.push_back(Value(map));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME, "onEvent", reqVec);
}

void IETAnalyticHelper::setLevel(int level)
{
    ValueVector reqVec;
    reqVec.push_back(Value(level));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME, "setLevel", reqVec);
}

void IETAnalyticHelper::charge(std::string name, double cash, double coin, int type)
{
    ValueVector reqVec;
    reqVec.push_back(Value(name));
    reqVec.push_back(Value(cash));
    reqVec.push_back(Value(coin));
    reqVec.push_back(Value(type));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME, "charge", reqVec);
}

void IETAnalyticHelper::reward(double coin, int type)
{
    ValueVector reqVec;
    reqVec.push_back(Value(coin));
    reqVec.push_back(Value(type));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME,"reward",reqVec);
}

void IETAnalyticHelper::purchase(std::string name, int amount, double coin)
{
    ValueVector reqVec;
    reqVec.push_back(Value(name));
    reqVec.push_back(Value(amount));
    reqVec.push_back(Value(coin));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME,"purchase",reqVec);
}

void IETAnalyticHelper::use(std::string name, int amount, double coin)
{
    ValueVector reqVec;
    reqVec.push_back(Value(name));
    reqVec.push_back(Value(amount));
    reqVec.push_back(Value(coin));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME,"use",reqVec);
}

void IETAnalyticHelper::missionStart(std::string missionId)
{
    ValueVector reqVec;
    reqVec.push_back(Value(missionId));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME,"onMissionBegin",reqVec);
}

void IETAnalyticHelper::missionSuccess(std::string missionId)
{
    ValueVector reqVec;
    reqVec.push_back(Value(missionId));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME,"onMissionCompleted",reqVec);
}

void IETAnalyticHelper::missionFailed(std::string missionId, std::string reason)
{
    ValueVector reqVec;
    reqVec.push_back(Value(missionId));
    reqVec.push_back(Value(reason));
    IETAndroidBridge::getInstance()->callJavaMethod(ANALYTIC_HELPER_CLASS_NAME,"onMissionFailed",reqVec);
}
