//
//  IETAndroidBridge.h
//  gameplugin
//
//  Created by geekgy on 15/9/5.
//
//

#include "cocos2d.h"

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
     @param reqData json数据
     @return json数据
     */
    std::string callJavaMethod(std::string className, std::string methodName, std::string reqData);
    
    /**
     调用Java函数

     @param className 类名
     @param methodName 函数名
     @param reqData json数据
     @param handler 回调函数
     */
    void callJavaMethodAsync(std::string className, std::string methodName, std::string reqData, std::function<void (std::string)> handler);
    
    /**
     Java异步回调结果处理

     @param responseId responseId
     @param resData json数据
     */
    void handleJavaRes(int responseId, std::string resData);
    
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
	std::string callJavaMethod(std::string className, std::string methodName, std::string reqData, int requestId);

private:
    static IETAndroidBridge *instance;
    int requestId;
    std::map<int, std::function<void (std::string)>> handlerMap;
};

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
