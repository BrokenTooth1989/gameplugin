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

int IETSystemUtil::getDebugMode() {
    return DEBUG_LEVEL;
}
std::string IETSystemUtil::getPlatCfgValue(std::string key)
{
    return [[[IOSSystemUtil getInstance] getConfigValueWithKey:NSStringFromString(key)] UTF8String];
}
std::string IETSystemUtil::getAppBundleId()
{
    return [[[IOSSystemUtil getInstance] getAppBundleId] UTF8String];
}
std::string IETSystemUtil::getAppName()
{
    return [[[IOSSystemUtil getInstance] getAppName] UTF8String];
}
std::string IETSystemUtil::getAppVersion() {
    return [[[IOSSystemUtil getInstance] getAppVersion] UTF8String];
}
int IETSystemUtil::getAppBuild() {
    return [[[IOSSystemUtil getInstance] getAppBuild] intValue];
}
std::string IETSystemUtil::getDeviceName() {
    return [[[IOSSystemUtil getInstance] getDeviceName] UTF8String];
}
std::string IETSystemUtil::getDeviceModel() {
    return [[[IOSSystemUtil getInstance] getDeviceModel] UTF8String];
}
std::string IETSystemUtil::getDeviceType() {
    return [[[IOSSystemUtil getInstance] getDeviceType] UTF8String];
}
std::string IETSystemUtil::getSystemName() {
    return [[[IOSSystemUtil getInstance] getSystemName] UTF8String];
}
std::string IETSystemUtil::getSystemVersion() {
    return [[[IOSSystemUtil getInstance] getSystemVersion] UTF8String];
}
std::string IETSystemUtil::getIDFV() {
    return [[[IOSSystemUtil getInstance] getIDFV] UTF8String];
}
std::string IETSystemUtil::getIDFA() {
    return [[[IOSSystemUtil getInstance] getIDFA] UTF8String];
}
std::string IETSystemUtil::getUUID() {
    return [[[IOSSystemUtil getInstance] getUUID] UTF8String];
}
std::string IETSystemUtil::getCountryCode()
{
    return [[[IOSSystemUtil getInstance] getCountryCode] UTF8String];
}
std::string IETSystemUtil::getLanguageCode()
{
    return [[[IOSSystemUtil getInstance] getLanguageCode] UTF8String];
}
long IETSystemUtil::getCpuTime() {
    return [[IOSSystemUtil getInstance] getCpuTime];
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
void IETSystemUtil::setBadgeNum(int num)
{
    [[IOSSystemUtil getInstance] setBadgeNum:num];
}
void IETSystemUtil::share(cocos2d::ValueVector items)
{
    [[IOSSystemUtil getInstance] share:[IETUtility valueVector2NsArr:items]];
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
bool IETSystemUtil::isJailbroken()
{
    return [[IOSSystemUtil getInstance] isJailbroken];
}
void IETSystemUtil::copyToPasteboard(std::string str)
{
    [[IOSSystemUtil getInstance] saveToPasteboard:NSStringFromString(str)];
}

void IETSystemUtil::requestUrl(std::string requestType, std::string url, cocos2d::ValueMap data, const std::function<void (bool, std::string)> func)
{
    NSString *nsReqType = NSStringFromString(requestType);
    NSString *nsUrl = NSStringFromString(url);
    NSDictionary *nsData = [IETUtility valueMap2NsDict:data];
    void (^block)(BOOL result, NSDictionary *resp) = [func](BOOL result, NSDictionary *resp) -> void {
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:resp options:NSJSONWritingPrettyPrinted error:nil];
        NSString *jsonString = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        func(result, [jsonString UTF8String]);
    };
    [[IOSSystemUtil getInstance] sendRequest:nsReqType url:nsUrl data:nsData handler:block];
}
