//
//  IETSystemUtil.m
//  blackjack
//
//  Created by geekgy on 8/24/16.
//
//

#include "IETSystemUtil.h"
#import "IETUtility.h"
#include <sys/sysctl.h>
#include "network/HttpClient.h"
#include <AFNetworking/AFNetworking.h>

using namespace cocos2d::network;

int IETSystemUtil::getDebugMode() {
    return DEBUG_LEVEL;
}
std::string IETSystemUtil::getPlatCfgValue(std::string key)
{
    return "value";
}
std::string IETSystemUtil::getAppBundleId()
{
    return "bundleId";
}
std::string IETSystemUtil::getAppName()
{
    return "appName";
}
std::string IETSystemUtil::getAppVersion()
{
    return "1.0";
}
int IETSystemUtil::getAppBuild()
{
    return 1;
}
std::string IETSystemUtil::getDeviceName()
{
    return "user's macbook";
}
std::string IETSystemUtil::getDeviceModel()
{
    return "macbook";
}
std::string IETSystemUtil::getDeviceType()
{
    return "macbook pro";
}
std::string IETSystemUtil::getSystemName()
{
    return "osx";
}
std::string IETSystemUtil::getSystemVersion()
{
    return "10.12.6";
}
std::string IETSystemUtil::getIDFV()
{
    return "IDFV";
}
std::string IETSystemUtil::getIDFA()
{
    return "IDFA";
}
std::string IETSystemUtil::getUUID()
{
    return "UUID";
}
std::string IETSystemUtil::getCountryCode()
{
    return "CN";
}
std::string IETSystemUtil::getLanguageCode()
{
    return "ZH";
}
long IETSystemUtil::getCpuTime()
{
    struct timeval boottime;
    int mib[2] = {CTL_KERN, KERN_BOOTTIME};
    size_t size = sizeof(boottime);
    time_t now;
    time_t uptime = -1;
    (void)time(&now);
    if (sysctl(mib, 2, &boottime, &size, NULL, 0) != -1 && boottime.tv_sec != 0)
    {
        uptime = now - boottime.tv_sec;
    }
    return uptime;
}
std::string IETSystemUtil::getNetworkState()
{
    return "ReachableViaWiFi";
}
void IETSystemUtil::showAlertDialog(std::string title, std::string message, std::string cancelBtnTitle, cocos2d::ValueVector otherBtnTitles, const std::function<void (int)> &func)
{}
void IETSystemUtil::showProgressDialog(std::string message, int percent)
{}
void IETSystemUtil::hideProgressDialog()
{}
void IETSystemUtil::showLoading(std::string message)
{}
void IETSystemUtil::hideLoading()
{}
void IETSystemUtil::showMessage(std::string message)
{}
void IETSystemUtil::vibrate()
{}
void IETSystemUtil::saveImage(std::string imgPath, std::string album, const std::function<void (bool, std::string)> &func)
{}
void IETSystemUtil::sendEmail(std::string subject, cocos2d::ValueVector, std::string emailBody, const std::function<void (bool, std::string)> &func)
{}
void IETSystemUtil::setNotificationState(bool enable)
{
    NSLog(@"setNotificationState: %@", enable?@"true":@"false");
}
void IETSystemUtil::postNotification(cocos2d::ValueMap map)
{}
void IETSystemUtil::setBadgeNum(int num)
{}
void IETSystemUtil::share(cocos2d::ValueVector items)
{}
void IETSystemUtil::keychainSet(std::string key, std::string value)
{}
std::string IETSystemUtil::keychainGet(std::string key)
{
    return "";
}
bool IETSystemUtil::isJailbroken()
{
    return false;
}
void IETSystemUtil::copyToPasteboard(std::string str)
{}
void IETSystemUtil::requestUrl(std::string requestType, std::string url, cocos2d::ValueMap data, const std::function<void (bool, std::string)> func)
{
    void(^success)(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) = ^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        NSError *parseError = nil;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:responseObject options:NSJSONWritingPrettyPrinted error:&parseError];
        NSString *respStr = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        func(true, [respStr UTF8String]);
    };
    void(^failure)(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) = ^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        func(false, [[NSString stringWithFormat:@"%@", error] UTF8String]);
    };
    
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.requestSerializer = [AFJSONRequestSerializer serializer];
    [manager.requestSerializer setValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [manager.requestSerializer setTimeoutInterval:10];
    
    if ([NSStringFromString(requestType) isEqualToString:@"get"]) {
        [manager GET:NSStringFromString(url) parameters:nil progress:nil success:success failure:failure];
    } else {
        [manager POST:NSStringFromString(url) parameters:[IETUtility valueMap2NsDict:data] progress:nil success:success failure:failure];
    }
}
