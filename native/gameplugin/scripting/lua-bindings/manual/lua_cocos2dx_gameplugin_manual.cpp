#include "lua_cocos2dx_gameplugin_manual.hpp"
#include "IETGamePluginConfig.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"
#include "CCLuaEngine.h"
#include "CCLuaStack.h"
#include "CCLuaValue.h"

using namespace std;

#pragma mark - IETSystemUtil
int lua_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S) - 1;
    if (argc == 4)
    {
        std::string arg0;
        std::string arg1;
        cocos2d::ValueMap arg2;
        std::function<void (bool, std::basic_string<char>)> arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:requestUrl");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETSystemUtil:requestUrl");
        ok &= luaval_to_ccvaluemap(tolua_S, 4, &arg2, "IETSystemUtil:requestUrl");
        do {
            // Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 5, 0);
            arg3 = [=](bool b, std::basic_string<char> str){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(b);
                stack->pushString(str.c_str());
                stack->executeFunctionByHandler(func, 2);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl'", nullptr);
            return 0;
        }
        cobj->requestUrl(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "IETSystemUtil:requestUrl",argc, 4);
    return 0;
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl'.",&tolua_err);
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2)
    {
        std::string arg0;
        std::function<void ()> arg1;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:syncGameConfig");
        
        do {
            // Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 3, 0);
            arg1 = [=](){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->executeFunctionByHandler(func, 0);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig'", nullptr);
            return 0;
        }
        cobj->syncGameConfig(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:syncGameConfig",argc, 1);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);

    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::function<void (int, int)> arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:downloadFile");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETSystemUtil:downloadFile");

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 4, 0);
            arg2 = [=](int first, int second) {
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushInt(first);
                stack->pushInt(second);
                stack->executeFunctionByHandler(func, 2);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile'", nullptr);
            return 0;
        }
        cobj->downloadFile(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:downloadFile",argc, 3);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETSystemUtil_showAlertDialog(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_showAlertDialog'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 5)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        cocos2d::ValueVector arg3;
        std::function<void (int)> arg4;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:showAlertDialog");
        
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETSystemUtil:showAlertDialog");
        
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "IETSystemUtil:showAlertDialog");
        
        ok &= luaval_to_ccvaluevector(tolua_S, 5, &arg3, "IETSystemUtil:showAlertDialog");
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 6, 0);
            arg4 = [=](int i){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushInt(i);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_showAlertDialog'", nullptr);
            return 0;
        }
        cobj->showAlertDialog(arg0, arg1, arg2, arg3, arg4);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:showAlertDialog",argc, 5);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_showAlertDialog'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETSystemUtil_saveImage(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_saveImage'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        std::function<void (bool, std::basic_string<char>)> arg2;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:saveImage");
        
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETSystemUtil:saveImage");
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 4, 0);
            arg2 = [=](bool b, std::string str){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(b);
                stack->pushString(str.c_str());
                stack->executeFunctionByHandler(func, 2);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_saveImage'", nullptr);
            return 0;
        }
        cobj->saveImage(arg0, arg1, arg2);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:saveImage",argc, 3);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_saveImage'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETSystemUtil_sendEmail(lua_State* tolua_S)
{
    int argc = 0;
    IETSystemUtil* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETSystemUtil",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETSystemUtil*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_sendEmail'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 4)
    {
        std::string arg0;
        cocos2d::ValueVector arg1;
        std::string arg2;
        std::function<void (bool, std::basic_string<char>)> arg3;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETSystemUtil:sendEmail");
        
        ok &= luaval_to_ccvaluevector(tolua_S, 3, &arg1, "IETSystemUtil:sendEmail");
        
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "IETSystemUtil:sendEmail");
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 5, 0);
            arg3 = [=](bool b, std::string str){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(b);
                stack->pushString(str.c_str());
                stack->executeFunctionByHandler(func, 2);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_sendEmail'", nullptr);
            return 0;
        }
        cobj->sendEmail(arg0, arg1, arg2, arg3);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETSystemUtil:sendEmail",argc, 4);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETSystemUtil_sendEmail'.",&tolua_err);
    
    return 0;
}
int lua_register_cocos2dx_gameplugin_manual_IETSystemUtil(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETSystemUtil");
    tolua_cclass(tolua_S,"IETSystemUtil","IETSystemUtil","",nullptr);
    tolua_beginmodule(tolua_S,"IETSystemUtil");
    {
        tolua_function(tolua_S,"requestUrl", lua_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl);
        tolua_function(tolua_S,"syncGameConfig",lua_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig);
        tolua_function(tolua_S,"downloadFile",lua_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile);
        tolua_function(tolua_S,"showAlertDialog",lua_cocos2dx_gameplugin_manual_IETSystemUtil_showAlertDialog);
        tolua_function(tolua_S,"saveImage",lua_cocos2dx_gameplugin_manual_IETSystemUtil_saveImage);
        tolua_function(tolua_S,"sendEmail",lua_cocos2dx_gameplugin_manual_IETSystemUtil_sendEmail);
    }
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETSystemUtil).name();
    g_luaType[typeName] = "IETSystemUtil";
    g_typeCast["IETSystemUtil"] = "IETSystemUtil";
    return 1;
}

