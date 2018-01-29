#include "lua_cocos2dx_gameplugin_auto.hpp"
#include "IETGamePluginConfig.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_cocos2dx_gameplugin_auto_IETSystemUtil_showLoading(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showLoading'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:showLoading");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showLoading'", nullptr);
            return 0;
        }
        cobj->showLoading(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:showLoading",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showLoading'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_postNotification(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_postNotification'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueMap arg0;

        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "IETSystemUtil:postNotification");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_postNotification'", nullptr);
            return 0;
        }
        cobj->postNotification(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:postNotification",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_postNotification'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_openUrl(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_openUrl'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:openUrl");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_openUrl'", nullptr);
            return 0;
        }
        cobj->openUrl(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:openUrl",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_openUrl'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideProgressDialog(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideProgressDialog'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideProgressDialog'", nullptr);
            return 0;
        }
        cobj->hideProgressDialog();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:hideProgressDialog",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideProgressDialog'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlDecode(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlDecode'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:urlDecode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlDecode'", nullptr);
            return 0;
        }
        std::string ret = cobj->urlDecode(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:urlDecode",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlDecode'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Decode(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Decode'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:base64Decode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Decode'", nullptr);
            return 0;
        }
        std::string ret = cobj->base64Decode(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:base64Decode",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Decode'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_share(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_share'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueVector arg0;

        ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "IETSystemUtil:share");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_share'", nullptr);
            return 0;
        }
        cobj->share(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:share",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_share'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceType(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceType'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceType'", nullptr);
            return 0;
        }
        std::string ret = cobj->getDeviceType();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getDeviceType",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceType'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_setNotificationState(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_setNotificationState'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "IETSystemUtil:setNotificationState");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_setNotificationState'", nullptr);
            return 0;
        }
        cobj->setNotificationState(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:setNotificationState",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_setNotificationState'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_vibrate(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_vibrate'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_vibrate'", nullptr);
            return 0;
        }
        cobj->vibrate();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:vibrate",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_vibrate'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLanguageCode(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLanguageCode'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLanguageCode'", nullptr);
            return 0;
        }
        std::string ret = cobj->getLanguageCode();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getLanguageCode",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLanguageCode'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainSet(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainSet'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:keychainSet");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETSystemUtil:keychainSet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainSet'", nullptr);
            return 0;
        }
        cobj->keychainSet(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:keychainSet",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainSet'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppVersion(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppVersion'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppVersion'", nullptr);
            return 0;
        }
        std::string ret = cobj->getAppVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getAppVersion",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppVersion'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLocalCfgValue(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLocalCfgValue'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:getLocalCfgValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLocalCfgValue'", nullptr);
            return 0;
        }
        std::string ret = cobj->getLocalCfgValue(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getLocalCfgValue",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLocalCfgValue'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceName(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceName'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getDeviceName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getDeviceName",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceName'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBuild(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBuild'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBuild'", nullptr);
            return 0;
        }
        int ret = cobj->getAppBuild();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getAppBuild",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBuild'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatformType(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatformType'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatformType'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPlatformType();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getPlatformType",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatformType'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_exitGame(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_exitGame'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_exitGame'", nullptr);
            return 0;
        }
        cobj->exitGame();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:exitGame",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_exitGame'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_setBadgeNum(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_setBadgeNum'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IETSystemUtil:setBadgeNum");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_setBadgeNum'", nullptr);
            return 0;
        }
        cobj->setBadgeNum(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:setBadgeNum",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_setBadgeNum'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getNetworkState(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getNetworkState'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getNetworkState'", nullptr);
            return 0;
        }
        std::string ret = cobj->getNetworkState();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getNetworkState",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getNetworkState'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFA(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFA'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFA'", nullptr);
            return 0;
        }
        std::string ret = cobj->getIDFA();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getIDFA",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFA'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_showProgressDialog(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showProgressDialog'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        int arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:showProgressDialog");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "IETSystemUtil:showProgressDialog");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showProgressDialog'", nullptr);
            return 0;
        }
        cobj->showProgressDialog(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:showProgressDialog",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showProgressDialog'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaDecrypt(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaDecrypt'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:xxteaDecrypt");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETSystemUtil:xxteaDecrypt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaDecrypt'", nullptr);
            return 0;
        }
        std::string ret = cobj->xxteaDecrypt(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:xxteaDecrypt",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaDecrypt'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCpuTime(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCpuTime'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCpuTime'", nullptr);
            return 0;
        }
        long ret = cobj->getCpuTime();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getCpuTime",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCpuTime'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCountryCode(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCountryCode'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCountryCode'", nullptr);
            return 0;
        }
        std::string ret = cobj->getCountryCode();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getCountryCode",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCountryCode'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBundleId(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBundleId'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBundleId'", nullptr);
            return 0;
        }
        std::string ret = cobj->getAppBundleId();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getAppBundleId",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBundleId'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_isJailbroken(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_isJailbroken'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_isJailbroken'", nullptr);
            return 0;
        }
        bool ret = cobj->isJailbroken();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:isJailbroken",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_isJailbroken'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemName(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemName'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getSystemName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getSystemName",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemName'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaEncrypt(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaEncrypt'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:xxteaEncrypt");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETSystemUtil:xxteaEncrypt");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaEncrypt'", nullptr);
            return 0;
        }
        std::string ret = cobj->xxteaEncrypt(arg0, arg1);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:xxteaEncrypt",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaEncrypt'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getOnlineCfgValue(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getOnlineCfgValue'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:getOnlineCfgValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getOnlineCfgValue'", nullptr);
            return 0;
        }
        std::string ret = cobj->getOnlineCfgValue(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getOnlineCfgValue",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getOnlineCfgValue'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatCfgValue(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatCfgValue'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:getPlatCfgValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatCfgValue'", nullptr);
            return 0;
        }
        std::string ret = cobj->getPlatCfgValue(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getPlatCfgValue",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatCfgValue'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceModel(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceModel'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceModel'", nullptr);
            return 0;
        }
        std::string ret = cobj->getDeviceModel();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getDeviceModel",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceModel'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlEncode(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlEncode'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:urlEncode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlEncode'", nullptr);
            return 0;
        }
        std::string ret = cobj->urlEncode(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:urlEncode",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlEncode'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainGet(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainGet'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:keychainGet");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainGet'", nullptr);
            return 0;
        }
        std::string ret = cobj->keychainGet(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:keychainGet",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainGet'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFV(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFV'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFV'", nullptr);
            return 0;
        }
        std::string ret = cobj->getIDFV();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getIDFV",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFV'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getUUID(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getUUID'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getUUID'", nullptr);
            return 0;
        }
        std::string ret = cobj->getUUID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getUUID",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getUUID'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_uncompressZip(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_uncompressZip'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:uncompressZip");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETSystemUtil:uncompressZip");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_uncompressZip'", nullptr);
            return 0;
        }
        bool ret = cobj->uncompressZip(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:uncompressZip",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_uncompressZip'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemVersion(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemVersion'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemVersion'", nullptr);
            return 0;
        }
        std::string ret = cobj->getSystemVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getSystemVersion",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemVersion'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideLoading(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideLoading'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideLoading'", nullptr);
            return 0;
        }
        cobj->hideLoading();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:hideLoading",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideLoading'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDebugMode(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDebugMode'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDebugMode'", nullptr);
            return 0;
        }
        int ret = cobj->getDebugMode();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getDebugMode",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDebugMode'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCfgValue(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCfgValue'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:getCfgValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCfgValue'", nullptr);
            return 0;
        }
        std::string ret = cobj->getCfgValue(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getCfgValue",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCfgValue'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Encode(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Encode'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:base64Encode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Encode'", nullptr);
            return 0;
        }
        std::string ret = cobj->base64Encode(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:base64Encode",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Encode'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCurrentTimeMills(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCurrentTimeMills'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCurrentTimeMills'", nullptr);
            return 0;
        }
        long long ret = cobj->getCurrentTimeMills();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getCurrentTimeMills",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCurrentTimeMills'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_showMessage(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showMessage'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:showMessage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showMessage'", nullptr);
            return 0;
        }
        cobj->showMessage(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:showMessage",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_showMessage'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppName(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppName'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getAppName();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:getAppName",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppName'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_copyToPasteboard(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_copyToPasteboard'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:copyToPasteboard");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_copyToPasteboard'", nullptr);
            return 0;
        }
        cobj->copyToPasteboard(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:copyToPasteboard",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_copyToPasteboard'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_setLocalConfig(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

    tolua_Error tolua_err;

    if (!tolua_isusertable(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:setLocalConfig");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_setLocalConfig'", nullptr);
            return 0;
        }
        IETSystemUtil::setLocalConfig(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IETSystemUtil:setLocalConfig",argc, 1);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_setLocalConfig'.",&tolua_err);
    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETSystemUtil_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

    tolua_Error tolua_err;

    if (!tolua_isusertable(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getInstance'", nullptr);
            return 0;
        }
        IETSystemUtil* ret = IETSystemUtil::getInstance();
        object_to_luaval<IETSystemUtil>(tolua_S, "IETSystemUtil",(IETSystemUtil*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IETSystemUtil:getInstance",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETSystemUtil_getInstance'.",&tolua_err);
    return 0;
}
static int lua_cocos2dx_gameplugin_auto_IETSystemUtil_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IETSystemUtil)");
    return 0;
}

