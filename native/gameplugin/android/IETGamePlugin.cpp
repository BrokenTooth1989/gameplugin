//
//  IETGamePlugin.mm
//  gameplugin
//
//  Created by geekgy on 15-3-17.
//
//

#include "IETGamePlugin.h"

using namespace std;
#include "cocos2d.h"
USING_NS_CC;
#include "jni.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#else

#endif
 
// #define CLASS_NAME_NATIVE_HELPER "com/fatalsignal/game/NativeHelper"

#ifdef __cplusplus
extern "C" {
#endif
   
#ifdef __cplusplus
}
#endif
// jobject mNativeHelper;
void IETGamePlugin::init()
{
	// JniMethodInfo jMthGetInstance;
 //    JniHelper::getStaticMethodInfo(jMthGetInstance, CLASS_NAME_NATIVE_HELPER, "getInstance", CCString::createWithFormat("()L%s;",CLASS_NAME_NATIVE_HELPER)->getCString());
 //    mNativeHelper =
 //    jMthGetInstance.env->NewGlobalRef(jMthGetInstance.env->CallStaticObjectMethod(jMthGetInstance.classID, jMthGetInstance.methodID));
}

void IETGamePlugin::crashReportLogs(std::string message)
{
}

void IETGamePlugin::crashReportException(std::string reason, cocos2d::ValueVector traceback)
{
}

//void IETGamePlugin::setGenVerifyUrlHandler(const std::function<std::string (cocos2d::ValueMap)> &func)
//{
//}

void IETGamePlugin::setRestoreHandler(const std::function<void (bool, std::string, std::string)> &func)
{
}

void IETGamePlugin::doIap(std::string iapId, std::string userId, const std::function<void (bool, std::string)> &func)
{

	
    func(true, "");
}

void IETGamePlugin::rate(int level)
{
}

bool IETGamePlugin::gcIsAvailable()
{
    return false;
}

cocos2d::ValueMap IETGamePlugin::gcGetPlayerInfo()
{
    return ValueMapNull;
}

void IETGamePlugin::gcGetPlayerFriends(const std::function<void (cocos2d::ValueVector)> &func)
{
}

void IETGamePlugin::gcGetPlayerAvatarWithId(std::string playerId, const std::function<void (std::string)> &func)
{
}

void IETGamePlugin::gcGetPlayerInfoWithIds(cocos2d::ValueVector playerIds, const std::function<void (cocos2d::ValueVector)> &func)
{
}

void IETGamePlugin::gcGetPlayerInfoWithId(std::string playerId, const std::function<void (cocos2d::ValueMap)> &func)
{
}

void IETGamePlugin::gcGetChallenges(const std::function<void (cocos2d::ValueVector)> &func)
{
}

int IETGamePlugin::gcGetScore(std::string leaderboard)
{
    return 10;
}

void IETGamePlugin::gcReportScore(int score, std::string leaderboard, bool h2l)
{
}

double IETGamePlugin::gcGetAchievement(std::string achievement)
{
    return 1;
}

void IETGamePlugin::gcReportAchievement(std::string achievement, double percent)
{
}

void IETGamePlugin::gcShowLeaderBoard()
{
}

void IETGamePlugin::gcShowArchievement()
{
}

void IETGamePlugin::gcShowChallenge()
{
}

void IETGamePlugin::gcReset()
{
}
void IETGamePlugin::setNotifyHandler(const std::function<void(cocos2d::ValueMap)>& func)
{}
void IETGamePlugin::setVerifyIapHandler(const std::function<void (cocos2d::ValueMap, std::function<void (int, std::string)>)> &func)
{}

std::string IETGamePlugin::uuidForDevice()
{

    return "";
}

void IETGamePlugin::setPromotionHandler(const std::function<void (cocos2d::ValueVector)> &func)
{
}




