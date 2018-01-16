//
//  IETGamePlugin.mm
//  gameplugin
//
//  Created by geekgy on 15-3-17.
//
//

#include "IETGamePlugin.h"
#import "IOSGamePlugin.h"
#import "IETUtility.h"

using namespace std;
using namespace cocos2d;
void IETGamePlugin::init()
{}
void IETGamePlugin::crashReportLogs(std::string message)
{
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        [[IOSGamePlugin getInstance] crashReportLog:NSStringFromString(message)];
    });
}

void IETGamePlugin::crashReportException(std::string reason, cocos2d::ValueVector traceback)
{
    [[IOSGamePlugin getInstance] crashReportExceptionWithReason:NSStringFromString(reason)
                                                   andTraceback:[IETUtility valueVector2NsArr:traceback]];
    Director::getInstance()->end();
    dispatch_async(dispatch_get_main_queue(), ^{
        exit(0);
    });
}

void IETGamePlugin::setNotifyHandler(const std::function<void (cocos2d::ValueMap)> &func)
{
    void(^block)(NSDictionary*) = [func](NSDictionary* dict) -> void {
        func([IETUtility nsDict2ValueMap:dict]);
    };
    [[IOSGamePlugin getInstance] setNotificationHandler:block];
}

void IETGamePlugin::setVerifyIapHandler(const std::function<void (cocos2d::ValueMap, std::function<void (int, std::string)>)> &func)
{
    void(^block)(NSDictionary*, void(^)(int, NSString*)) = [func](NSDictionary* dict, void(^cb)(int state, NSString* msg)) -> void {
        __block id observerId;
        observerId = [[NSNotificationCenter defaultCenter] addObserverForName:@"IapVerifyCallback"
                                                                          object:nil
                                                                           queue:[NSOperationQueue mainQueue]
                                                                      usingBlock:^(NSNotification * _Nonnull note) {
                                                                          [[NSNotificationCenter defaultCenter] removeObserver:observerId];
                                                                          NSDictionary *userInfo = note.userInfo;
                                                                          int state = [[userInfo objectForKey:@"state"] intValue];
                                                                          NSString *message = [userInfo objectForKey:@"message"];
                                                                          cb(state, message);
                                                                      }];
        func([IETUtility nsDict2ValueMap:dict], [cb](int state, std::string message) {
            NSDictionary *userInfo = @{@"state":@(state), @"message":NSStringFromString(message)};
            [[NSNotificationCenter defaultCenter] postNotificationName:@"IapVerifyCallback"
                                                                object:nil
                                                              userInfo:userInfo];
        });
    };
    [[IOSGamePlugin getInstance] setVerifyIapHandler:block];
}

void IETGamePlugin::setRestoreHandler(const std::function<void (bool, std::string, std::string)> &func)
{
    void (^block)(BOOL, NSString*, NSString*) = [func](BOOL result, NSString *message, NSString *iapId) -> void {
        func(result, [message UTF8String], [iapId UTF8String]);
    };
    [[IOSGamePlugin getInstance] setRestoreHandler:block];
}

void IETGamePlugin::doIap(std::string iapId, std::string userId, const std::function<void (bool, std::string)> &func)
{
    void (^block)(BOOL, NSString*) = [func](BOOL result, NSString *message) -> void {
        func(result, [message UTF8String]);
    };
    [[IOSGamePlugin getInstance] doIap:NSStringFromString(iapId) userId:NSStringFromString(userId) handler:block];
}

bool IETGamePlugin::gcIsAvailable()
{
    return [[IOSGamePlugin getInstance] gcIsAvailable];
}

cocos2d::ValueMap IETGamePlugin::gcGetPlayerInfo()
{
    return [IETUtility nsDict2ValueMap:[[IOSGamePlugin getInstance] gcGetPlayerInfo]];
}

void IETGamePlugin::gcGetPlayerFriends(const std::function<void (cocos2d::ValueVector)> &func)
{
    void (^block)(NSArray*) = [func](NSArray *friends) -> void {
        func([IETUtility nsArr2ValueVector:friends]);
    };
    [[IOSGamePlugin getInstance] gcGetPlayerFriends:block];
}

void IETGamePlugin::gcGetPlayerAvatarWithId(std::string playerId, const std::function<void (std::string)> &func)
{
    void (^block)(NSString*) = [func](NSString* filePath) -> void {
        func([filePath UTF8String]);
    };
    [[IOSGamePlugin getInstance] gcGetPlayerAvatarWithId:NSStringFromString(playerId) handler:block];
}

void IETGamePlugin::gcGetPlayerInfoWithIds(cocos2d::ValueVector playerIds, const std::function<void (cocos2d::ValueVector)> &func)
{
    void (^block)(NSArray*) = [func](NSArray *playerInfos) -> void {
        func([IETUtility nsArr2ValueVector:playerInfos]);
    };
    [[IOSGamePlugin getInstance] gcGetPlayerInfoWithIds:[IETUtility valueVector2NsArr:playerIds] handler:block];
}

void IETGamePlugin::gcGetPlayerInfoWithId(std::string playerId, const std::function<void (cocos2d::ValueMap)> &func)
{
    void (^block)(NSDictionary*) = [func](NSDictionary *playerInfo) -> void {
        func([IETUtility nsDict2ValueMap:playerInfo]);
    };
    [[IOSGamePlugin getInstance] gcGetPlayerInfoWithId:NSStringFromString(playerId) handler:block];
}

void IETGamePlugin::gcGetChallenges(const std::function<void (cocos2d::ValueVector)> &func)
{
    void (^block)(NSArray*) = [func](NSArray *challenges) -> void {
        func([IETUtility nsArr2ValueVector:challenges]);
    };
    [[IOSGamePlugin getInstance] gcGetChallengesWithhandler:block];
}

int IETGamePlugin::gcGetScore(std::string leaderboard)
{
    NSString* nsLeaderboard = [NSString stringWithUTF8String:leaderboard.c_str()];
    return [[IOSGamePlugin getInstance] gcGetScore:nsLeaderboard];
}

void IETGamePlugin::gcReportScore(int score, std::string leaderboard, bool h2l)
{
    NSString* nsLeaderboard = [NSString stringWithUTF8String:leaderboard.c_str()];
    [[IOSGamePlugin getInstance] gcReportScore:score leaderboard:nsLeaderboard sortH2L:h2l];
}

double IETGamePlugin::gcGetAchievement(std::string achievement)
{
    NSString* nsAchievement = [NSString stringWithUTF8String:achievement.c_str()];
    return [[IOSGamePlugin getInstance] gcGetAchievement:nsAchievement];
}

void IETGamePlugin::gcReportAchievement(std::string achievement, double percent)
{
    NSString* nsAchievement = [NSString stringWithUTF8String:achievement.c_str()];
    [[IOSGamePlugin getInstance] gcReportAchievement:nsAchievement percentComplete:percent];
}

void IETGamePlugin::gcShowLeaderBoard()
{
    [[IOSGamePlugin getInstance] gcShowLeaderBoard];
}

void IETGamePlugin::gcShowArchievement()
{
    [[IOSGamePlugin getInstance] gcShowArchievement];
}

void IETGamePlugin::gcShowChallenge()
{
    [[IOSGamePlugin getInstance] gcShowChallenge];
}

void IETGamePlugin::gcReset()
{
    [[IOSGamePlugin getInstance] gcReset];
}

