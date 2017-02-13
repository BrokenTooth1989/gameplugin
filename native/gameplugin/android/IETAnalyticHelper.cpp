//
//  IETAnalyticHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAnalyticHelper.h"

using namespace std;
using namespace cocos2d;

void initFileHandler()
{
    
}

void IETAnalyticHelper::setAccountInfo(cocos2d::ValueMap userInfo)
{
    
}

void IETAnalyticHelper::onEvent(std::string eventId)
{
    
}

void IETAnalyticHelper::onEvent(std::string eventId, std::string label)
{
    
}

void IETAnalyticHelper::onEvent(std::string eventId, cocos2d::ValueMap map)
{
    
}

void IETAnalyticHelper::setLevel(int level)
{
    
}

void IETAnalyticHelper::charge(std::string name, double cash, double coin, int type)
{
    
}

void IETAnalyticHelper::reward(double coin, int type)
{
    
}

void IETAnalyticHelper::purchase(std::string name, int amount, double coin)
{
    
}

void IETAnalyticHelper::use(std::string name, int amount, double coin)
{
    
}

void IETAnalyticHelper::missionStart(std::string missionId)
{
    log("missionStart");
    log("missionId=%s", missionId.c_str());
}

void IETAnalyticHelper::missionSuccess(std::string missionId)
{
    log("missionSuccess");
    log("missionId=%s", missionId.c_str());
}

void IETAnalyticHelper::missionFailed(std::string missionId, std::string reason)
{
    log("missionFailed");
    log("missionId=%s", missionId.c_str());
    log("reason=%s", reason.c_str());
}
