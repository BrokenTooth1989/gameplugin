//
//  IETGamePluginDefine.h
//  gameplugin
//
//  Created by geekgy on 15/6/11.
//
//

#ifndef gameplugin_IETGamePluginDefine_h
#define gameplugin_IETGamePluginDefine_h

// 单例
#define SINGLETON(__CLASS_NAME__) \
static __CLASS_NAME__* getInstance() { \
    static __CLASS_NAME__ *_instance = nullptr; \
    if (_instance == nullptr) { \
        _instance = new __CLASS_NAME__(); \
        _instance->init(); \
    } \
    return _instance; \
} \

#endif
