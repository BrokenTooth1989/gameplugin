//
//  IETAnalyticHelper.h
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#ifndef gameplugin_IETAnalyticHelper_h
#define gameplugin_IETAnalyticHelper_h

#include "cocos2d.h"
#include "IETGamePluginDefine.h"

class IETAnalyticHelper {
private:
    void init(){};
public:
    SINGLETON(IETAnalyticHelper);
    void setAccountInfo(cocos2d::ValueMap userInfo);
    void onEvent(std::string eventId);
    void onEvent(std::string eventId, std::string label);
    void onEvent(std::string eventId, cocos2d::ValueMap map);
    void setLevel(int level);
    void charge(std::string name, double cash, double coin, int type);
    void reward(double coin, int type);
    void purchase(std::string name, int amount, double coin);
    void use(std::string name, int amount, double coin);
    void missionStart(std::string missionId);
    void missionSuccess(std::string missionId);
    void missionFailed(std::string missionId, std::string reason);
};

#endif
