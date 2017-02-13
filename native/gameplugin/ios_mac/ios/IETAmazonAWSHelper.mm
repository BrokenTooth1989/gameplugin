//
//  IETAmazonAWSHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/15.
//
//

#include "IETAmazonAWSHelper.h"
#import <Foundation/Foundation.h>
#import "IETUtility.h"

using namespace std;
using namespace cocos2d;

void IETAmazonAWSHelper::sync(std::string data, std::function<void (bool, std::string)> &func)
{
    NSString* nsData = [NSString stringWithUTF8String:data.c_str()];
    void (^block)(BOOL, NSString*) = [func](BOOL result, NSString* nsData) -> void{
        nsData = nsData==nil?@"":nsData;
        string data = [nsData UTF8String];
        Director::getInstance()->getScheduler()->performFunctionInCocosThread([func, result, data]{
            func(result, data);
        });
    };
    dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_async(queue, ^{
        [[NSClassFromString(@"AmazonAWSHelper") getInstance] sync:nsData :block];
    });
}

std::string IETAmazonAWSHelper::getUserId()
{
    NSString* nsUserId = [[NSClassFromString(@"AmazonAWSHelper") getInstance] getUserId];
    nsUserId = nsUserId==nil?@"":nsUserId;
    return [nsUserId UTF8String];
}

void IETAmazonAWSHelper::connectFb(std::string token)
{
    NSString* nsToken = [NSString stringWithUTF8String:token.c_str()];
    [[NSClassFromString(@"AmazonAWSHelper") getInstance] connectFb:nsToken];
}

