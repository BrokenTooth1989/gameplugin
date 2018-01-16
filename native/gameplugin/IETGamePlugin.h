//
//  IETGamePlugin.h
//  gameplugin
//
//  Created by geekgy on 15-3-16.
//
//

#ifndef gameplugin_IETGamePlugin_h
#define gameplugin_IETGamePlugin_h

#include "cocos2d.h"
#include "IETGamePluginDefine.h"

class IETGamePlugin {
protected:
    virtual void init();
public:
    SINGLETON(IETGamePlugin);
    
    void crashReportLogs(std::string message);
    void crashReportException(std::string reason, cocos2d::ValueVector traceback);
    void setNotifyHandler(const std::function<void(cocos2d::ValueMap)>& func);
    void setVerifyIapHandler(const std::function<void (cocos2d::ValueMap, std::function<void (int, std::string)>)> &func);
    void setRestoreHandler(const std::function<void(bool, std::string, std::string)>& func);
    void doIap(std::string iapId, std::string userId, const std::function<void(bool, std::string)>& func);
    bool gcIsAvailable();
    cocos2d::ValueMap gcGetPlayerInfo();
    void gcGetPlayerFriends(const std::function<void (cocos2d::ValueVector)> &func);
    void gcGetPlayerAvatarWithId(std::string playerId, const std::function<void (std::string)> &func);
    void gcGetPlayerInfoWithIds(cocos2d::ValueVector playerIds, const std::function<void (cocos2d::ValueVector)> &func);
    void gcGetPlayerInfoWithId(std::string playerId, const std::function<void (cocos2d::ValueMap)> &func);
    void gcGetChallenges(const std::function<void (cocos2d::ValueVector)> &func);
    int gcGetScore(std::string leaderboard);
    void gcReportScore(int score, std::string leaderboard, bool h2l);
    double gcGetAchievement(std::string achievement);
    void gcReportAchievement(std::string achievement, double percent);
    void gcShowLeaderBoard();
    void gcShowArchievement();
    void gcShowChallenge();
    void gcReset();
};

#endif /* defined(GamePlugin_GamePlugin_h) */
