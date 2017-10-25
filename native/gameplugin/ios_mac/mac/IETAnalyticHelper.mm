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

using namespace std;
using namespace cocos2d;

NSFileHandle *myHandle = nil;
NSMutableArray *testArr = nil;

void initFileHandler()
{
    if (myHandle == nil) {
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        NSString *documentsDirectory = [paths objectAtIndex:0];
        NSString* fileName = [documentsDirectory stringByAppendingString:@"/event.txt"];
        myHandle = [NSFileHandle fileHandleForWritingAtPath:fileName];
        [myHandle retain];
        [myHandle seekToEndOfFile];
    }
}

void writeTestData(NSString* str, BOOL flush)
{
    if (testArr == nil) {
        testArr = [NSMutableArray array];
        [testArr retain];
    }
    [testArr addObject:str];
    if ([testArr count] > 0 || flush) {
        NSString* str = [NSString stringWithFormat:@"%@\n", [testArr componentsJoinedByString:@"\n"]];
        [myHandle writeData:[str dataUsingEncoding:NSUTF8StringEncoding]];
        [testArr removeAllObjects];
    }
}

void IETAnalyticHelper::setAccountInfo(cocos2d::ValueMap userInfo)
{
    
}

void IETAnalyticHelper::onEvent(std::string eventId)
{
    if (!strcmp(eventId.c_str(), "finish")) {
        writeTestData([NSString stringWithUTF8String:"\n"], true);
    } else {
        initFileHandler();
        NSString* eventMsg = [NSString stringWithFormat:@"onEvent: %s", eventId.c_str()];
        writeTestData(eventMsg, false);
    }
}

void IETAnalyticHelper::onEvent(std::string eventId, std::string label)
{
    initFileHandler();
    NSString* eventMsg = [NSString stringWithFormat:@"onEvent: %s, label: %s", eventId.c_str(), label.c_str()];
    writeTestData(eventMsg, false);
}

void IETAnalyticHelper::onEvent(std::string eventId, cocos2d::ValueMap map)
{
    NSString* nsEventId = [NSString stringWithUTF8String:eventId.c_str()];
    NSDictionary* nsDict = [IETUtility valueMap2NsDict:map];
    initFileHandler();
    NSString* eventMsg = [NSString stringWithFormat:@"onEvent: %@, data: %@", nsEventId, nsDict];
    writeTestData(eventMsg, false);
}

void IETAnalyticHelper::setLevel(int level)
{
    initFileHandler();
    NSString* eventMsg = [NSString stringWithFormat:@"setLevel: %d", level];
    writeTestData(eventMsg, false);
}

void IETAnalyticHelper::charge(std::string name, double cash, double coin, int type)
{
    initFileHandler();
    NSString* eventMsg = [NSString stringWithFormat:@"charge: %s, cash: %f, coin: %f, type: %d", name.c_str(), cash, coin, type];
    writeTestData(eventMsg, false);
}

void IETAnalyticHelper::reward(double coin, int type)
{
    initFileHandler();
    NSString* eventMsg = [NSString stringWithFormat:@"reward: %f, reason: %d", coin, type];
    writeTestData(eventMsg, false);
}

void IETAnalyticHelper::purchase(std::string name, int amount, double coin)
{
    initFileHandler();
    NSString* eventMsg = [NSString stringWithFormat:@"purchase: %s, amount: %d, coin: %f", name.c_str(), amount, coin];
    writeTestData(eventMsg, false);
}

void IETAnalyticHelper::use(std::string name, int amount, double coin)
{
    initFileHandler();
    NSString* eventMsg = [NSString stringWithFormat:@"use: %s, amount: %d, coin: %f", name.c_str(), amount, coin];
    writeTestData(eventMsg, false);
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
