//
//  IETAdvertiseHelper.h
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#ifndef gameplugin_IETAdvertiseHelper_h
#define gameplugin_IETAdvertiseHelper_h

#include "cocos2d.h"
#include "IETGamePluginDefine.h"

class IETAdvertiseHelper {
private:
    void init(){};
public:
    SINGLETON(IETAdvertiseHelper);
    void setBannerAdName(std::string name);
    void setSpotAdNames(cocos2d::ValueVector names);
    void setVideoAdNames(cocos2d::ValueVector names);
    int showBannerAd(bool isPortrait, bool isBottom);
    void hideBannerAd();
    bool isSpotAdReady();
    bool showSpotAd(const std::function<void (bool)> &func);
    bool isVedioReady();
    bool showVedioAd(const std::function<void (bool)> &viewFunc, const std::function<void(bool)>& clickFunc);
};

#endif
