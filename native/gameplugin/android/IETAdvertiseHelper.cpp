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

void IETAdvertiseHelper::setBannerAdName(std::string name)
{
    assert(false);
}

void IETAdvertiseHelper::setSpotAdNames(cocos2d::ValueVector names)
{
    assert(false);
}

void IETAdvertiseHelper::setVideoAdNames(cocos2d::ValueVector names)
{
    assert(false);
}

int IETAdvertiseHelper::showBannerAd(bool isPortrait, bool isBottom)
{
    ValueVector reqVec;
    reqVec.push_back(Value(isPortrait));
    reqVec.push_back(Value(isBottom));
    ValueVector retVec = IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME,"showBannerAd",reqVec);
    int height = retVec[0].asInt();
    return height;
}

void IETAdvertiseHelper::hideBannerAd()
{
    IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME,"hideBannerAd",ValueVectorNull);
}

bool IETAdvertiseHelper::isSpotAdReady()
{
    ValueVector retVec = IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME,"isInterstitialAdReady",ValueVectorNull);
    return retVec[0].asBool();
}

bool IETAdvertiseHelper::showSpotAd(const std::function<void (bool)> &func)
{
    ValueVector retVec = IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME, "showInterstitialAd", ValueVectorNull, [=](cocos2d::ValueVector resVec) {
        func(resVec[0].asBool());
    });
    return retVec[0].asBool();
}

bool IETAdvertiseHelper::isVedioReady()
{
    ValueVector retVec = IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME,"isVideoAdReady",ValueVectorNull);
    return retVec[0].asBool();
}

bool IETAdvertiseHelper::showVedioAd(const std::function<void (bool)> &viewFunc, const std::function<void (bool)> &clickFunc)
{
    ValueVector retVec = IETAndroidBridge::getInstance()->callJavaMethod(ADVERTISE_HELPER_CLASS_NAME, "showVideoAd", ValueVectorNull, [=](ValueVector resVec) {
        bool viewed = resVec[0].asBool();
        bool clicked = resVec[1].asBool();
        viewFunc(viewed);
        clickFunc(clicked);
    });
    return retVec[0].asBool();
}

