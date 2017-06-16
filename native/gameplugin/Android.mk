
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := gameplugin_static
LOCAL_MODULE_FILENAME := libgameplugin

LOCAL_SRC_FILES :=  aes.c \
					android/IETAdvertiseHelper.cpp \
					android/IETAmazonAWSHelper.cpp \
					android/IETAnalyticHelper.cpp \
					android/IETFacebookHelper.cpp \
					android/IETGamePlugin.cpp \
					android/IETSystemUtil.cpp \
					IETSystemUtil.cpp \
					scripting/lua-bindings/manual/lua_cocos2dx_gameplugin_manual.cpp \
					scripting/lua-bindings/auto/lua_cocos2dx_gameplugin_auto.cpp 


LOCAL_EXPORT_C_INCLUDES := 	$(LOCAL_PATH) \
							$(LOCAL_PATH)/scripting/lua-bindings/manual \
							$(LOCAL_PATH)/scripting/lua-bindings/auto 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/ \
					$(COCOS2DX_ROOT)/ \
                    $(COCOS2DX_ROOT)/cocos/ \
                    $(COCOS2DX_ROOT)/cocos/scripting/lua-bindings/manual \
                    $(COCOS2DX_ROOT)/cocos/platform \
                    $(COCOS2DX_ROOT)/external \
                    $(COCOS2DX_ROOT)/external/lua/tolua \
                    $(COCOS2DX_ROOT)/external/lua/luajit/include

$(warning $(COCOS2DX_ROOT))
include $(BUILD_STATIC_LIBRARY)