//
//  IETUtility.mm
//  gameplugin
//
//  Created by geekgy on 15/9/5.
//
//

#import "IETUtility.h"

using namespace std;
using namespace cocos2d;

@implementation IETUtility

static void addObjectToNSArray(const Value& value, NSMutableArray *array)
{
    // add string into array
    if (value.getType() == Value::Type::STRING)
    {
        NSString *element = [NSString stringWithCString:value.asString().c_str() encoding:NSUTF8StringEncoding];
        [array addObject:element];
        return;
    }
    
    //add float  into array
    if (value.getType() == Value::Type::FLOAT) {
        NSNumber *number = [NSNumber numberWithFloat:value.asFloat()];
        [array addObject:number];
    }
    
    //add double into array
    if (value.getType() == Value::Type::DOUBLE) {
        NSNumber *number = [NSNumber numberWithDouble:value.asDouble()];
        [array addObject:number];
    }
    
    //add boolean into array
    if (value.getType() == Value::Type::BOOLEAN) {
        NSNumber *element = [NSNumber numberWithBool:value.asBool()];
        [array addObject:element];
    }
    
    if (value.getType() == Value::Type::INTEGER) {
        NSNumber *element = [NSNumber numberWithInt:value.asInt()];
        [array addObject:element];
    }
    
    //todo: add date and data support
    
    // add array into array
    if (value.getType() == Value::Type::VECTOR)
    {
        NSMutableArray *element = [NSMutableArray array];
        
        ValueVector valueArray = value.asValueVector();
        
        for (const auto &e : valueArray)
        {
            addObjectToNSArray(e, element);
        }
        
        [array addObject:element];
        return;
    }
    
    // add dictionary value into array
    if (value.getType() == Value::Type::MAP)
    {
        NSMutableDictionary *element = [NSMutableDictionary dictionary];
        
        auto valueDict = value.asValueMap();
        for (auto iter = valueDict.begin(); iter != valueDict.end(); ++iter)
        {
            addObjectToNSDict(iter->first, iter->second, element);
        }
        
        [array addObject:element];
    }
}

void addObjectToNSDict(const std::string& key, const Value& value, NSMutableDictionary *dict)
{
    NSString *NSkey = [NSString stringWithCString:key.c_str() encoding:NSUTF8StringEncoding];
    
    // the object is a Dictionary
    if (value.getType() == Value::Type::MAP)
    {
        NSMutableDictionary *dictElement = [NSMutableDictionary dictionary];
        ValueMap subDict = value.asValueMap();
        for (auto iter = subDict.begin(); iter != subDict.end(); ++iter)
        {
            addObjectToNSDict(iter->first, iter->second, dictElement);
        }
        
        [dict setObject:dictElement forKey:NSkey];
        return;
    }
    
    //add float  into dict
    if (value.getType() == Value::Type::FLOAT) {
        NSNumber *number = [NSNumber numberWithFloat:value.asFloat()];
        [dict setObject:number forKey:NSkey];
    }
    
    //add double into dict
    if (value.getType() == Value::Type::DOUBLE) {
        NSNumber *number = [NSNumber numberWithDouble:value.asDouble()];
        [dict setObject:number forKey:NSkey];
    }
    
    //add boolean into dict
    if (value.getType() == Value::Type::BOOLEAN) {
        NSNumber *element = [NSNumber numberWithBool:value.asBool()];
        [dict setObject:element forKey:NSkey];
    }
    
    //add integer into dict
    if (value.getType() == Value::Type::INTEGER) {
        NSNumber *element = [NSNumber numberWithInt:value.asInt()];
        [dict setObject:element forKey:NSkey];
    }
    
    // the object is a String
    if (value.getType() == Value::Type::STRING)
    {
        NSString *strElement = [NSString stringWithCString:value.asString().c_str() encoding:NSUTF8StringEncoding];
        [dict setObject:strElement forKey:NSkey];
        return;
    }
    
    // the object is a Array
    if (value.getType() == Value::Type::VECTOR)
    {
        NSMutableArray *arrElement = [NSMutableArray array];
        
        ValueVector array = value.asValueVector();
        
        for(const auto& v : array)
        {
            addObjectToNSArray(v, arrElement);
        }
        
        [dict setObject:arrElement forKey:NSkey];
        return;
    }
}

