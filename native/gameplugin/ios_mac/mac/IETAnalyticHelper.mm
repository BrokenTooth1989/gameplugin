//
//  IETAnalyticHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAnalyticHelper.h"
#import <Foundation/Foundation.h>
#import "IETUtility.h"
#include "IETSystemUtil.h"

using namespace std;
using namespace cocos2d;

NSFileHandle *myHandle = nil;
NSMutableArray *testArr = nil;

void IETAnalyticHelper::setAccountInfo(cocos2d::ValueMap userInfo)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(userInfo));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::onEvent(std::string eventId)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(eventId));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::onEvent(std::string eventId, std::string label)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(eventId));
    valueVec.push_back(Value(label));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::onEvent(std::string eventId, cocos2d::ValueMap map)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(eventId));
    valueVec.push_back(Value(map));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::setLevel(int level)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(level));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::charge(std::string name, double cash, double coin, int type)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(name));
    valueVec.push_back(Value(cash));
    valueVec.push_back(Value(coin));
    valueVec.push_back(Value(type));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::reward(double coin, int type)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(coin));
    valueVec.push_back(Value(type));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::purchase(std::string name, int amount, double coin)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(name));
    valueVec.push_back(Value(amount));
    valueVec.push_back(Value(coin));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::use(std::string name, int amount, double coin)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(name));
    valueVec.push_back(Value(amount));
    valueVec.push_back(Value(coin));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::missionStart(std::string missionId)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(missionId));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::missionSuccess(std::string missionId)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(missionId));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}

void IETAnalyticHelper::missionFailed(std::string missionId, std::string reason)
{
    ValueVector valueVec;
    valueVec.push_back(Value(__FUNCTION__));
    valueVec.push_back(Value(missionId));
    valueVec.push_back(Value(reason));
    cocos2d::ValueMap valueMap;
    valueMap["Analytic"] = valueVec;
    IETSystemUtil::getInstance()->requestUrl("post", "http://127.0.0.1:3000/log", valueMap, [](bool, std::string){});
}
