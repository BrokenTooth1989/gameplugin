//
//  IETUtility.h
//  gameplugin
//
//  Created by geekgy on 15/9/5.
//
//

#import <Foundation/Foundation.h>
#include "cocos2d.h"

#define NSStringFromString(str) [NSString stringWithUTF8String:str.c_str()]

@interface IETUtility : NSObject

+ (cocos2d::ValueMap)nsDict2ValueMap:(NSDictionary*)dict;

+ (NSDictionary*)valueMap2NsDict:(cocos2d::ValueMap)map;

+ (cocos2d::ValueVector)nsArr2ValueVector:(NSArray*)arr;

+ (NSArray*)valueVector2NsArr:(cocos2d::ValueVector)vec;

@end
