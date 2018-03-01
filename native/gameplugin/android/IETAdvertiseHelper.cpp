//
//  IETAdvertiseHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAdvertiseHelper.h"
#include "IETAndroidBridge.h"

using namespace std;
using namespace cocos2d;

#define ADVERTISE_HELPER_CLASS_NAME "com.joycastle.gameplugin.AdvertiseHelper"

int IETAdvertiseHelper::showBannerAd(bool isPortrait, bool isBottom)
{
    ValueVector reqVec;
    reqVec.push_back(Value(isPortrait));
    reqVec.push_back(Value(isBottom));
    ValueVector resVec = IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME,"showBannerAd",reqVec);
    int height = resVec[1].asInt();
    return height;
}

void IETAdvertiseHelper::hideBannerAd()
{
    IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME,"hideBannerAd",ValueVectorNull);
}

bool IETAdvertiseHelper::isSpotAdReady()
{
    log("isSpotAdReady");
    IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME,"hideBannerAd",ValueVectorNull);
    return true;
}

bool IETAdvertiseHelper::showSpotAd(const std::function<void (bool)> &func)
{
    log("showSpotAd");
    func(true);
    return true;
}

bool IETAdvertiseHelper::isVedioReady()
{
    std::string isReady = IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME,"isVideoAdReady",ValueVectorNull);
    return isReady=="true" ? true:false;
}

bool IETAdvertiseHelper::showVedioAd(const std::function<void (bool)> &viewFunc, const std::function<void (bool)> &clickFunc)
{
//    IETAndroidBridge::getInstance()->callJavaMethodAsync(ADVERTISE_HELPER_CLASS_NAME,"showVideoAd",ValueVectorNull,[=](std::string _resData){
//        log("IETSystemUtil::setNotificationState:  %s", _resData.c_str());
// 
//        rapidjson::Document readdoc;
//        readdoc.Parse<0>(_resData.c_str());     
//        if(!readdoc.HasParseError() )  
//        {  
//            if (readdoc.HasMember("reward"))
//            {
//                rapidjson::Value& idValue=readdoc["reward"];
//                viewFunc(idValue.GetBool());
//            } 
//            else if (readdoc.HasMember("click"))
//            {
//                rapidjson::Value& idValue=readdoc["click"];
//                clickFunc(idValue.GetBool());
//            }
//        } 
//    });
  
    return true;
}
void IETAdvertiseHelper::setVideoAdNames(cocos2d::ValueVector names)
{}
void IETAdvertiseHelper::setBannerAdName(std::string name)
{}
void IETAdvertiseHelper::setSpotAdNames(cocos2d::ValueVector names)
{}
