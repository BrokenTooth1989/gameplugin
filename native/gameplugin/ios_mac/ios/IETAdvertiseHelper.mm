//
//  IETAdvertiseHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETAdvertiseHelper.h"
#import <Foundation/Foundation.h>
#import "IOSAdvertiseHelper.h"
#import "IETUtility.h"

using namespace std;
using namespace cocos2d;

void IETAdvertiseHelper::setBannerAdName(std::string name)
{
    [[IOSAdvertiseHelper getInstance] setBannerAdName:[NSString stringWithUTF8String:name.c_str()]];
}

void IETAdvertiseHelper::setSpotAdNames(cocos2d::ValueVector names)
{
    [[IOSAdvertiseHelper getInstance] setSpotAdNames:[IETUtility valueVector2NsArr:names]];
}

void IETAdvertiseHelper::setVideoAdNames(cocos2d::ValueVector names)
{
    [[IOSAdvertiseHelper getInstance] setVideoAdNames:[IETUtility valueVector2NsArr:names]];
}

int IETAdvertiseHelper::showBannerAd(bool isPortrait, bool isBottom)
{
    return [[IOSAdvertiseHelper getInstance] showBannerAd:isPortrait :isBottom];
}

void IETAdvertiseHelper::hideBannerAd()
{
    [[IOSAdvertiseHelper getInstance] hideBannerAd];
}

bool IETAdvertiseHelper::isSpotAdReady()
{
    return [[IOSAdvertiseHelper getInstance] isSpotAdReady];
}

bool IETAdvertiseHelper::showSpotAd(const std::function<void (bool)> &func)
{
    void(^block)(BOOL) = [func](BOOL result) -> void {
        func(result);
    };
    return [[IOSAdvertiseHelper getInstance] showSpotAd:block];
}

bool IETAdvertiseHelper::isVedioReady()
{
    return [[IOSAdvertiseHelper getInstance] isVedioAdReady];
}

bool IETAdvertiseHelper::showVedioAd(const std::function<void (bool)> &viewFunc, const std::function<void (bool)> &clickFunc)
{
    void(^viewBlock)(BOOL) = [viewFunc](BOOL result) -> void {
        viewFunc(result);
    };
    void(^clickBlock)(BOOL) = [clickFunc](BOOL result) -> void {
        clickFunc(result);
    };
    return [[IOSAdvertiseHelper getInstance] showVedioAd:viewBlock :clickBlock];
}
