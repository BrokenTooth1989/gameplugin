//
//  IETAmazonAWSHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/15.
//
//

#include "cocos2d.h"
#include "IETAmazonAWSHelper.h"

using namespace std;
using namespace cocos2d;

void IETAmazonAWSHelper::sync(std::string data, std::function<void (bool, std::string)> &func)
{
    log("sync");
    log("%s", data.c_str());
    Director::getInstance()->getScheduler()->schedule([=](float){
        Director::getInstance()->getScheduler()->unschedule("haha", Director::getInstance());
        func(true, data);
    }, Director::getInstance(), 2, false, "haha");
}

std::string IETAmazonAWSHelper::getUserId()
{
    return "us-east-1:d2a31cec-f0e6-4377-8ad9-5fbcf55083d2";
}

void IETAmazonAWSHelper::connectFb(std::string token)
{
    log("connectFb");
    log("%s", token.c_str());
}

//void IETAmazonAWSHelper::setRemoteNotifyFunc(std::function<void (cocos2d::ValueMap)> &func)
//{
//    log("setRemoteNotifyFunc");
//}

