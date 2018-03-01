//
//  IETAndroidBridge.h
//  gameplugin
//
//  Created by geekgy on 15/9/5.
//
//

#include "cocos2d.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

class IETAndroidBridge
{
public:
    /**
     单例

     @return 对象
     */
    static IETAndroidBridge* getInstance();
    
    /**
     调用Java函数

     @param className 类名
     @param methodName 函数名
     @param reqData 数据
     @return 数据
     */
    cocos2d::ValueVector callJavaMethod(std::string className, std::string methodName, cocos2d::ValueVector reqVec);
    
    /**
     调用Java函数

     @param className 类名
     @param methodName 函数名
     @param reqData json数据
     @param handler 回调函数
     @return 数据
     */
    cocos2d::ValueVector callJavaMethodAsync(std::string className, std::string methodName, cocos2d::ValueVector reqVec, std::function<void (cocos2d::ValueVector)> handler);
    
    /**
     Java异步回调结果处理

     @param responseId responseId
     @param resData json数据
     */
    void handleJavaRes(int responseId, std::string resData);
    
    /**
     生成Json

     @param vec 参数
     @return json
     */
    std::string generateJson(cocos2d::ValueVector vec);;
    
    /**
     Json解析

     @param str json
     @return 参数
     */
    cocos2d::ValueVector parseJson(std::string str);
    
private:
    IETAndroidBridge();
    ~IETAndroidBridge();

    /**
     调用Java函数

     @param className 类名
     @param methodName 方法名
     @param reqData json数据
     @param requestId requestId
     @return json数据
     */
    cocos2d::ValueVector callJavaMethod(std::string className, std::string methodName, cocos2d::ValueVector reqVec, int requestId);
    
    void valueVec2JsonArray(cocos2d::ValueVector vec, rapidjson::Value &valArr, rapidjson::Value &typeArr, rapidjson::Document::AllocatorType &allocate);

    void valueMap2JsonObject(cocos2d::ValueMap map, rapidjson::Value &valObj, rapidjson::Value &typeObj, rapidjson::Document::AllocatorType &allocate);
    
    void jsonArray2ValueVec(rapidjson::Value &valArr, cocos2d::ValueVector &vec);
    
    void jsonObject2ValueMap(rapidjson::Value &valObj, cocos2d::ValueMap &map);
    
private:
    static IETAndroidBridge *instance;
    int requestId;
    std::map<int, std::function<void (cocos2d::ValueVector)>> handlerMap;
};

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_joycastle_gameplugin_NativeUtil
 * Method:    invokeCppMethod
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_joycastle_gameplugin_NativeUtil_invokeCppMethod
  (JNIEnv *, jclass, jint, jstring);

#ifdef __cplusplus
}
#endif
#endif
