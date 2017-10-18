//
//  IETFacebookHelper.mm
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#include "IETFacebookHelper.h"
#import <Foundation/Foundation.h>
#import "IETUtility.h"

using namespace std;
using namespace cocos2d;

void IETFacebookHelper::openFacebookPage(std::string installUrl, std::string url)
{
    NSString* nsInstallUrl = [NSString stringWithUTF8String:installUrl.c_str()];
    NSString* nsUrl = [NSString stringWithUTF8String:url.c_str()];
    [[NSClassFromString(@"FacebookHelper") getInstance] openFacebookPage:nsInstallUrl :nsUrl];
}

void IETFacebookHelper::setLoginFunc(const std::function<void(std::string, std::string)>& func)
{
    void (^block)(NSString*,NSString*) = [func](NSString* fid, NSString* token) -> void {
        func([fid UTF8String], [token UTF8String]);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] setLoginFunc:block];
}

void IETFacebookHelper::setAppLinkFunc(const std::function<void(cocos2d::ValueMap)>& func)
{
    void (^block)(NSDictionary*) = [func](NSDictionary* userInfo) -> void {
        ValueMap valueMap = [IETUtility nsDict2ValueMap:userInfo];
        func(valueMap);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] setAppLinkFunc:block];
}

bool IETFacebookHelper::isLogin()
{
    if ([[NSClassFromString(@"FacebookHelper") getInstance] isLogin]) {
        return true;
    }
    return false;
}

void IETFacebookHelper::inviteFriend(std::string appLinkURL,std::string prviewImageURL, std::function<void(bool)>& func)
{
    void (^block)(BOOL) = [func](BOOL b) -> void {
        func(b);
    };
    
    NSString* nsappLinkURL = [NSString stringWithUTF8String:appLinkURL.c_str()];
    NSString* nsprviewImageURL = [NSString stringWithUTF8String:prviewImageURL.c_str()];
    
    [[NSClassFromString(@"FacebookHelper") getInstance] inviteFriendsWithLink:nsappLinkURL andImg:nsprviewImageURL withBlock:block];
    
    
}

void IETFacebookHelper::login()
{
    [[NSClassFromString(@"FacebookHelper") getInstance] login];
}

void IETFacebookHelper::logout()
{
    [[NSClassFromString(@"FacebookHelper") getInstance] logout];
}

std::string IETFacebookHelper::getUserID()
{
    NSString* nsUserId = [[NSClassFromString(@"FacebookHelper") getInstance] getUserID];
    nsUserId = nsUserId==nil?@"":nsUserId;
    return [nsUserId UTF8String];
}

std::string IETFacebookHelper::getAccessToken()
{
    NSString* nsToken = [[NSClassFromString(@"FacebookHelper") getInstance] getAccessToken];
    nsToken = nsToken==nil?@"":nsToken;
    return [nsToken UTF8String];
}

void IETFacebookHelper::getUserProfile(std::string fid, int picSize, std::function<void (cocos2d::ValueMap)> &func)
{
    NSString* nsFid = [NSString stringWithUTF8String:fid.c_str()];
    void (^block)(NSDictionary*) = [func](NSDictionary* dict) -> void{
        func([IETUtility nsDict2ValueMap:dict]);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] getUserProfileWithId:nsFid
                                                                  andPicSize:picSize
                                                                          cb:block];
}

void IETFacebookHelper::getInvitableFriends(cocos2d::ValueVector inviteTokens, int picSize, std::function<void (cocos2d::ValueMap)> &func)
{
    NSMutableArray* nsInviteTokens = [NSMutableArray array];
    for (int i=0; i<inviteTokens.size(); i++) {
        string str = inviteTokens.at(i).asString();
        [nsInviteTokens addObject:[NSString stringWithUTF8String:str.c_str()]];
    }
    void (^block)(NSDictionary*) = [func](NSDictionary* friends) -> void{
        func([IETUtility nsDict2ValueMap:friends]);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] getInvitableFriendsWithInviteToken:nsInviteTokens
                                                                                   picSize:picSize
                                                                                        cb:block];
}

void IETFacebookHelper::getFriends(int picSize, std::function<void (cocos2d::ValueMap)> &func)
{
    void (^block)(NSDictionary*) = [func](NSDictionary* friends) -> void{
        func([IETUtility nsDict2ValueMap:friends]);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] getFriendsWithPicSize:picSize
                                                                           cb:block];
}

void IETFacebookHelper::confirmRequest(cocos2d::ValueVector fidOrTokens, std::string title, std::string msg, std::function<void (cocos2d::ValueMap)> &func)
{
    NSMutableArray* nsFidOrTokens = [NSMutableArray array];
    for (int i=0; i<fidOrTokens.size(); i++) {
        string str = fidOrTokens.at(i).asString();
        [nsFidOrTokens addObject:[NSString stringWithUTF8String:str.c_str()]];
    }
    NSString* nsTitle = [NSString stringWithUTF8String:title.c_str()];
    NSString* nsMsg =[NSString stringWithUTF8String:msg.c_str()];
    void (^block)(NSDictionary*) = [func](NSDictionary* dict) -> void{
        func([IETUtility nsDict2ValueMap:dict]);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] confirmRequest:nsFidOrTokens
                                                             withTitle:nsTitle
                                                               withMsg:nsMsg
                                                                    cb:block];
}

void IETFacebookHelper::queryRequest(std::function<void (cocos2d::ValueMap)> &func)
{
    void (^block)(NSDictionary*) = [func](NSDictionary* requests) -> void{
        func([IETUtility nsDict2ValueMap:requests]);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] queryRequest:block];
}

void IETFacebookHelper::acceptRequest(std::string requestId, std::function<void (bool)> &func)
{
    NSString* nsRequestId = [NSString stringWithUTF8String:requestId.c_str()];
    void (^block)(BOOL) = [func](BOOL result) -> void{
        func(result);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] acceptRequest:nsRequestId cb:block];
}

void IETFacebookHelper::share(std::string title, std::string description, std::string caption, std::string imageUrl, std::string contentUrl, std::function<void (bool)> &func)
{
    NSString* nsTitle = [NSString stringWithUTF8String:title.c_str()];
    NSString* nsDesc = [NSString stringWithUTF8String:description.c_str()];
    NSString* nsCaption = [NSString stringWithUTF8String:caption.c_str()];
    NSString* nsImgUrl = [NSString stringWithUTF8String:imageUrl.c_str()];
    NSString* nsContentUrl = [NSString stringWithUTF8String:contentUrl.c_str()];
    void (^block)(BOOL) = [func](BOOL result) -> void{
        func(result);
    };
    
    [[NSClassFromString(@"FacebookHelper") getInstance] shareName:nsTitle
                                description:nsDesc
                                   imageUrl:nsImgUrl
                                 contentUrl:nsContentUrl
                                    caption:nsCaption
                                           :block];
}

void IETFacebookHelper::setLevel(int level)
{
    [[NSClassFromString(@"FacebookHelper") getInstance] setLevel:level];
}

void IETFacebookHelper::getLevel(std::string fid, std::function<void (int)> &func)
{
    NSString* nsFid = [NSString stringWithUTF8String:fid.c_str()];
    void (^block)(int) = [func](int level) -> void{
        func(level);
    };
    [[NSClassFromString(@"FacebookHelper") getInstance] getLevelWithId:nsFid cb:block];
}