#pragma mark - IETGamePlugin
int lua_cocos2dx_gameplugin_manual_IETGamePlugin_setNotifyHandler(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_setNotifyHandler'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::function<void (cocos2d::ValueMap)> arg0;
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](cocos2d::ValueMap map){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluemap_to_luaval(stack->getLuaState(), map);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_setNotifyHandler'", nullptr);
            return 0;
        }
        cobj->setNotifyHandler(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:setNotifyHandler",argc, 1);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_setNotifyHandler'.",&tolua_err);
    
    return 0;
}
std::function<void (int, std::string)> _iapVerifyCallback;
int iapVerifyCallback(lua_State* tolua_S)
{
    int arg0;
    std::string arg1;
    luaval_to_int32(tolua_S, 1,(int *)&arg0, "iapVerifyCallback");
    luaval_to_std_string(tolua_S, 2,&arg1, "iapVerifyCallback");
    if (_iapVerifyCallback) {
        _iapVerifyCallback(arg0, arg1);
    }
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETGamePlugin_doIap(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_doIap'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        std::function<void (bool, std::basic_string<char>)> arg2;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:doIap");
        
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETGamePlugin:doIap");
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 4, 0);
            arg2 = [=](bool b, std::basic_string<char> str){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(b);
                stack->pushString(str.c_str());
                stack->executeFunctionByHandler(func, 2);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_doIap'", nullptr);
            return 0;
        }
        cobj->doIap(arg0, arg1, arg2);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:doIap",argc, 3);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_doIap'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerFriends(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerFriends'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::function<void (std::vector<cocos2d::Value, std::allocator<cocos2d::Value> >)> arg0;
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](cocos2d::ValueVector vec){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluevector_to_luaval(stack->getLuaState(), vec);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerFriends'", nullptr);
            return 0;
        }
        cobj->gcGetPlayerFriends(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcGetPlayerFriends",argc, 1);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerFriends'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerAvatarWithId(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerAvatarWithId'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2)
    {
        std::string arg0;
        std::function<void (std::basic_string<char>)> arg1;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:gcGetPlayerAvatarWithId");
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 3, 0);
            arg1 = [=](std::string str){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushString(str.c_str());
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerAvatarWithId'", nullptr);
            return 0;
        }
        cobj->gcGetPlayerAvatarWithId(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcGetPlayerAvatarWithId",argc, 2);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerAvatarWithId'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithIds(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithIds'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2)
    {
        cocos2d::ValueVector arg0;
        std::function<void (std::vector<cocos2d::Value, std::allocator<cocos2d::Value> >)> arg1;
        
        ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "IETGamePlugin:gcGetPlayerInfoWithIds");
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 3, 0);
            arg1 = [=](cocos2d::ValueVector vec){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluevector_to_luaval(stack->getLuaState(), vec);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithIds'", nullptr);
            return 0;
        }
        cobj->gcGetPlayerInfoWithIds(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcGetPlayerInfoWithIds",argc, 2);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithIds'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithId(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithId'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 2)
    {
        std::string arg0;
        std::function<void (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg1;
        
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETGamePlugin:gcGetPlayerInfoWithId");
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 3, 0);
            arg1 = [=](cocos2d::ValueMap map){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluemap_to_luaval(stack->getLuaState(), map);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithId'", nullptr);
            return 0;
        }
        cobj->gcGetPlayerInfoWithId(arg0, arg1);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcGetPlayerInfoWithId",argc, 2);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithId'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetChallenges(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetChallenges'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::function<void (std::vector<cocos2d::Value, std::allocator<cocos2d::Value> >)> arg0;
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](cocos2d::ValueVector vec){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluevector_to_luaval(stack->getLuaState(), vec);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetChallenges'", nullptr);
            return 0;
        }
        cobj->gcGetChallenges(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:gcGetChallenges",argc, 1);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetChallenges'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETGamePlugin_setPromotionHandler(lua_State* tolua_S)
{
    int argc = 0;
    IETGamePlugin* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETGamePlugin",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETGamePlugin*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_setPromotionHandler'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::function<void (std::vector<cocos2d::Value, std::allocator<cocos2d::Value> >)> arg0;
        
        do {
            // Lambda binding for lua is not supported.
            // assert(false);
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](cocos2d::ValueVector vec){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluevector_to_luaval(stack->getLuaState(), vec);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_setPromotionHandler'", nullptr);
            return 0;
        }
        cobj->setPromotionHandler(arg0);
        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETGamePlugin:setPromotionHandler",argc, 1);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETGamePlugin_setPromotionHandler'.",&tolua_err);
    
    return 0;
}

int lua_register_cocos2dx_gameplugin_manual_IETGamePlugin(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETGamePlugin");
    tolua_cclass(tolua_S,"IETGamePlugin","IETGamePlugin","",nullptr);

    tolua_beginmodule(tolua_S,"IETGamePlugin");
    {
        tolua_function(tolua_S,"setNotifyHandler",lua_cocos2dx_gameplugin_manual_IETGamePlugin_setNotifyHandler);
        tolua_function(tolua_S,"doIap",lua_cocos2dx_gameplugin_manual_IETGamePlugin_doIap);
        tolua_function(tolua_S,"gcGetPlayerFriends",lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerFriends);
        tolua_function(tolua_S,"gcGetPlayerAvatarWithId",lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerAvatarWithId);
        tolua_function(tolua_S,"gcGetPlayerInfoWithIds",lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithIds);
        tolua_function(tolua_S,"gcGetPlayerInfoWithId",lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetPlayerInfoWithId);
        tolua_function(tolua_S,"gcGetChallenges",lua_cocos2dx_gameplugin_manual_IETGamePlugin_gcGetChallenges);
        tolua_function(tolua_S,"setPromotionHandler",lua_cocos2dx_gameplugin_manual_IETGamePlugin_setPromotionHandler);
    }
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETGamePlugin).name();
    g_luaType[typeName] = "IETGamePlugin";
    g_typeCast["IETGamePlugin"] = "IETGamePlugin";
    return 1;
}

#pragma mark - IETAdvertiseHelper

int lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;
    
    tolua_Error tolua_err;
    
    
    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;
    
    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);
    
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd'", nullptr);
        return 0;
    }
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        std::function<void (bool)> arg0;
        
        do {
            // Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](bool b){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(b);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
            ;
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd'", nullptr);
            return 0;
        }
        bool ret = cobj->showSpotAd(arg0);
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:showSpotAd",argc, 1);
    return 0;
    
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd'.",&tolua_err);
    
    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd(lua_State* tolua_S)
{
    int argc = 0;
    IETAdvertiseHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETAdvertiseHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETAdvertiseHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2)
    {
        std::function<void (bool)> arg0;
        std::function<void (bool)> arg1;

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](bool b){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(b);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        
        do {
            // Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 3, 0);
            arg1 = [=](bool b){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(b);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
        ;
        
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd'", nullptr);
            return 0;
        }
        bool ret = cobj->showVedioAd(arg0, arg1);
        tolua_pushboolean(tolua_S, (bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETAdvertiseHelper:showVedioAd",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd'.",&tolua_err);

    return 0;
}
int lua_register_cocos2dx_gameplugin_manual_IETAdvertiseHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETAdvertiseHelper");
    tolua_cclass(tolua_S,"IETAdvertiseHelper","IETAdvertiseHelper","",nullptr);

    tolua_beginmodule(tolua_S,"IETAdvertiseHelper");
    {
        tolua_function(tolua_S,"showSpotAd",lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd);
        tolua_function(tolua_S,"showVedioAd",lua_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd);
    }
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETAdvertiseHelper).name();
    g_luaType[typeName] = "IETAdvertiseHelper";
    g_typeCast["IETAdvertiseHelper"] = "IETAdvertiseHelper";
    return 1;
}

