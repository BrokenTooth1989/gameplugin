//
//  IETAndroidBridge.cpp
//  gameplugin
//
//  Created by geekgy on 15/9/5.
//
//

#include "IETAndroidBridge.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "jni.h"
#include "platform/android/jni/JniHelper.h"
#endif

using namespace std;
using namespace cocos2d;

IETAndroidBridge *IETAndroidBridge::instance = nullptr;

IETAndroidBridge* IETAndroidBridge::getInstance()
{
    if (!instance)
    {
        instance = new IETAndroidBridge();
    }
    return instance;
}

cocos2d::ValueVector IETAndroidBridge::callJavaMethod(std::string className, std::string methodName, cocos2d::ValueVector reqVec)
{
    return this->callJavaMethod(className, methodName, reqVec, -1);
}

cocos2d::ValueVector IETAndroidBridge::callJavaMethodAsync(std::string className, std::string methodName, cocos2d::ValueVector reqVec, std::function<void (cocos2d::ValueVector)> handler)
{
    int reqId = requestId++;
    handlerMap[reqId] = handler;
    return this->callJavaMethod(className, methodName, reqVec, reqId);
}

void IETAndroidBridge::handleJavaRes(int responseId, std::string resJson)
{
    std::function<void (cocos2d::ValueVector)> handler = handlerMap[responseId];
    ValueVector resVec = parseJson(resJson);
    handler(resVec);
    handlerMap[responseId] = nullptr;
}

cocos2d::ValueVector IETAndroidBridge::callJavaMethod(std::string className, std::string methodName, cocos2d::ValueVector reqVec, int requestId)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    string reqJson = generateJson(reqVec);
    JNIEnv* env = JniHelper::getEnv();
    jclass clazz = env->FindClass("com/joycastle/gameplugin/NativeUtil");
    jmethodID method = env->GetStaticMethodID(clazz, "invokeJavaMethod", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)Ljava/lang/String;");
    jstring jclassName = env->NewStringUTF(className.c_str());
    jstring jmethodName = env->NewStringUTF(methodName.c_str());
    jstring jreqJson = env->NewStringUTF(reqJson.c_str());
    jstring jresJson = (jstring)(env->CallStaticObjectMethod(clazz, method, jclassName, jmethodName, jreqJson, requestId));
    const char* resJson = env->GetStringUTFChars((jstring)jresJson, 0);
    env->DeleteLocalRef(clazz);
    env->DeleteLocalRef(jclassName);
    env->DeleteLocalRef(jmethodName);
    env->DeleteLocalRef(jreqJson);
    ValueVector resVec = parseJson(resJson);
    return resVec;
#else
    return ValueVectorNull;
#endif
}

std::string IETAndroidBridge::generateJson(cocos2d::ValueVector vec)
{
    rapidjson::Document document;
    document.SetObject();
    rapidjson::Document::AllocatorType & allocate = document.GetAllocator();
    
    rapidjson::Value valueArray(rapidjson::kArrayType);
    rapidjson::Value typeArray(rapidjson::kArrayType);
    valueVec2JsonArray(vec, valueArray, typeArray, allocate);
    document.AddMember("value", valueArray, allocate);
    document.AddMember("type", typeArray, allocate);
    
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer>  writer(buffer);
    document.Accept(writer);
    string jsonStr = buffer.GetString();
    
    return jsonStr;
}

cocos2d::ValueVector IETAndroidBridge::parseJson(std::string str)
{
    rapidjson::Document document;
    document.Parse<0>(str.c_str());

    if (document.HasParseError()) {
        CCLOG("Json Parse Error: %s", document.GetParseError());
        assert(false);
    }
    
    rapidjson::Value &valueArray = document["value"];
    ValueVector vec;
    jsonArray2ValueVec(valueArray, vec);
    
    return vec;
}

IETAndroidBridge::IETAndroidBridge()
:requestId(0)
{
}

IETAndroidBridge::~IETAndroidBridge()
{
}

void IETAndroidBridge::valueVec2JsonArray(cocos2d::ValueVector vec, rapidjson::Value &valArr, rapidjson::Value &typeArr, rapidjson::Document::AllocatorType &allocate)
{
    for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
        switch (iter->getType()) {
            case Value::Type::INTEGER:
            {
                valArr.PushBack(iter->asInt(), allocate);
                typeArr.PushBack("int", allocate);
            }
                break;
            case Value::Type::FLOAT:
            {
                valArr.PushBack(iter->asFloat(), allocate);
                typeArr.PushBack("float", allocate);
            }
                break;
            case Value::Type::DOUBLE:
            {
                valArr.PushBack(iter->asDouble(), allocate);
                typeArr.PushBack("double", allocate);
            }
                break;
            case Value::Type::BOOLEAN:
            {
                valArr.PushBack(iter->asBool(), allocate);
                typeArr.PushBack("bool", allocate);
            }
                break;
            case Value::Type::STRING:
            {
                string str = iter->asString();
                rapidjson::Value strVal;
                strVal.SetString(str.c_str(), (unsigned)str.length(), allocate);
                valArr.PushBack(strVal, allocate);
                typeArr.PushBack("string", allocate);
            }
                break;
            case Value::Type::VECTOR:
            {
                rapidjson::Value childArray(rapidjson::kArrayType);
                rapidjson::Value childType(rapidjson::kArrayType);
                valueVec2JsonArray(iter->asValueVector(), childArray, childType, allocate);
                valArr.PushBack(childArray, allocate);
                typeArr.PushBack(childType, allocate);
            }
                break;
            case Value::Type::MAP:
            {
                rapidjson::Value childValue(rapidjson::kObjectType);
                rapidjson::Value childType(rapidjson::kObjectType);
                valueMap2JsonObject(iter->asValueMap(), childValue, childType, allocate);
                valArr.PushBack(childValue, allocate);
                typeArr.PushBack(childType, allocate);
            }
                break;
            default:
                break;
        }
    }
}