int lua_register_cocos2dx_gameplugin_auto_IETSystemUtil(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETSystemUtil");
    tolua_cclass(tolua_S,"IETSystemUtil","IETSystemUtil","",nullptr);

    tolua_beginmodule(tolua_S,"IETSystemUtil");
        tolua_function(tolua_S,"showLoading",lua_cocos2dx_gameplugin_auto_IETSystemUtil_showLoading);
        tolua_function(tolua_S,"postNotification",lua_cocos2dx_gameplugin_auto_IETSystemUtil_postNotification);
        tolua_function(tolua_S,"openUrl",lua_cocos2dx_gameplugin_auto_IETSystemUtil_openUrl);
        tolua_function(tolua_S,"hideProgressDialog",lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideProgressDialog);
        tolua_function(tolua_S,"urlDecode",lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlDecode);
        tolua_function(tolua_S,"base64Decode",lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Decode);
        tolua_function(tolua_S,"share",lua_cocos2dx_gameplugin_auto_IETSystemUtil_share);
        tolua_function(tolua_S,"getDeviceType",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceType);
        tolua_function(tolua_S,"setNotificationState",lua_cocos2dx_gameplugin_auto_IETSystemUtil_setNotificationState);
        tolua_function(tolua_S,"vibrate",lua_cocos2dx_gameplugin_auto_IETSystemUtil_vibrate);
        tolua_function(tolua_S,"getLanguageCode",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLanguageCode);
        tolua_function(tolua_S,"keychainSet",lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainSet);
        tolua_function(tolua_S,"getAppVersion",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppVersion);
        tolua_function(tolua_S,"getLocalCfgValue",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getLocalCfgValue);
        tolua_function(tolua_S,"getDeviceName",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceName);
        tolua_function(tolua_S,"getAppBuild",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBuild);
        tolua_function(tolua_S,"getPlatformType",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatformType);
        tolua_function(tolua_S,"exitGame",lua_cocos2dx_gameplugin_auto_IETSystemUtil_exitGame);
        tolua_function(tolua_S,"setBadgeNum",lua_cocos2dx_gameplugin_auto_IETSystemUtil_setBadgeNum);
        tolua_function(tolua_S,"getNetworkState",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getNetworkState);
        tolua_function(tolua_S,"getIDFA",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFA);
        tolua_function(tolua_S,"showProgressDialog",lua_cocos2dx_gameplugin_auto_IETSystemUtil_showProgressDialog);
        tolua_function(tolua_S,"xxteaDecrypt",lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaDecrypt);
        tolua_function(tolua_S,"getCpuTime",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCpuTime);
        tolua_function(tolua_S,"getCountryCode",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCountryCode);
        tolua_function(tolua_S,"getAppBundleId",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppBundleId);
        tolua_function(tolua_S,"isJailbroken",lua_cocos2dx_gameplugin_auto_IETSystemUtil_isJailbroken);
        tolua_function(tolua_S,"getSystemName",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemName);
        tolua_function(tolua_S,"xxteaEncrypt",lua_cocos2dx_gameplugin_auto_IETSystemUtil_xxteaEncrypt);
        tolua_function(tolua_S,"getOnlineCfgValue",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getOnlineCfgValue);
        tolua_function(tolua_S,"getPlatCfgValue",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatCfgValue);
        tolua_function(tolua_S,"getDeviceModel",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDeviceModel);
        tolua_function(tolua_S,"urlEncode",lua_cocos2dx_gameplugin_auto_IETSystemUtil_urlEncode);
        tolua_function(tolua_S,"keychainGet",lua_cocos2dx_gameplugin_auto_IETSystemUtil_keychainGet);
        tolua_function(tolua_S,"getIDFV",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getIDFV);
        tolua_function(tolua_S,"getUUID",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getUUID);
        tolua_function(tolua_S,"uncompressZip",lua_cocos2dx_gameplugin_auto_IETSystemUtil_uncompressZip);
        tolua_function(tolua_S,"getSystemVersion",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getSystemVersion);
        tolua_function(tolua_S,"hideLoading",lua_cocos2dx_gameplugin_auto_IETSystemUtil_hideLoading);
        tolua_function(tolua_S,"getDebugMode",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getDebugMode);
        tolua_function(tolua_S,"getCfgValue",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCfgValue);
        tolua_function(tolua_S,"base64Encode",lua_cocos2dx_gameplugin_auto_IETSystemUtil_base64Encode);
        tolua_function(tolua_S,"getCurrentTimeMills",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getCurrentTimeMills);
        tolua_function(tolua_S,"showMessage",lua_cocos2dx_gameplugin_auto_IETSystemUtil_showMessage);
        tolua_function(tolua_S,"getAppName",lua_cocos2dx_gameplugin_auto_IETSystemUtil_getAppName);
        tolua_function(tolua_S,"copyToPasteboard",lua_cocos2dx_gameplugin_auto_IETSystemUtil_copyToPasteboard);
        tolua_function(tolua_S,"setLocalConfig", lua_cocos2dx_gameplugin_auto_IETSystemUtil_setLocalConfig);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_gameplugin_auto_IETSystemUtil_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETSystemUtil).name();
    g_luaType[typeName] = "IETSystemUtil";
    g_typeCast["IETSystemUtil"] = "IETSystemUtil";
    return 1;
}

int lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportLogs(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportLogs'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:crashReportLogs");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportLogs'", nullptr);
            return 0;
        }
        cobj->crashReportLogs(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:crashReportLogs",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportLogs'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowArchievement(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowArchievement'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowArchievement'", nullptr);
            return 0;
        }
        cobj->gcShowArchievement();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcShowArchievement",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowArchievement'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportScore(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportScore'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        std::string arg1;
        bool arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IETGamePlugin:gcReportScore");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETGamePlugin:gcReportScore");

        ok &= luaval_to_boolean(tolua_S, 4,&arg2, "IETGamePlugin:gcReportScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportScore'", nullptr);
            return 0;
        }
        cobj->gcReportScore(arg0, arg1, arg2);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcReportScore",argc, 3);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportScore'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowChallenge(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowChallenge'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowChallenge'", nullptr);
            return 0;
        }
        cobj->gcShowChallenge();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcShowChallenge",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowChallenge'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_setSuspensiveIap(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_setSuspensiveIap'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueMap arg0;

        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "IETGamePlugin:setSuspensiveIap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_setSuspensiveIap'", nullptr);
            return 0;
        }
        cobj->setSuspensiveIap(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:setSuspensiveIap",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_setSuspensiveIap'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReset(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReset'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReset'", nullptr);
            return 0;
        }
        cobj->gcReset();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcReset",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReset'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetScore(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetScore'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:gcGetScore");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetScore'", nullptr);
            return 0;
        }
        int ret = cobj->gcGetScore(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcGetScore",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetScore'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_canDoIap(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_canDoIap'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_canDoIap'", nullptr);
            return 0;
        }
        bool ret = cobj->canDoIap();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:canDoIap",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_canDoIap'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_setIapVerifyUrlAndSign(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_setIapVerifyUrlAndSign'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:setIapVerifyUrlAndSign");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETGamePlugin:setIapVerifyUrlAndSign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_setIapVerifyUrlAndSign'", nullptr);
            return 0;
        }
        cobj->setIapVerifyUrlAndSign(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:setIapVerifyUrlAndSign",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_setIapVerifyUrlAndSign'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcIsAvailable(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcIsAvailable'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcIsAvailable'", nullptr);
            return 0;
        }
        bool ret = cobj->gcIsAvailable();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcIsAvailable",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcIsAvailable'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetAchievement(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetAchievement'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:gcGetAchievement");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetAchievement'", nullptr);
            return 0;
        }
        double ret = cobj->gcGetAchievement(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcGetAchievement",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetAchievement'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportException(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportException'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::ValueVector arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:crashReportException");

        ok &= luaval_to_ccvaluevector(tolua_S, 3, &arg1, "IETGamePlugin:crashReportException");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportException'", nullptr);
            return 0;
        }
        cobj->crashReportException(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:crashReportException",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportException'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetPlayerInfo(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetPlayerInfo'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetPlayerInfo'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->gcGetPlayerInfo();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcGetPlayerInfo",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetPlayerInfo'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_getSuspensiveIap(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_getSuspensiveIap'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_getSuspensiveIap'", nullptr);
            return 0;
        }
        cocos2d::ValueMap ret = cobj->getSuspensiveIap();
        ccvaluemap_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:getSuspensiveIap",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_getSuspensiveIap'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportAchievement(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportAchievement'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:gcReportAchievement");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "IETGamePlugin:gcReportAchievement");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportAchievement'", nullptr);
            return 0;
        }
        cobj->gcReportAchievement(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcReportAchievement",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportAchievement'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowLeaderBoard(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowLeaderBoard'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowLeaderBoard'", nullptr);
            return 0;
        }
        cobj->gcShowLeaderBoard();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcShowLeaderBoard",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowLeaderBoard'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETGamePlugin_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

    tolua_Error tolua_err;

    if (!tolua_isusertable(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_getInstance'", nullptr);
            return 0;
        }
        IETGamePlugin* ret = IETGamePlugin::getInstance();
        object_to_luaval<IETGamePlugin>(tolua_S, "IETGamePlugin",(IETGamePlugin*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IETGamePlugin:getInstance",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETGamePlugin_getInstance'.",&tolua_err);
    return 0;
}
static int lua_cocos2dx_gameplugin_auto_IETGamePlugin_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IETGamePlugin)");
    return 0;
}