#pragma mark - IETAnalyticHelper
int lua_register_cocos2dx_gameplugin_manual_IETAnalyticHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETAnalyticHelper");
    tolua_cclass(tolua_S,"IETAnalyticHelper","IETAnalyticHelper","",nullptr);

    tolua_beginmodule(tolua_S,"IETAnalyticHelper");
    
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETAnalyticHelper).name();
    g_luaType[typeName] = "IETAnalyticHelper";
    g_typeCast["IETAnalyticHelper"] = "IETAnalyticHelper";
    return 1;
}

#pragma mark - IETFacebookHelper
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3)
    {
        cocos2d::ValueVector arg0;
        int arg1;
        std::function<void(cocos2d::ValueMap)> arg2;

        ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "IETFacebookHelper:getInvitableFriends");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "IETSystemUtil:getInvitableFriends");
        
        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 4, 0);
            arg2 = [=](cocos2d::ValueMap vec){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluemap_to_luaval(stack->getLuaState(), vec);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends'", nullptr);
            return 0;
        }
        cobj->getInvitableFriends(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:getInvitableFriends",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (cocos2d::ValueMap)> arg0;

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](cocos2d::ValueMap vec){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluemap_to_luaval(stack->getLuaState(), vec);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest'", nullptr);
            return 0;
        }
        cobj->queryRequest(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:queryRequest",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_inviteFriend(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_inviteFriend'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        std::function<void (bool)> arg2;


        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETFacebookHelper:inviteFriend");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETFacebookHelper:inviteFriend");

        do {
            // Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 4, 0);
            arg2 = [=](bool b){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(b);
                stack->executeFunctionByHandler(func, 1);
            };
        } while(0)
        ;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_inviteFriend'", nullptr);
            return 0;
        }
        cobj->inviteFriend(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:inviteFriend",argc, 4);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_inviteFriend'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        cocos2d::ValueVector arg0;
        std::string arg1;
        std::string arg2;
        std::function<void (cocos2d::ValueMap)> arg3;

        ok &= luaval_to_ccvaluevector(tolua_S, 2, &arg0, "IETFacebookHelper:confirmRequest");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETFacebookHelper:confirmRequest");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "IETFacebookHelper:confirmRequest");

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 5, 0);
            arg3 = [=](cocos2d::ValueMap map){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluemap_to_luaval(stack->getLuaState(), map);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest'", nullptr);
            return 0;
        }
        cobj->confirmRequest(arg0, arg1, arg2, arg3);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:confirmRequest",argc, 4);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void (std::basic_string<char>, std::basic_string<char>)> arg0;

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](std::basic_string<char> fid, std::basic_string<char> token){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushString(fid.c_str());
                stack->pushString(token.c_str());
                stack->executeFunctionByHandler(func, 2);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc'", nullptr);
            return 0;
        }
        cobj->setLoginFunc(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:setLoginFunc",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_share(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_share'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 6) 
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        std::function<void (bool)> arg5;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETFacebookHelper:share");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "IETFacebookHelper:share");

        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "IETFacebookHelper:share");

        ok &= luaval_to_std_string(tolua_S, 5,&arg3, "IETFacebookHelper:share");

        ok &= luaval_to_std_string(tolua_S, 6,&arg4, "IETFacebookHelper:share");

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 7, 0);
            arg5 = [=](bool result){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(result);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_share'", nullptr);
            return 0;
        }
        cobj->share(arg0, arg1, arg2, arg3, arg4, arg5);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:share",argc, 6);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_share'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2)
    {
        int arg0;
        std::function<void (cocos2d::ValueMap)> arg1;
        
        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "IETSystemUtil:getFriends");
        
        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 3, 0);
            arg1 = [=](cocos2d::ValueMap vec){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluemap_to_luaval(stack->getLuaState(), vec);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends'", nullptr);
            return 0;
        }
        cobj->getFriends(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:getFriends",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::function<void (bool)> arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETFacebookHelper:acceptRequest");

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 3, 0);
            arg1 = [=](bool result){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushBoolean(result);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest'", nullptr);
            return 0;
        }
        cobj->acceptRequest(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:acceptRequest",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::function<void(cocos2d::ValueMap)> arg0;

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 2, 0);
            arg0 = [=](cocos2d::ValueMap map){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluemap_to_luaval(stack->getLuaState(), map);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc'", nullptr);
            return 0;
        }
        cobj->setAppLinkFunc(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:setAppLinkFunc",argc, 1);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::function<void (int)> arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETFacebookHelper:getLevel");

        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 3, 0);
            arg1 = [=](int i){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                stack->pushInt(i);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel'", nullptr);
            return 0;
        }
        cobj->getLevel(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:getLevel",argc, 2);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel'.",&tolua_err);

    return 0;
}
int lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile(lua_State* tolua_S)
{
    int argc = 0;
    IETFacebookHelper* cobj = nullptr;
    bool ok  = true;

    tolua_Error tolua_err;


    if (!tolua_isusertype(tolua_S,1,"IETFacebookHelper",0,&tolua_err)) goto tolua_lerror;

    cobj = (IETFacebookHelper*)tolua_tousertype(tolua_S,1,0);

    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile'", nullptr);
        return 0;
    }

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3)
    {
        std::string arg0;
        int arg1;
        std::function<void (cocos2d::ValueMap)> arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "IETFacebookHelper:getUserProfile");
        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "IETSystemUtil:getUserProfile");
        
        do {
			// Lambda binding for lua is not supported.
            LUA_FUNCTION func = toluafix_ref_function(tolua_S, 4, 0);
            arg2 = [=](cocos2d::ValueMap map){
                LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
                ccvaluemap_to_luaval(stack->getLuaState(), map);
                stack->executeFunctionByHandler(func, 1);
            };
		} while(0)
		;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile'", nullptr);
            return 0;
        }
        cobj->getUserProfile(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "IETFacebookHelper:getUserProfile",argc, 3);
    return 0;

    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile'.",&tolua_err);

    return 0;
}
int lua_register_cocos2dx_gameplugin_manual_IETFacebookHelper(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"IETFacebookHelper");
    tolua_cclass(tolua_S,"IETFacebookHelper","IETFacebookHelper","",nullptr);

    tolua_beginmodule(tolua_S,"IETFacebookHelper");
        tolua_function(tolua_S,"getInvitableFriends",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends);
        tolua_function(tolua_S,"queryRequest",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest);
        tolua_function(tolua_S,"confirmRequest",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest);
        tolua_function(tolua_S,"setLoginFunc",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc);
        tolua_function(tolua_S,"share",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_share);
        tolua_function(tolua_S,"getFriends",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends);
        tolua_function(tolua_S,"acceptRequest",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest);
        tolua_function(tolua_S,"setAppLinkFunc",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc);
        tolua_function(tolua_S,"getLevel",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel);
        tolua_function(tolua_S,"getUserProfile",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile);
        tolua_function(tolua_S,"inviteFriend",lua_cocos2dx_gameplugin_manual_IETFacebookHelper_inviteFriend);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(IETFacebookHelper).name();
    g_luaType[typeName] = "IETFacebookHelper";
    g_typeCast["IETFacebookHelper"] = "IETFacebookHelper";
    return 1;
}
#pragma mark - register all
TOLUA_API int register_all_cocos2dx_gameplugin_manual(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"ccg",0);
	tolua_beginmodule(tolua_S,"ccg");

	lua_register_cocos2dx_gameplugin_manual_IETGamePlugin(tolua_S);
	lua_register_cocos2dx_gameplugin_manual_IETAdvertiseHelper(tolua_S);
	lua_register_cocos2dx_gameplugin_manual_IETSystemUtil(tolua_S);
	lua_register_cocos2dx_gameplugin_manual_IETAnalyticHelper(tolua_S);
	lua_register_cocos2dx_gameplugin_manual_IETFacebookHelper(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

