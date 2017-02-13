//
//  IETAnalyticHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAnalyticHelper.h"
#import <Foundation/Foundation.h>
#import "IOSAnalyticHelper.h"
#import "IETUtility.h"

using namespace std;
using namespace cocos2d;

void IETAnalyticHelper::setAccountInfo(cocos2d::ValueMap userInfo)
{
    NSDictionary* nsUserInfo = [IETUtility valueMap2NsDict:userInfo];
    [[IOSAnalyticHelper getInstance] setAccoutInfo:nsUserInfo];
}

void IETAnalyticHelper::onEvent(std::string eventId)
{
    NSString* nsEventId = [NSString stringWithUTF8String:eventId.c_str()];
    [[IOSAnalyticHelper getInstance] onEvent:nsEventId];
}

void IETAnalyticHelper::onEvent(std::string eventId, std::string label)
{
    NSString* nsEventId = [NSString stringWithUTF8String:eventId.c_str()];
    NSString* nsLabel = [NSString stringWithUTF8String:label.c_str()];
    [[IOSAnalyticHelper getInstance] onEvent:nsEventId Label:nsLabel];
}

void IETAnalyticHelper::onEvent(std::string eventId, cocos2d::ValueMap map)
{
    NSString* nsEventId = [NSString stringWithUTF8String:eventId.c_str()];
    NSDictionary* nsDict = [IETUtility valueMap2NsDict:map];
    [[IOSAnalyticHelper getInstance] onEvent:nsEventId eventData:nsDict];
}

void IETAnalyticHelper::setLevel(int level)
{
    [[IOSAnalyticHelper getInstance] setLevel:level];
}

void IETAnalyticHelper::charge(std::string name, double cash, double coin, int type)
{
    NSString *nsName = [NSString stringWithUTF8String:name.c_str()];
    [[IOSAnalyticHelper getInstance] charge:nsName :cash :coin :type];
}

void IETAnalyticHelper::reward(double coin, int type)
{
    [[IOSAnalyticHelper getInstance] reward:coin :type];
}

void IETAnalyticHelper::purchase(std::string name, int amount, double coin)
{
    NSString *nsName = [NSString stringWithUTF8String:name.c_str()];
    [[IOSAnalyticHelper getInstance] purchase:nsName :amount :coin];
}

void IETAnalyticHelper::use(std::string name, int amount, double coin)
{
    NSString *nsName = [NSString stringWithUTF8String:name.c_str()];
    [[IOSAnalyticHelper getInstance] use:nsName :amount :coin];
}

void IETAnalyticHelper::missionStart(std::string missionId)
{
    [[IOSAnalyticHelper getInstance] missionStart:NSStringFromString(missionId)];
}

void IETAnalyticHelper::missionSuccess(std::string missionId)
{
    [[IOSAnalyticHelper getInstance] missionSuccess:NSStringFromString(missionId)];
}

void IETAnalyticHelper::missionFailed(std::string missionId, std::string reason)
{
    [[IOSAnalyticHelper getInstance] missionFailed:NSStringFromString(missionId)
                                           because:NSStringFromString(reason)];
}