int lua_register_cocos2dx_gameplugin_auto_IETGamePlugin(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETGamePlugin");
    tolua_cclass(tolua_S,"IETGamePlugin","IETGamePlugin","",nullptr);

    tolua_beginmodule(tolua_S,"IETGamePlugin");
        tolua_function(tolua_S,"crashReportLogs",lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportLogs);
        tolua_function(tolua_S,"gcShowArchievement",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowArchievement);
        tolua_function(tolua_S,"gcReportScore",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportScore);
        tolua_function(tolua_S,"gcShowChallenge",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowChallenge);
        tolua_function(tolua_S,"setSuspensiveIap",lua_cocos2dx_gameplugin_auto_IETGamePlugin_setSuspensiveIap);
        tolua_function(tolua_S,"gcReset",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReset);
        tolua_function(tolua_S,"gcGetScore",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetScore);
        tolua_function(tolua_S,"canDoIap",lua_cocos2dx_gameplugin_auto_IETGamePlugin_canDoIap);
        tolua_function(tolua_S,"setIapVerifyUrlAndSign",lua_cocos2dx_gameplugin_auto_IETGamePlugin_setIapVerifyUrlAndSign);
        tolua_function(tolua_S,"gcIsAvailable",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcIsAvailable);
        tolua_function(tolua_S,"gcGetAchievement",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetAchievement);
        tolua_function(tolua_S,"crashReportException",lua_cocos2dx_gameplugin_auto_IETGamePlugin_crashReportException);
        tolua_function(tolua_S,"gcGetPlayerInfo",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcGetPlayerInfo);
        tolua_function(tolua_S,"getSuspensiveIap",lua_cocos2dx_gameplugin_auto_IETGamePlugin_getSuspensiveIap);
        tolua_function(tolua_S,"gcReportAchievement",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcReportAchievement);
        tolua_function(tolua_S,"gcShowLeaderBoard",lua_cocos2dx_gameplugin_auto_IETGamePlugin_gcShowLeaderBoard);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_gameplugin_auto_IETGamePlugin_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETGamePlugin).name();
    g_luaType[typeName] = "IETGamePlugin";
    g_typeCast["IETGamePlugin"] = "IETGamePlugin";
    return 1;
}

