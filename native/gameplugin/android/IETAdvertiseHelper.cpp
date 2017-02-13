//
//  IETAdvertiseHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAdvertiseHelper.h"

using namespace std;
using namespace cocos2d;

int IETAdvertiseHelper::showBannerAd(bool isPortrait, bool isBottom)
{
    log("showBannerAd");
    return 40;
}

void IETAdvertiseHelper::hideBannerAd()
{
    log("hideBannerAd");
}

bool IETAdvertiseHelper::isSpotAdReady()
{
    log("isSpotAdReady");
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
    return true;
}

bool IETAdvertiseHelper::showVedioAd(const std::function<void (bool)> &viewFunc, const std::function<void (bool)> &clickFunc)
{
    log("showVedioAd");
    return true;
}