void IETAndroidBridge::valueMap2JsonObject(cocos2d::ValueMap map, rapidjson::Value &valObj, rapidjson::Value &typeObj, rapidjson::Document::AllocatorType &allocate)
{
    for (auto iter = map.cbegin(); iter != map.cend(); ++iter)
    {
        switch (iter->second.getType()) {
            case Value::Type::INTEGER:
            {
                valObj.AddMember(iter->first.c_str(), iter->second.asInt(), allocate);
                typeObj.AddMember(iter->first.c_str(), "int", allocate);
            }
                break;
            case Value::Type::FLOAT:
            {
                valObj.AddMember(iter->first.c_str(), iter->second.asFloat(), allocate);
                typeObj.AddMember(iter->first.c_str(), "float", allocate);
            }
                break;
            case Value::Type::DOUBLE:
            {
                valObj.AddMember(iter->first.c_str(), iter->second.asDouble(), allocate);
                typeObj.AddMember(iter->first.c_str(), "double", allocate);
            }
                break;
            case Value::Type::BOOLEAN:
            {
                valObj.AddMember(iter->first.c_str(), iter->second.asBool(), allocate);
                typeObj.AddMember(iter->first.c_str(), "bool", allocate);
            }
                break;
            case Value::Type::STRING:
            {
                string str = iter->second.asString();
                rapidjson::Value strVal;
                strVal.SetString(str.c_str(), (unsigned)str.length(), allocate);
                valObj.AddMember(iter->first.c_str(), strVal, allocate);
                typeObj.AddMember(iter->first.c_str(), "string", allocate);
            }
                break;
            case Value::Type::VECTOR:
            {
                rapidjson::Value childArray(rapidjson::kArrayType);
                rapidjson::Value childType(rapidjson::kArrayType);
                valueVec2JsonArray(iter->second.asValueVector(), childArray, childType, allocate);
                valObj.AddMember(iter->first.c_str(), childArray, allocate);
                typeObj.AddMember(iter->first.c_str(), childType, allocate);
            }
                break;
            case Value::Type::MAP:
            {
                rapidjson::Value childObject(rapidjson::kObjectType);
                rapidjson::Value childType(rapidjson::kObjectType);
                valueMap2JsonObject(iter->second.asValueMap(), childObject, childType, allocate);
                valObj.AddMember(iter->first.c_str(), childObject, allocate);
                typeObj.AddMember(iter->first.c_str(), childType, allocate);
            }
                break;
            default:
                break;
        }
    }
}

void IETAndroidBridge::jsonArray2ValueVec(rapidjson::Value &valArr, cocos2d::ValueVector &vec)
{
    for (int i=0; i<valArr.Size(); i++) {
        rapidjson::Value &value = valArr[i];
        if (value.IsInt()) {
            vec.push_back(Value(value.GetInt()));
        } else if (value.IsDouble()) {
            vec.push_back(Value(value.GetDouble()));
        } else if (value.IsBool()) {
            vec.push_back(Value(value.GetBool()));
        } else if (value.IsString()) {
            vec.push_back(Value(value.GetString()));
        } else if (value.IsArray()) {
            ValueVector childVec;
            jsonArray2ValueVec(value, childVec);
            vec.push_back(Value(childVec));
        } else if (value.IsObject()) {
            ValueMap childMap;
            jsonObject2ValueMap(value, childMap);
            vec.push_back(Value(childMap));
        }
    }
}

void IETAndroidBridge::jsonObject2ValueMap(rapidjson::Value &valObj, cocos2d::ValueMap &map)
{
    for (auto it = valObj.MemberonBegin(); it != valObj.MemberonEnd(); it++) {
        string key = it->name.GetString();
        if (it->value.IsInt()) {
            map[key] = Value(it->value.GetInt());
        } else if (it->value.IsDouble()) {
            map[key] = Value(it->value.GetDouble());
        } else if (it->value.IsBool()) {
            map[key] = Value(it->value.GetBool());
        } else if (it->value.IsString()) {
            map[key] = Value(it->value.GetString());
        } else if (it->value.IsArray()) {
            ValueVector childVec;
            jsonArray2ValueVec(it->value, childVec);
            map[key] = Value(childVec);
        } else if (it->value.IsObject()) {
            ValueMap childMap;
            jsonObject2ValueMap(it->value, childMap);
            map[key] = Value(childMap);
        }
    }
}

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
JNIEXPORT void JNICALL Java_com_joycastle_gameplugin_NativeUtil_invokeCppMethod(JNIEnv *env, jclass type, jint responseId, jstring resData_)
{
    const char *resData = env->GetStringUTFChars(resData_, 0);
    IETAndroidBridge::getInstance()->handleJavaRes(responseId, resData);
    env->ReleaseStringUTFChars(resData_, resData);
}
#endif