int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_hideBannerAd(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_hideBannerAd'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_hideBannerAd'", nullptr);
            return 0;
        }
        cobj->hideBannerAd();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:hideBannerAd",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_hideBannerAd'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_showBannerAd(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_showBannerAd'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        bool arg0;
        bool arg1;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "IETAdvertiseHelper:showBannerAd");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "IETAdvertiseHelper:showBannerAd");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_showBannerAd'", nullptr);
            return 0;
        }
        int ret = cobj->showBannerAd(arg0, arg1);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:showBannerAd",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_showBannerAd'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setVideoAdNames(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setVideoAdNames'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueVector arg0;

        ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "IETAdvertiseHelper:setVideoAdNames");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setVideoAdNames'", nullptr);
            return 0;
        }
        cobj->setVideoAdNames(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:setVideoAdNames",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setVideoAdNames'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setBannerAdName(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setBannerAdName'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAdvertiseHelper:setBannerAdName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setBannerAdName'", nullptr);
            return 0;
        }
        cobj->setBannerAdName(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:setBannerAdName",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setBannerAdName'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isSpotAdReady(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isSpotAdReady'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isSpotAdReady'", nullptr);
            return 0;
        }
        bool ret = cobj->isSpotAdReady();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:isSpotAdReady",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isSpotAdReady'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setSpotAdNames(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setSpotAdNames'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueVector arg0;

        ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "IETAdvertiseHelper:setSpotAdNames");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setSpotAdNames'", nullptr);
            return 0;
        }
        cobj->setSpotAdNames(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:setSpotAdNames",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setSpotAdNames'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isVedioReady(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isVedioReady'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isVedioReady'", nullptr);
            return 0;
        }
        bool ret = cobj->isVedioReady();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:isVedioReady",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isVedioReady'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

    tolua_Error tolua_err;

    if (!tolua_isusertable(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_getInstance'", nullptr);
            return 0;
        }
        IETAdvertiseHelper* ret = IETAdvertiseHelper::getInstance();
        object_to_luaval<IETAdvertiseHelper>(tolua_S, "IETAdvertiseHelper",(IETAdvertiseHelper*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IETAdvertiseHelper:getInstance",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_getInstance'.",&tolua_err);
    return 0;
}
static int lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IETAdvertiseHelper)");
    return 0;
}

