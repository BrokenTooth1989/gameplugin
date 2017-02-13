//
//  IETAmazonAWSHelper.h
//  gameplugin
//
//  Created by geekgy on 15/6/15.
//
//

#ifndef gameplugin_IETAmazonAWSHelper_h
#define gameplugin_IETAmazonAWSHelper_h

#include "cocos2d.h"
#include "IETGamePluginDefine.h"

class IETAmazonAWSHelper {
private:
    void init(){};
public:
    SINGLETON(IETAmazonAWSHelper);
    void sync(std::string data, std::function<void(bool, std::string data)>& func);
    std::string getUserId();
    void connectFb(std::string token);
};

#endif