void addValueToDict(id nsKey, id nsValue, ValueMap& dict)
{
    // the key must be a string
    CCASSERT([nsKey isKindOfClass:[NSString class]], "The key should be a string!");
    std::string key = [nsKey UTF8String];
    
    // the value is a string
    if ([nsValue isKindOfClass:[NSString class]])
    {
        dict[key] = Value([nsValue UTF8String]);
        return;
    }
    
    // the value is a number
    if ([nsValue isKindOfClass:[NSNumber class]])
    {
        NSNumber* num = nsValue;
        const char* numType = [num objCType];
        if(num == (void*)kCFBooleanFalse || num == (void*)kCFBooleanTrue)
        {
            dict[key] = Value([num boolValue]);
        }
        else if(strcmp(numType, @encode(float)) == 0)
        {
            dict[key] = Value([num floatValue]);
        }
        else if(strcmp(numType, @encode(double)) == 0)
        {
            dict[key] = Value([num doubleValue]);
        }
        else{
            dict[key] = Value([num intValue]);
        }
        return;
    }
    
    
    // the value is a new dictionary
    if ([nsValue isKindOfClass:[NSDictionary class]])
    {
        ValueMap subDict;
        
        for (id subKey in [nsValue allKeys])
        {
            id subValue = [nsValue objectForKey:subKey];
            addValueToDict(subKey, subValue, subDict);
        }
        dict[key] = Value(subDict);
        return;
    }
    
    // the value is a array
    if ([nsValue isKindOfClass:[NSArray class]])
    {
        ValueVector valueArray;
        
        for (id item in nsValue)
        {
            addItemToArray(item, valueArray);
        }
        dict[key] = Value(valueArray);
        return;
    }
    
}

void addItemToArray(id item, ValueVector& array)
{
    // add string value into array
    if ([item isKindOfClass:[NSString class]])
    {
        array.push_back(Value([item UTF8String]));
        return;
    }
    
    // add number value into array(such as int, float, bool and so on)
    // the value is a number
    if ([item isKindOfClass:[NSNumber class]])
    {
        NSNumber* num = item;
        const char* numType = [num objCType];
        if(num == (void*)kCFBooleanFalse || num == (void*)kCFBooleanTrue)
        {
            array.push_back(Value([num boolValue]));
        }
        else if(strcmp(numType, @encode(float)) == 0)
        {
            array.push_back(Value([num floatValue]));
        }
        else if(strcmp(numType, @encode(double)) == 0)
        {
            array.push_back(Value([num doubleValue]));
        }
        else{
            array.push_back(Value([num intValue]));
        }
        return;
    }
    
    
    // add dictionary value into array
    if ([item isKindOfClass:[NSDictionary class]])
    {
        ValueMap dict;
        for (id subKey in [item allKeys])
        {
            id subValue = [item objectForKey:subKey];
            addValueToDict(subKey, subValue, dict);
        }
        
        array.push_back(Value(dict));
        return;
    }
    
    // add array value into array
    if ([item isKindOfClass:[NSArray class]])
    {
        ValueVector subArray;
        for (id subItem in item)
        {
            addItemToArray(subItem, subArray);
        }
        array.push_back(Value(subArray));
        return;
    }
}

+ (cocos2d::ValueMap)nsDict2ValueMap:(NSDictionary *)dict {
    if (dict == nil) {
        return ValueMapNull;
    }
    ValueMap map;
    
    if (dict != nil)
    {
        for (id key in [dict allKeys])
        {
            id value = [dict objectForKey:key];
            addValueToDict(key, value, map);
        }
    }
    return map;
}

+ (NSDictionary*)valueMap2NsDict:(cocos2d::ValueMap)map {
    if (map == ValueMapNull) {
        return [NSDictionary dictionary];
    }
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    for (auto iter = map.begin(); iter != map.end(); ++iter)
    {
        addObjectToNSDict(iter->first, iter->second, dict);
    }
    return dict;
}

+ (cocos2d::ValueVector)nsArr2ValueVector:(NSArray *)arr {
    if (arr == nil) {
        return ValueVectorNull;
    }
    NSDictionary* dic = [NSDictionary dictionaryWithObject:arr forKey:@"arr"];
    ValueMap map = [self nsDict2ValueMap:dic];
    ValueVector vec = map.at("arr").asValueVector();
    return vec;
}

+ (NSArray *)valueVector2NsArr:(cocos2d::ValueVector)vec {
    if (vec == ValueVectorNull) {
        return [NSArray array];
    }
    ValueMap map;
    map["arr"] = Value(vec);
    NSDictionary* dic = [self valueMap2NsDict:map];
    NSArray* arr = [dic objectForKey:@"arr"];
    return arr;
}

@end