int lua_register_cocos2dx_gameplugin_auto_IETAdvertiseHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETAdvertiseHelper");
    tolua_cclass(tolua_S,"IETAdvertiseHelper","IETAdvertiseHelper","",nullptr);

    tolua_beginmodule(tolua_S,"IETAdvertiseHelper");
        tolua_function(tolua_S,"hideBannerAd",lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_hideBannerAd);
        tolua_function(tolua_S,"showBannerAd",lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_showBannerAd);
        tolua_function(tolua_S,"setVideoAdNames",lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setVideoAdNames);
        tolua_function(tolua_S,"setBannerAdName",lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setBannerAdName);
        tolua_function(tolua_S,"isSpotAdReady",lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isSpotAdReady);
        tolua_function(tolua_S,"setSpotAdNames",lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_setSpotAdNames);
        tolua_function(tolua_S,"isVedioReady",lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isVedioReady);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_gameplugin_auto_IETAdvertiseHelper_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETAdvertiseHelper).name();
    g_luaType[typeName] = "IETAdvertiseHelper";
    g_typeCast["IETAdvertiseHelper"] = "IETAdvertiseHelper";
    return 1;
}

int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_purchase(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_purchase'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:purchase");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "IETAnalyticHelper:purchase");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "IETAnalyticHelper:purchase");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_purchase'", nullptr);
            return 0;
        }
        cobj->purchase(arg0, arg1, arg2);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:purchase",argc, 3);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_purchase'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_use(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_use'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        int arg1;
        double arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:use");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "IETAnalyticHelper:use");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "IETAnalyticHelper:use");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_use'", nullptr);
            return 0;
        }
        cobj->use(arg0, arg1, arg2);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:use",argc, 3);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_use'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionStart(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionStart'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:missionStart");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionStart'", nullptr);
            return 0;
        }
        cobj->missionStart(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:missionStart",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionStart'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionFailed(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionFailed'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:missionFailed");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETAnalyticHelper:missionFailed");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionFailed'", nullptr);
            return 0;
        }
        cobj->missionFailed(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:missionFailed",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionFailed'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setLevel(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setLevel'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IETAnalyticHelper:setLevel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setLevel'", nullptr);
            return 0;
        }
        cobj->setLevel(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:setLevel",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setLevel'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_charge(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_charge'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        std::string arg0;
        double arg1;
        double arg2;
        int arg3;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:charge");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "IETAnalyticHelper:charge");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "IETAnalyticHelper:charge");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "IETAnalyticHelper:charge");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_charge'", nullptr);
            return 0;
        }
        cobj->charge(arg0, arg1, arg2, arg3);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:charge",argc, 4);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_charge'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_onEvent(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;
    tolua_Error tolua_err;

    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;
    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_onEvent'", nullptr);
        return 0;
    }
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:onEvent");

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETAnalyticHelper:onEvent");

            if (!ok) { break; }
            cobj->onEvent(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:onEvent");

            if (!ok) { break; }
            cobj->onEvent(arg0);
            return 0;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:onEvent");

            if (!ok) { break; }
            cocos2d::ValueMap arg1;
            ok &= luaval_to_ccvaluemap(tolua_S, 3, &arg1, "IETAnalyticHelper:onEvent");

            if (!ok) { break; }
            cobj->onEvent(arg0, arg1);
            return 0;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "IETAnalyticHelper:onEvent",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_onEvent'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setAccountInfo(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setAccountInfo'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::ValueMap arg0;

        ok &= luaval_to_ccvaluemap(tolua_S, 2, &arg0, "IETAnalyticHelper:setAccountInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setAccountInfo'", nullptr);
            return 0;
        }
        cobj->setAccountInfo(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:setAccountInfo",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setAccountInfo'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_reward(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_reward'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        int arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "IETAnalyticHelper:reward");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "IETAnalyticHelper:reward");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_reward'", nullptr);
            return 0;
        }
        cobj->reward(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:reward",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_reward'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionSuccess(lua_State* tolua_S)
{
    int argc = 0;
    IETAnalyticHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAnalyticHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionSuccess'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAnalyticHelper:missionSuccess");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionSuccess'", nullptr);
            return 0;
        }
        cobj->missionSuccess(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAnalyticHelper:missionSuccess",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionSuccess'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

    tolua_Error tolua_err;

    if (!tolua_isusertable(tolua_S,1,"IETAnalyticHelper",0,&tolua_err)) goto tolua_lerror;

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_getInstance'", nullptr);
            return 0;
        }
        IETAnalyticHelper* ret = IETAnalyticHelper::getInstance();
        object_to_luaval<IETAnalyticHelper>(tolua_S, "IETAnalyticHelper",(IETAnalyticHelper*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IETAnalyticHelper:getInstance",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_getInstance'.",&tolua_err);
    return 0;
}
static int lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IETAnalyticHelper)");
    return 0;
}

