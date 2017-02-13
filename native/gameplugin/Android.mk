
LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := gameplugin_static
LOCAL_MODULE_FILENAME := libgameplugin

LOCAL_SRC_FILES := 	$(LOCAL_PATH)/IETAdvertiseHelper.cpp \
					$(LOCAL_PATH)/IETAmazonAWSHelper.cpp \
					$(LOCAL_PATH)/IETAnalyticHelper.cpp \
					$(LOCAL_PATH)/IETFacebookHelper.cpp \
					$(LOCAL_PATH)/IETGamePlugin.cpp \
					$(LOCAL_PATH)/IETSystemUtil.cpp \
					$(LOCAL_PATH)/android/IETAdvertiseHelper.cpp \
					$(LOCAL_PATH)/android/IETAmazonAWSHelper.cpp \
					$(LOCAL_PATH)/android/IETAnalyticHelper.cpp \
					$(LOCAL_PATH)/android/IETFacebookHelper.cpp \
					$(LOCAL_PATH)/android/IETGamePlugin.cpp \
					$(LOCAL_PATH)/android/IETSystemUtil.cpp \
					$(LOCAL_PATH)/scripting/lua-bindings/manual/lua_cocos2dx_gameplugin_manual.cpp \
					$(LOCAL_PATH)/scripting/lua-bindings/auto/lua_cocos2dx_gameplugin_auto.cpp 


LOCAL_EXPORT_C_INCLUDES := 	$(LOCAL_PATH)/ \
							$(LOCAL_PATH)/scripting/lua-bindings/manual \
							$(LOCAL_PATH)/scripting/lua-bindings/auto 

LOCAL_C_INCLUDES := $(LOCAL_PATH)/ \
					$(COCOS2DX_ROOT)/ \
                    $(COCOS2DX_ROOT)/cocos \
                    $(COCOS2DX_ROOT)/cocos/scripting/lua-bindings/manual \
                    $(COCOS2DX_ROOT)/cocos/platform \
                    $(COCOS2DX_ROOT)/external \
                    $(COCOS2DX_ROOT)/external/lua/tolua \
                    $(COCOS2DX_ROOT)/external/lua/luajit/include

include $(BUILD_STATIC_LIBRARY)
