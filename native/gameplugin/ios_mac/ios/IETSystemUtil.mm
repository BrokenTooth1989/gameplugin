//
//  IETSystemUtil.m
//  blackjack
//
//  Created by geekgy on 8/24/16.
//
//

#include "IETSystemUtil.h"
#import "IOSSystemUtil.h"
#import "IETUtility.h"
#include <sys/sysctl.h>
#import "AFNetworking.h"

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
std::string IETSystemUtil::getConfigValue(std::string key)
{
    return [[[IOSSystemUtil getInstance] getConfigValueWithKey:NSStringFromString(key)] UTF8String];
}
std::string IETSystemUtil::getBundleId()
{
    return [[[IOSSystemUtil getInstance] getBundleId] UTF8String];
}
std::string IETSystemUtil::getAppName()
{
    return [[[IOSSystemUtil getInstance] getAppName] UTF8String];
}
std::string IETSystemUtil::getAppVersionName() {
    NSString * version = [[NSBundle mainBundle] objectForInfoDictionaryKey: @"CFBundleShortVersionString"];
    return [version UTF8String];
}
int IETSystemUtil::getAppBuildNum() {
    NSString * build = [[NSBundle mainBundle] objectForInfoDictionaryKey: (NSString *)kCFBundleVersionKey];
    return [build intValue];
}
int IETSystemUtil::getAppVersion()
{
    return [[[IOSSystemUtil getInstance] getAppVersion] intValue];
}
std::string IETSystemUtil::getCountryCode()
{
    return [[[IOSSystemUtil getInstance] getCountryCode] UTF8String];
}
std::string IETSystemUtil::getLanguageCode()
{
    return [[[IOSSystemUtil getInstance] getLanguageCode] UTF8String];
}
std::string IETSystemUtil::getDeviceName()
{
    return [[[IOSSystemUtil getInstance] getDeviceName] UTF8String];
}
std::string IETSystemUtil::getSystemVersion()
{
    return [[[IOSSystemUtil getInstance] getSystemVersion] UTF8String];
}
std::string IETSystemUtil::getNetworkState()
{
    return [[[IOSSystemUtil getInstance] getNetworkState] UTF8String];
}
void IETSystemUtil::showAlertDialog(std::string title, std::string message, std::string cancelBtnTitle, cocos2d::ValueVector otherBtnTitles, const std::function<void (int)> &func)
{
    void (^block)(int buttonIdx) = [func](int buttonIdx) -> void {
        func(buttonIdx);
    };
    [[IOSSystemUtil getInstance] showAlertDialogWithTitle:NSStringFromString(title)
                                                  message:NSStringFromString(message)
                                           cancelBtnTitle:NSStringFromString(cancelBtnTitle)
                                           otherBtnTitles:[IETUtility valueVector2NsArr:otherBtnTitles]
                                                 callback:block];
}
void IETSystemUtil::showProgressDialog(std::string message, int percent)
{
    [[IOSSystemUtil getInstance] showProgressDialogWithMessage:NSStringFromString(message)
                                                       percent:percent];
}
void IETSystemUtil::hideProgressDialog()
{
    [[IOSSystemUtil getInstance] hideProgressDialog];
}
void IETSystemUtil::showLoading(std::string message)
{
    [[IOSSystemUtil getInstance] showLoadingWithMessage:NSStringFromString(message)];
}
void IETSystemUtil::hideLoading()
{
    [[IOSSystemUtil getInstance] hideLoading];
}
void IETSystemUtil::showMessage(std::string message)
{
    [[IOSSystemUtil getInstance] showMessage:NSStringFromString(message)];
}
void IETSystemUtil::vibrate()
{
    [[IOSSystemUtil getInstance] vibrate];
}
void IETSystemUtil::saveImage(std::string imgPath, std::string album, const std::function<void (bool, std::string)> &func)
{
    void (^block)(BOOL result, NSString *message) = [func](BOOL result, NSString *message) -> void {
        func(result, [message UTF8String]);
    };
    [[IOSSystemUtil getInstance] saveImage:NSStringFromString(imgPath)
                                   toAlbum:NSStringFromString(album)
                                   handler:block];
}
void IETSystemUtil::sendEmail(std::string subject, cocos2d::ValueVector toRecipients, std::string emailBody, const std::function<void (bool, std::string)> &func)
{
    void (^block)(BOOL result, NSString *message) = [func](BOOL result, NSString *message) -> void {
        func(result, [message UTF8String]);
    };
    [[IOSSystemUtil getInstance] sendEmailWithSubject:NSStringFromString(subject)
                                         toRecipients:[IETUtility valueVector2NsArr:toRecipients]
                                            emailBody:NSStringFromString(emailBody)
                                              handler:block];
}
void IETSystemUtil::setNotificationState(bool enable)
{
    [[IOSSystemUtil getInstance] setNotificationState:enable];
}
void IETSystemUtil::postNotification(cocos2d::ValueMap map)
{
    [[IOSSystemUtil getInstance] postNotification:[IETUtility valueMap2NsDict:map]];
}
void IETSystemUtil::share(cocos2d::ValueVector items)
{
    
}
void IETSystemUtil::keychainSet(std::string key, std::string value)
{
    [[IOSSystemUtil getInstance] keychainSet:NSStringFromString(key) withValue:NSStringFromString(value)];
}
std::string IETSystemUtil::keychainGet(std::string key)
{
    NSString* value = [[IOSSystemUtil getInstance] keychainGetValueForKey:NSStringFromString(key)];
    if (value == nil) {
        return "";
    }
    return [value UTF8String];
}
void IETSystemUtil::copyToPasteboard(std::string str)
{
    UIPasteboard *pasteboard = [UIPasteboard generalPasteboard];
    pasteboard.string = [NSString stringWithUTF8String:str.c_str()];
}

void IETSystemUtil::requestUrl(std::string requestType, std::string url, std::string data, const std::function<void (bool, std::string)> &func)
{
    CCLOG("%s, %s, %s", requestType.c_str(), url.c_str(), data.c_str());
    NSString* nsUrl = @"https://www.baidu.com";
    NSDictionary *params = @{@"foo": @"bar"};
    void(^success)(AFHTTPRequestOperation*, id) = ^(AFHTTPRequestOperation *operation, id responseObject) {
        NSLog(@"JSON: %@", responseObject);
    };
    void(^failure)(AFHTTPRequestOperation*, NSError*) = ^(AFHTTPRequestOperation *operation, NSError *error) {
        NSLog(@"Error: %@", error);
    };
    AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
    if (!strcmp(requestType.c_str(), "get")) {
        [manager GET:nsUrl parameters:params success:success failure:failure];
    } else {
        [manager POST:nsUrl parameters:params success:success failure:failure];
    }
//    AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
//    [manager GET:@"http://example.com/resources.json" parameters:nil success:^(AFHTTPRequestOperation *operation, id responseObject) {
//        NSLog(@"JSON: %@", responseObject);
//    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
//        NSLog(@"Error: %@", error);
//    }];
//    
//    AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
//    NSDictionary *parameters = @{@"foo": @"bar"};
//    [manager POST:@"http://example.com/resources.json" parameters:parameters success:^(AFHTTPRequestOperation *operation, id responseObject) {
//
//    } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
    
//    }];
}