int lua_register_cocos2dx_gameplugin_auto_IETAnalyticHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETAnalyticHelper");
    tolua_cclass(tolua_S,"IETAnalyticHelper","IETAnalyticHelper","",nullptr);

    tolua_beginmodule(tolua_S,"IETAnalyticHelper");
        tolua_function(tolua_S,"purchase",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_purchase);
        tolua_function(tolua_S,"use",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_use);
        tolua_function(tolua_S,"missionStart",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionStart);
        tolua_function(tolua_S,"missionFailed",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionFailed);
        tolua_function(tolua_S,"setLevel",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setLevel);
        tolua_function(tolua_S,"charge",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_charge);
        tolua_function(tolua_S,"onEvent",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_onEvent);
        tolua_function(tolua_S,"setAccountInfo",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_setAccountInfo);
        tolua_function(tolua_S,"reward",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_reward);
        tolua_function(tolua_S,"missionSuccess",lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_missionSuccess);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_gameplugin_auto_IETAnalyticHelper_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETAnalyticHelper).name();
    g_luaType[typeName] = "IETAnalyticHelper";
    g_typeCast["IETAnalyticHelper"] = "IETAnalyticHelper";
    return 1;
}

int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_setLevel(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_setLevel'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IETFacebookHelper:setLevel");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_setLevel'", nullptr);
            return 0;
        }
        cobj->setLevel(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:setLevel",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_setLevel'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getUserID(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getUserID'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getUserID'", nullptr);
            return 0;
        }
        std::string ret = cobj->getUserID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:getUserID",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getUserID'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_isLogin(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_isLogin'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_isLogin'", nullptr);
            return 0;
        }
        bool ret = cobj->isLogin();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:isLogin",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_isLogin'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_logout(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_logout'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_logout'", nullptr);
            return 0;
        }
        cobj->logout();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:logout",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_logout'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_login(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_login'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_login'", nullptr);
            return 0;
        }
        cobj->login();
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:login",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_login'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_openFacebookPage(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_openFacebookPage'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETFacebookHelper:openFacebookPage");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETFacebookHelper:openFacebookPage");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_openFacebookPage'", nullptr);
            return 0;
        }
        cobj->openFacebookPage(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:openFacebookPage",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_openFacebookPage'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getAccessToken(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getAccessToken'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getAccessToken'", nullptr);
            return 0;
        }
        std::string ret = cobj->getAccessToken();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:getAccessToken",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getAccessToken'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

    tolua_Error tolua_err;

    if (!tolua_isusertable(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getInstance'", nullptr);
            return 0;
        }
        IETFacebookHelper* ret = IETFacebookHelper::getInstance();
        object_to_luaval<IETFacebookHelper>(tolua_S, "IETFacebookHelper",(IETFacebookHelper*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IETFacebookHelper:getInstance",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getInstance'.",&tolua_err);
    return 0;
}
static int lua_cocos2dx_gameplugin_auto_IETFacebookHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IETFacebookHelper)");
    return 0;
}

int lua_register_cocos2dx_gameplugin_auto_IETFacebookHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETFacebookHelper");
    tolua_cclass(tolua_S,"IETFacebookHelper","IETFacebookHelper","",nullptr);

    tolua_beginmodule(tolua_S,"IETFacebookHelper");
        tolua_function(tolua_S,"setLevel",lua_cocos2dx_gameplugin_auto_IETFacebookHelper_setLevel);
        tolua_function(tolua_S,"getUserID",lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getUserID);
        tolua_function(tolua_S,"isLogin",lua_cocos2dx_gameplugin_auto_IETFacebookHelper_isLogin);
        tolua_function(tolua_S,"logout",lua_cocos2dx_gameplugin_auto_IETFacebookHelper_logout);
        tolua_function(tolua_S,"login",lua_cocos2dx_gameplugin_auto_IETFacebookHelper_login);
        tolua_function(tolua_S,"openFacebookPage",lua_cocos2dx_gameplugin_auto_IETFacebookHelper_openFacebookPage);
        tolua_function(tolua_S,"getAccessToken",lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getAccessToken);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_gameplugin_auto_IETFacebookHelper_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETFacebookHelper).name();
    g_luaType[typeName] = "IETFacebookHelper";
    g_typeCast["IETFacebookHelper"] = "IETFacebookHelper";
    return 1;
}

int lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_connectFb(lua_State* tolua_S)
{
    int argc = 0;
    IETAmazonAWSHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAmazonAWSHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAmazonAWSHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_connectFb'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETAmazonAWSHelper:connectFb");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_connectFb'", nullptr);
            return 0;
        }
        cobj->connectFb(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAmazonAWSHelper:connectFb",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_connectFb'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getUserId(lua_State* tolua_S)
{
    int argc = 0;
    IETAmazonAWSHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAmazonAWSHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAmazonAWSHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getUserId'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getUserId'", nullptr);
            return 0;
        }
        std::string ret = cobj->getUserId();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAmazonAWSHelper:getUserId",argc, 0);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getUserId'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

    tolua_Error tolua_err;

    if (!tolua_isusertable(tolua_S,1,"IETAmazonAWSHelper",0,&tolua_err)) goto tolua_lerror;

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getInstance'", nullptr);
            return 0;
        }
        IETAmazonAWSHelper* ret = IETAmazonAWSHelper::getInstance();
        object_to_luaval<IETAmazonAWSHelper>(tolua_S, "IETAmazonAWSHelper",(IETAmazonAWSHelper*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IETAmazonAWSHelper:getInstance",argc, 0);
    return 0;
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getInstance'.",&tolua_err);
    return 0;
}
static int lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (IETAmazonAWSHelper)");
    return 0;
}

int lua_register_cocos2dx_gameplugin_auto_IETAmazonAWSHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETAmazonAWSHelper");
    tolua_cclass(tolua_S,"IETAmazonAWSHelper","IETAmazonAWSHelper","",nullptr);

    tolua_beginmodule(tolua_S,"IETAmazonAWSHelper");
        tolua_function(tolua_S,"connectFb",lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_connectFb);
        tolua_function(tolua_S,"getUserId",lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getUserId);
        tolua_function(tolua_S,"getInstance", lua_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETAmazonAWSHelper).name();
    g_luaType[typeName] = "IETAmazonAWSHelper";
    g_typeCast["IETAmazonAWSHelper"] = "IETAmazonAWSHelper";
    return 1;
}
TOLUA_API int register_all_cocos2dx_gameplugin_auto(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ccg",0);
	tolua_beginmodule(tolua_S,"ccg");

	lua_register_cocos2dx_gameplugin_auto_IETGamePlugin(tolua_S);
	lua_register_cocos2dx_gameplugin_auto_IETAdvertiseHelper(tolua_S);
	lua_register_cocos2dx_gameplugin_auto_IETSystemUtil(tolua_S);
	lua_register_cocos2dx_gameplugin_auto_IETFacebookHelper(tolua_S);
	lua_register_cocos2dx_gameplugin_auto_IETAnalyticHelper(tolua_S);
	lua_register_cocos2dx_gameplugin_auto_IETAmazonAWSHelper(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

