#include "jsb_cocos2dx_gameplugin_manual.hpp"
#include "cocos2d_specifics.hpp"
#include "IETGamePluginConfig.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    JS::RootedObject global(cx, ScriptingCore::getInstance()->getGlobalObject());
    isNewValid = JS_GetProperty(cx, global, "initializing", &initializing) && initializing.toBoolean();
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    JS_ReportError(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;    
}
JSClass  *jsb_IETSystemUtil_class;
JSObject *jsb_IETSystemUtil_prototype;

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_isSalePromotionValid(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isSalePromotionValid : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isSalePromotionValid();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isSalePromotionValid : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_isRedirectGameValid(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isRedirectGameValid : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isRedirectGameValid();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isRedirectGameValid : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewBuildDialog(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewBuildDialog : Invalid Native Object");
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewBuildDialog : Error processing arguments");
        cobj->showNewBuildDialog(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewBuildDialog : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getOnLineValue(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getOnLineValue : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getOnLineValue : Error processing arguments");
        cocos2d::Value ret = cobj->getOnLineValue(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = ccvalue_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getOnLineValue : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_showRedirectGameDialog(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showRedirectGameDialog : Invalid Native Object");
    if (argc == 0) {
        cobj->showRedirectGameDialog();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showRedirectGameDialog : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getBuildPath(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getBuildPath : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getBuildPath();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getBuildPath : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile : Invalid Native Object");
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::function<void (int, int)> arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        do {
		    if(JS_TypeOfValue(cx, args.get(2)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(2)));
		        auto lambda = [=](int larg0, int larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[2];
		            largv[0] = int32_to_jsval(cx, larg0);
		            largv[1] = int32_to_jsval(cx, larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg2 = lambda;
		    }
		    else
		    {
		        arg2 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile : Error processing arguments");
        cobj->downloadFile(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getValue(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getValue : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getValue : Error processing arguments");
        cocos2d::Value ret = cobj->getValue(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = ccvalue_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getValue : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_showSalePromotionDialog(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showSalePromotionDialog : Invalid Native Object");
    if (argc == 1) {
        std::function<void (std::basic_string<char>, int, int)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](std::basic_string<char> larg0, int larg1, int larg2) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[3];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = int32_to_jsval(cx, larg1);
		            largv[2] = int32_to_jsval(cx, larg2);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(3, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showSalePromotionDialog : Error processing arguments");
        cobj->showSalePromotionDialog(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showSalePromotionDialog : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewVersionValid(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewVersionValid : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isNewVersionValid();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewVersionValid : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig : Invalid Native Object");
    if (argc == 1) {
        std::function<void ()> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=]() -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(0, nullptr, &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig : Error processing arguments");
        cobj->syncGameConfig(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getLocalValue(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getLocalValue : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getLocalValue : Error processing arguments");
        cocos2d::Value ret = cobj->getLocalValue(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = ccvalue_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getLocalValue : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewBuildValid(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewBuildValid : Invalid Native Object");
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewBuildValid : Error processing arguments");
        bool ret = cobj->isNewBuildValid(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewBuildValid : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_checkVersionBuild(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_checkVersionBuild : Invalid Native Object");
    if (argc == 2) {
        int arg0;
        std::function<void ()> arg1;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(1)));
		        auto lambda = [=]() -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(0, nullptr, &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_checkVersionBuild : Error processing arguments");
        cobj->checkVersionBuild(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_checkVersionBuild : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewVersionDialog(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETSystemUtil* cobj = (IETSystemUtil *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewVersionDialog : Invalid Native Object");
    if (argc == 0) {
        cobj->showNewVersionDialog();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewVersionDialog : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_urlEncode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_urlEncode : Error processing arguments");
        std::string ret = IETSystemUtil::urlEncode(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_urlEncode : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETSystemUtil* ret = IETSystemUtil::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<IETSystemUtil>(cx, (IETSystemUtil*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getInstance : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_uncompressZip(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_uncompressZip : Error processing arguments");
        bool ret = IETSystemUtil::uncompressZip(arg0, arg1);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_uncompressZip : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_urlDecode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_urlDecode : Error processing arguments");
        std::string ret = IETSystemUtil::urlDecode(arg0);
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_urlDecode : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getServerRoot(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = IETSystemUtil::getServerRoot();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getServerRoot : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::function<void (bool, std::basic_string<char>)> arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(1)));
		        auto lambda = [=](bool larg0, std::basic_string<char> larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[2];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            largv[1] = std_string_to_jsval(cx, larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl : Error processing arguments");
        IETSystemUtil::requestUrl(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_exitGame(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETSystemUtil::exitGame();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_exitGame : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getDebugMode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = IETSystemUtil::getDebugMode();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getDebugMode : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getPlatformType(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = IETSystemUtil::getPlatformType();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getPlatformType : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getCurrentTimeMills(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        long ret = IETSystemUtil::getCurrentTimeMills();
        jsval jsret = JSVAL_NULL;
        jsret = long_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_getCurrentTimeMills : wrong number of arguments");
    return false;
}

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_relaunchGame(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETSystemUtil::relaunchGame();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETSystemUtil_relaunchGame : wrong number of arguments");
    return false;
}


void js_IETSystemUtil_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (IETSystemUtil)", obj);
}
void js_register_cocos2dx_gameplugin_manual_IETSystemUtil(JSContext *cx, JS::HandleObject global) {
    jsb_IETSystemUtil_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_IETSystemUtil_class->name = "IETSystemUtil";
    jsb_IETSystemUtil_class->addProperty = JS_PropertyStub;
    jsb_IETSystemUtil_class->delProperty = JS_DeletePropertyStub;
    jsb_IETSystemUtil_class->getProperty = JS_PropertyStub;
    jsb_IETSystemUtil_class->setProperty = JS_StrictPropertyStub;
    jsb_IETSystemUtil_class->enumerate = JS_EnumerateStub;
    jsb_IETSystemUtil_class->resolve = JS_ResolveStub;
    jsb_IETSystemUtil_class->convert = JS_ConvertStub;
    jsb_IETSystemUtil_class->finalize = js_IETSystemUtil_finalize;
    jsb_IETSystemUtil_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("isSalePromotionValid", js_cocos2dx_gameplugin_manual_IETSystemUtil_isSalePromotionValid, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isRedirectGameValid", js_cocos2dx_gameplugin_manual_IETSystemUtil_isRedirectGameValid, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showNewBuildDialog", js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewBuildDialog, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getOnLineValue", js_cocos2dx_gameplugin_manual_IETSystemUtil_getOnLineValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showRedirectGameDialog", js_cocos2dx_gameplugin_manual_IETSystemUtil_showRedirectGameDialog, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getBuildPath", js_cocos2dx_gameplugin_manual_IETSystemUtil_getBuildPath, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("downloadFile", js_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getValue", js_cocos2dx_gameplugin_manual_IETSystemUtil_getValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showSalePromotionDialog", js_cocos2dx_gameplugin_manual_IETSystemUtil_showSalePromotionDialog, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isNewVersionValid", js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewVersionValid, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("syncGameConfig", js_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getLocalValue", js_cocos2dx_gameplugin_manual_IETSystemUtil_getLocalValue, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isNewBuildValid", js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewBuildValid, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("checkVersionBuild", js_cocos2dx_gameplugin_manual_IETSystemUtil_checkVersionBuild, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showNewVersionDialog", js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewVersionDialog, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("urlEncode", js_cocos2dx_gameplugin_manual_IETSystemUtil_urlEncode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getInstance", js_cocos2dx_gameplugin_manual_IETSystemUtil_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("uncompressZip", js_cocos2dx_gameplugin_manual_IETSystemUtil_uncompressZip, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("urlDecode", js_cocos2dx_gameplugin_manual_IETSystemUtil_urlDecode, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getServerRoot", js_cocos2dx_gameplugin_manual_IETSystemUtil_getServerRoot, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("requestUrl", js_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("exitGame", js_cocos2dx_gameplugin_manual_IETSystemUtil_exitGame, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDebugMode", js_cocos2dx_gameplugin_manual_IETSystemUtil_getDebugMode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getPlatformType", js_cocos2dx_gameplugin_manual_IETSystemUtil_getPlatformType, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCurrentTimeMills", js_cocos2dx_gameplugin_manual_IETSystemUtil_getCurrentTimeMills, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("relaunchGame", js_cocos2dx_gameplugin_manual_IETSystemUtil_relaunchGame, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_IETSystemUtil_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_IETSystemUtil_class,
        dummy_constructor<IETSystemUtil>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "IETSystemUtil", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<IETSystemUtil> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_IETSystemUtil_class;
        p->proto = jsb_IETSystemUtil_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_IETGamePlugin_class;
JSObject *jsb_IETGamePlugin_prototype;

bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showLoading(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showLoading : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showLoading : Error processing arguments");
        cobj->showLoading(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showLoading : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_postNotification(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_postNotification : Invalid Native Object");
    if (argc == 1) {
        cocos2d::ValueMap arg0;
        ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_postNotification : Error processing arguments");
        cobj->postNotification(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_postNotification : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_openUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_openUrl : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_openUrl : Error processing arguments");
        cobj->openUrl(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_openUrl : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_hideProgressDialog(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_hideProgressDialog : Invalid Native Object");
    if (argc == 0) {
        cobj->hideProgressDialog();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_hideProgressDialog : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showGameLoading(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showGameLoading : Invalid Native Object");
    if (argc == 3) {
        std::string arg0;
        cocos2d::Vec2 arg1;
        double arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_vector2(cx, args.get(1), &arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !isnan(arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showGameLoading : Error processing arguments");
        cobj->showGameLoading(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showGameLoading : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_rate(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_rate : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_rate : Error processing arguments");
        cobj->rate(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_rate : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getGameClock(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getGameClock : Invalid Native Object");
    if (argc == 0) {
        long ret = cobj->getGameClock();
        jsval jsret = JSVAL_NULL;
        jsret = long_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getGameClock : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getLanguageCode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getLanguageCode : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getLanguageCode();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getLanguageCode : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getAppVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getAppVersion : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->getAppVersion();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getAppVersion : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getDeviceName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getDeviceName : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getDeviceName();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getDeviceName : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_setGenVerifyUrlCallFunc(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_setGenVerifyUrlCallFunc : Invalid Native Object");
    if (argc == 1) {
        std::function<std::basic_string<char> (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](std::unordered_map<std::basic_string<char> larg0, cocos2d::Value larg1, std::hash<string> larg2, std::equal_to<std::basic_string<char> > larg3, std::allocator<std::pair<const std::basic_string<char> larg4, cocos2d::Value> > > larg5) -> basic_string<char> {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[6];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = ccvalue_to_jsval(cx, larg1);
		            do {
		            if (larg2) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::hash<string>>(cx, (std::hash<string>)larg2);
		                largv[2] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[2] = JSVAL_NULL;
		            }
		        } while (0);
		            do {
		            if (larg3) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::equal_to<std::basic_string<char> >>(cx, (std::equal_to<std::basic_string<char> >)larg3);
		                largv[3] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[3] = JSVAL_NULL;
		            }
		        } while (0);
		            largv[4] = std_string_to_jsval(cx, larg4);
		            do {
		            if (larg5) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Value> > >>(cx, (cocos2d::Value> > >)larg5);
		                largv[5] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[5] = JSVAL_NULL;
		            }
		        } while (0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(6, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		            std::basic_string<char> ret;
		            do {
		            if (rval.isNull()) { ret = nullptr; break; }
		            if (!rval.isObject()) { ok = false; break; }
		            js_proxy_t *jsProxy;
		            JSObject *tmpObj = rval.toObjectOrNull();
		            jsProxy = jsb_get_js_proxy(tmpObj);
		            ret = (std::basic_string<char>)(jsProxy ? jsProxy->ptr : NULL);
		            JSB_PRECONDITION2( ret, cx, false, "Invalid Native Object");
		        } while (0);
		            return ret;
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_setGenVerifyUrlCallFunc : Error processing arguments");
        cobj->setGenVerifyUrlCallFunc(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_setGenVerifyUrlCallFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getNetworkState(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getNetworkState : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getNetworkState();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getNetworkState : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showProgressDialog(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showProgressDialog : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        double arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showProgressDialog : Error processing arguments");
        cobj->showProgressDialog(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showProgressDialog : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_hideGameLoading(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_hideGameLoading : Invalid Native Object");
    if (argc == 0) {
        cobj->hideGameLoading();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_hideGameLoading : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getCountryCode(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getCountryCode : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getCountryCode();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getCountryCode : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showImageDialog(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showImageDialog : Invalid Native Object");
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::function<void (bool)> arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        do {
		    if(JS_TypeOfValue(cx, args.get(2)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(2)));
		        auto lambda = [=](bool larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[1];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg2 = lambda;
		    }
		    else
		    {
		        arg2 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showImageDialog : Error processing arguments");
        cobj->showImageDialog(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showImageDialog : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_sendEmail(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_sendEmail : Invalid Native Object");
    if (argc == 4) {
        std::string arg0;
        cocos2d::ValueVector arg1;
        std::string arg2;
        std::function<void (bool, std::basic_string<char>)> arg3;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_ccvaluevector(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        do {
		    if(JS_TypeOfValue(cx, args.get(3)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(3)));
		        auto lambda = [=](bool larg0, std::basic_string<char> larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[2];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            largv[1] = std_string_to_jsval(cx, larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg3 = lambda;
		    }
		    else
		    {
		        arg3 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_sendEmail : Error processing arguments");
        bool ret = cobj->sendEmail(arg0, arg1, arg2, arg3);
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_sendEmail : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_doIap(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_doIap : Invalid Native Object");
    if (argc == 4) {
        cocos2d::ValueVector arg0;
        std::string arg1;
        std::string arg2;
        std::function<void (bool, std::basic_string<char>)> arg3;
        ok &= jsval_to_ccvaluevector(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        do {
		    if(JS_TypeOfValue(cx, args.get(3)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(3)));
		        auto lambda = [=](bool larg0, std::basic_string<char> larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[2];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            largv[1] = std_string_to_jsval(cx, larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg3 = lambda;
		    }
		    else
		    {
		        arg3 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_doIap : Error processing arguments");
        cobj->doIap(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_doIap : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showChooseView(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showChooseView : Invalid Native Object");
    if (argc == 5) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::function<void (bool)> arg4;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        do {
		    if(JS_TypeOfValue(cx, args.get(4)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(4)));
		        auto lambda = [=](bool larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[1];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg4 = lambda;
		    }
		    else
		    {
		        arg4 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showChooseView : Error processing arguments");
        cobj->showChooseView(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_showChooseView : wrong number of arguments: %d, was expecting %d", argc, 5);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getSystemVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getSystemVersion : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getSystemVersion();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getSystemVersion : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_hideLoading(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_hideLoading : Invalid Native Object");
    if (argc == 0) {
        cobj->hideLoading();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_hideLoading : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_setNotificationState(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_setNotificationState : Invalid Native Object");
    if (argc == 1) {
        bool arg0;
        arg0 = JS::ToBoolean(args.get(0));
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_setNotificationState : Error processing arguments");
        cobj->setNotificationState(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_setNotificationState : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_saveImageToAlbum(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_saveImageToAlbum : Invalid Native Object");
    if (argc == 3) {
        std::string arg0;
        std::string arg1;
        std::function<void (bool, std::basic_string<char>)> arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        do {
		    if(JS_TypeOfValue(cx, args.get(2)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(2)));
		        auto lambda = [=](bool larg0, std::basic_string<char> larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[2];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            largv[1] = std_string_to_jsval(cx, larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg2 = lambda;
		    }
		    else
		    {
		        arg2 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_saveImageToAlbum : Error processing arguments");
        cobj->saveImageToAlbum(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_saveImageToAlbum : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_chartviewShow(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_chartviewShow : Invalid Native Object");
    if (argc == 2) {
        cocos2d::ValueVector arg0;
        double arg1;
        ok &= jsval_to_ccvaluevector(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !isnan(arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_chartviewShow : Error processing arguments");
        cobj->chartviewShow(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_chartviewShow : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_copyToPasteboard(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETGamePlugin* cobj = (IETGamePlugin *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_copyToPasteboard : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETGamePlugin_copyToPasteboard : Error processing arguments");
        cobj->copyToPasteboard(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_copyToPasteboard : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETGamePlugin* ret = IETGamePlugin::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<IETGamePlugin>(cx, (IETGamePlugin*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETGamePlugin_getInstance : wrong number of arguments");
    return false;
}


void js_IETGamePlugin_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (IETGamePlugin)", obj);
}
void js_register_cocos2dx_gameplugin_manual_IETGamePlugin(JSContext *cx, JS::HandleObject global) {
    jsb_IETGamePlugin_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_IETGamePlugin_class->name = "IETGamePlugin";
    jsb_IETGamePlugin_class->addProperty = JS_PropertyStub;
    jsb_IETGamePlugin_class->delProperty = JS_DeletePropertyStub;
    jsb_IETGamePlugin_class->getProperty = JS_PropertyStub;
    jsb_IETGamePlugin_class->setProperty = JS_StrictPropertyStub;
    jsb_IETGamePlugin_class->enumerate = JS_EnumerateStub;
    jsb_IETGamePlugin_class->resolve = JS_ResolveStub;
    jsb_IETGamePlugin_class->convert = JS_ConvertStub;
    jsb_IETGamePlugin_class->finalize = js_IETGamePlugin_finalize;
    jsb_IETGamePlugin_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("showLoading", js_cocos2dx_gameplugin_manual_IETGamePlugin_showLoading, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("postNotification", js_cocos2dx_gameplugin_manual_IETGamePlugin_postNotification, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("openUrl", js_cocos2dx_gameplugin_manual_IETGamePlugin_openUrl, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hideProgressDialog", js_cocos2dx_gameplugin_manual_IETGamePlugin_hideProgressDialog, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showGameLoading", js_cocos2dx_gameplugin_manual_IETGamePlugin_showGameLoading, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("rate", js_cocos2dx_gameplugin_manual_IETGamePlugin_rate, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getGameClock", js_cocos2dx_gameplugin_manual_IETGamePlugin_getGameClock, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getLanguageCode", js_cocos2dx_gameplugin_manual_IETGamePlugin_getLanguageCode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAppVersion", js_cocos2dx_gameplugin_manual_IETGamePlugin_getAppVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getDeviceName", js_cocos2dx_gameplugin_manual_IETGamePlugin_getDeviceName, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setGenVerifyUrlCallFunc", js_cocos2dx_gameplugin_manual_IETGamePlugin_setGenVerifyUrlCallFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getNetworkState", js_cocos2dx_gameplugin_manual_IETGamePlugin_getNetworkState, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showProgressDialog", js_cocos2dx_gameplugin_manual_IETGamePlugin_showProgressDialog, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hideGameLoading", js_cocos2dx_gameplugin_manual_IETGamePlugin_hideGameLoading, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getCountryCode", js_cocos2dx_gameplugin_manual_IETGamePlugin_getCountryCode, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showImageDialog", js_cocos2dx_gameplugin_manual_IETGamePlugin_showImageDialog, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sendEmail", js_cocos2dx_gameplugin_manual_IETGamePlugin_sendEmail, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("doIap", js_cocos2dx_gameplugin_manual_IETGamePlugin_doIap, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showChooseView", js_cocos2dx_gameplugin_manual_IETGamePlugin_showChooseView, 5, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getSystemVersion", js_cocos2dx_gameplugin_manual_IETGamePlugin_getSystemVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("hideLoading", js_cocos2dx_gameplugin_manual_IETGamePlugin_hideLoading, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setNotificationState", js_cocos2dx_gameplugin_manual_IETGamePlugin_setNotificationState, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("saveImageToAlbum", js_cocos2dx_gameplugin_manual_IETGamePlugin_saveImageToAlbum, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("chartviewShow", js_cocos2dx_gameplugin_manual_IETGamePlugin_chartviewShow, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("copyToPasteboard", js_cocos2dx_gameplugin_manual_IETGamePlugin_copyToPasteboard, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_cocos2dx_gameplugin_manual_IETGamePlugin_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_IETGamePlugin_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_IETGamePlugin_class,
        dummy_constructor<IETGamePlugin>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "IETGamePlugin", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<IETGamePlugin> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_IETGamePlugin_class;
        p->proto = jsb_IETGamePlugin_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_IETAdvertiseHelper_class;
JSObject *jsb_IETAdvertiseHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_isVedioReady(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAdvertiseHelper* cobj = (IETAdvertiseHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_isVedioReady : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isVedioReady();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_isVedioReady : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAdvertiseHelper* cobj = (IETAdvertiseHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd : Invalid Native Object");
    if (argc == 1) {
        std::function<void (bool)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](bool larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[1];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd : Error processing arguments");
        cobj->showVedioAd(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAdvertiseHelper* cobj = (IETAdvertiseHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd : Invalid Native Object");
    if (argc == 0) {
        cobj->showSpotAd();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETAdvertiseHelper* ret = IETAdvertiseHelper::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<IETAdvertiseHelper>(cx, (IETAdvertiseHelper*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_getInstance : wrong number of arguments");
    return false;
}


void js_IETAdvertiseHelper_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (IETAdvertiseHelper)", obj);
}
void js_register_cocos2dx_gameplugin_manual_IETAdvertiseHelper(JSContext *cx, JS::HandleObject global) {
    jsb_IETAdvertiseHelper_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_IETAdvertiseHelper_class->name = "IETAdvertiseHelper";
    jsb_IETAdvertiseHelper_class->addProperty = JS_PropertyStub;
    jsb_IETAdvertiseHelper_class->delProperty = JS_DeletePropertyStub;
    jsb_IETAdvertiseHelper_class->getProperty = JS_PropertyStub;
    jsb_IETAdvertiseHelper_class->setProperty = JS_StrictPropertyStub;
    jsb_IETAdvertiseHelper_class->enumerate = JS_EnumerateStub;
    jsb_IETAdvertiseHelper_class->resolve = JS_ResolveStub;
    jsb_IETAdvertiseHelper_class->convert = JS_ConvertStub;
    jsb_IETAdvertiseHelper_class->finalize = js_IETAdvertiseHelper_finalize;
    jsb_IETAdvertiseHelper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("isVedioReady", js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_isVedioReady, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showVedioAd", js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showSpotAd", js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_IETAdvertiseHelper_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_IETAdvertiseHelper_class,
        dummy_constructor<IETAdvertiseHelper>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "IETAdvertiseHelper", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<IETAdvertiseHelper> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_IETAdvertiseHelper_class;
        p->proto = jsb_IETAdvertiseHelper_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_IETAnalyticHelper_class;
JSObject *jsb_IETAnalyticHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_purchase(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAnalyticHelper* cobj = (IETAnalyticHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_purchase : Invalid Native Object");
    if (argc == 3) {
        std::string arg0;
        int arg1;
        double arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !isnan(arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_purchase : Error processing arguments");
        cobj->purchase(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_purchase : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_use(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAnalyticHelper* cobj = (IETAnalyticHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_use : Invalid Native Object");
    if (argc == 3) {
        std::string arg0;
        int arg1;
        double arg2;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !isnan(arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_use : Error processing arguments");
        cobj->use(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_use : wrong number of arguments: %d, was expecting %d", argc, 3);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAnalyticHelper* cobj = (IETAnalyticHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setLevel : Invalid Native Object");
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setLevel : Error processing arguments");
        cobj->setLevel(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setLevel : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_charge(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAnalyticHelper* cobj = (IETAnalyticHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_charge : Invalid Native Object");
    if (argc == 4) {
        std::string arg0;
        double arg1;
        double arg2;
        int arg3;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= JS::ToNumber( cx, args.get(1), &arg1) && !isnan(arg1);
        ok &= JS::ToNumber( cx, args.get(2), &arg2) && !isnan(arg2);
        ok &= jsval_to_int32(cx, args.get(3), (int32_t *)&arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_charge : Error processing arguments");
        cobj->charge(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_charge : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_onEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    JS::RootedObject obj(cx);
    IETAnalyticHelper* cobj = NULL;
    obj = args.thisv().toObjectOrNull();
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    cobj = (IETAnalyticHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_onEvent : Invalid Native Object");
    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            std::string arg1;
            ok &= jsval_to_std_string(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            cobj->onEvent(arg0, arg1);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            cobj->onEvent(arg0);
            args.rval().setUndefined();
            return true;
        }
    } while(0);

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_onEvent : wrong number of arguments");
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setAccountInfo(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAnalyticHelper* cobj = (IETAnalyticHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setAccountInfo : Invalid Native Object");
    if (argc == 1) {
        cocos2d::ValueMap arg0;
        ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setAccountInfo : Error processing arguments");
        cobj->setAccountInfo(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setAccountInfo : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_reward(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAnalyticHelper* cobj = (IETAnalyticHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_reward : Invalid Native Object");
    if (argc == 2) {
        double arg0;
        int arg1;
        ok &= JS::ToNumber( cx, args.get(0), &arg0) && !isnan(arg0);
        ok &= jsval_to_int32(cx, args.get(1), (int32_t *)&arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_reward : Error processing arguments");
        cobj->reward(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_reward : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETAnalyticHelper* ret = IETAnalyticHelper::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<IETAnalyticHelper>(cx, (IETAnalyticHelper*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAnalyticHelper_getInstance : wrong number of arguments");
    return false;
}


void js_IETAnalyticHelper_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (IETAnalyticHelper)", obj);
}
void js_register_cocos2dx_gameplugin_manual_IETAnalyticHelper(JSContext *cx, JS::HandleObject global) {
    jsb_IETAnalyticHelper_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_IETAnalyticHelper_class->name = "IETAnalyticHelper";
    jsb_IETAnalyticHelper_class->addProperty = JS_PropertyStub;
    jsb_IETAnalyticHelper_class->delProperty = JS_DeletePropertyStub;
    jsb_IETAnalyticHelper_class->getProperty = JS_PropertyStub;
    jsb_IETAnalyticHelper_class->setProperty = JS_StrictPropertyStub;
    jsb_IETAnalyticHelper_class->enumerate = JS_EnumerateStub;
    jsb_IETAnalyticHelper_class->resolve = JS_ResolveStub;
    jsb_IETAnalyticHelper_class->convert = JS_ConvertStub;
    jsb_IETAnalyticHelper_class->finalize = js_IETAnalyticHelper_finalize;
    jsb_IETAnalyticHelper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("purchase", js_cocos2dx_gameplugin_manual_IETAnalyticHelper_purchase, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("use", js_cocos2dx_gameplugin_manual_IETAnalyticHelper_use, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLevel", js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("charge", js_cocos2dx_gameplugin_manual_IETAnalyticHelper_charge, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("onEvent", js_cocos2dx_gameplugin_manual_IETAnalyticHelper_onEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAccountInfo", js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setAccountInfo, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("reward", js_cocos2dx_gameplugin_manual_IETAnalyticHelper_reward, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_cocos2dx_gameplugin_manual_IETAnalyticHelper_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_IETAnalyticHelper_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_IETAnalyticHelper_class,
        dummy_constructor<IETAnalyticHelper>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "IETAnalyticHelper", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<IETAnalyticHelper> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_IETAnalyticHelper_class;
        p->proto = jsb_IETAnalyticHelper_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_IETFeedbackHelper_class;
JSObject *jsb_IETFeedbackHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETFeedbackHelper_checkFeedback(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFeedbackHelper* cobj = (IETFeedbackHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFeedbackHelper_checkFeedback : Invalid Native Object");
    if (argc == 0) {
        int ret = cobj->checkFeedback();
        jsval jsret = JSVAL_NULL;
        jsret = int32_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFeedbackHelper_checkFeedback : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFeedbackHelper_showFeedBack(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFeedbackHelper* cobj = (IETFeedbackHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFeedbackHelper_showFeedBack : Invalid Native Object");
    if (argc == 1) {
        cocos2d::ValueMap arg0;
        ok &= jsval_to_ccvaluemap(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFeedbackHelper_showFeedBack : Error processing arguments");
        cobj->showFeedBack(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFeedbackHelper_showFeedBack : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFeedbackHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETFeedbackHelper* ret = IETFeedbackHelper::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<IETFeedbackHelper>(cx, (IETFeedbackHelper*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFeedbackHelper_getInstance : wrong number of arguments");
    return false;
}


void js_IETFeedbackHelper_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (IETFeedbackHelper)", obj);
}
void js_register_cocos2dx_gameplugin_manual_IETFeedbackHelper(JSContext *cx, JS::HandleObject global) {
    jsb_IETFeedbackHelper_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_IETFeedbackHelper_class->name = "IETFeedbackHelper";
    jsb_IETFeedbackHelper_class->addProperty = JS_PropertyStub;
    jsb_IETFeedbackHelper_class->delProperty = JS_DeletePropertyStub;
    jsb_IETFeedbackHelper_class->getProperty = JS_PropertyStub;
    jsb_IETFeedbackHelper_class->setProperty = JS_StrictPropertyStub;
    jsb_IETFeedbackHelper_class->enumerate = JS_EnumerateStub;
    jsb_IETFeedbackHelper_class->resolve = JS_ResolveStub;
    jsb_IETFeedbackHelper_class->convert = JS_ConvertStub;
    jsb_IETFeedbackHelper_class->finalize = js_IETFeedbackHelper_finalize;
    jsb_IETFeedbackHelper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("checkFeedback", js_cocos2dx_gameplugin_manual_IETFeedbackHelper_checkFeedback, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("showFeedBack", js_cocos2dx_gameplugin_manual_IETFeedbackHelper_showFeedBack, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_cocos2dx_gameplugin_manual_IETFeedbackHelper_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_IETFeedbackHelper_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_IETFeedbackHelper_class,
        dummy_constructor<IETFeedbackHelper>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "IETFeedbackHelper", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<IETFeedbackHelper> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_IETFeedbackHelper_class;
        p->proto = jsb_IETFeedbackHelper_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_IETFacebookHelper_class;
JSObject *jsb_IETFacebookHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends : Invalid Native Object");
    if (argc == 2) {
        cocos2d::ValueVector arg0;
        std::function<void (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg1;
        ok &= jsval_to_ccvaluevector(cx, args.get(0), &arg0);
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(1)));
		        auto lambda = [=](std::unordered_map<std::basic_string<char> larg0, cocos2d::Value larg1, std::hash<string> larg2, std::equal_to<std::basic_string<char> > larg3, std::allocator<std::pair<const std::basic_string<char> larg4, cocos2d::Value> > > larg5) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[6];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = ccvalue_to_jsval(cx, larg1);
		            do {
		            if (larg2) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::hash<string>>(cx, (std::hash<string>)larg2);
		                largv[2] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[2] = JSVAL_NULL;
		            }
		        } while (0);
		            do {
		            if (larg3) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::equal_to<std::basic_string<char> >>(cx, (std::equal_to<std::basic_string<char> >)larg3);
		                largv[3] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[3] = JSVAL_NULL;
		            }
		        } while (0);
		            largv[4] = std_string_to_jsval(cx, larg4);
		            do {
		            if (larg5) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Value> > >>(cx, (cocos2d::Value> > >)larg5);
		                largv[5] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[5] = JSVAL_NULL;
		            }
		        } while (0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(6, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends : Error processing arguments");
        cobj->getInvitableFriends(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest : Invalid Native Object");
    if (argc == 1) {
        std::function<void (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](std::unordered_map<std::basic_string<char> larg0, cocos2d::Value larg1, std::hash<string> larg2, std::equal_to<std::basic_string<char> > larg3, std::allocator<std::pair<const std::basic_string<char> larg4, cocos2d::Value> > > larg5) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[6];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = ccvalue_to_jsval(cx, larg1);
		            do {
		            if (larg2) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::hash<string>>(cx, (std::hash<string>)larg2);
		                largv[2] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[2] = JSVAL_NULL;
		            }
		        } while (0);
		            do {
		            if (larg3) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::equal_to<std::basic_string<char> >>(cx, (std::equal_to<std::basic_string<char> >)larg3);
		                largv[3] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[3] = JSVAL_NULL;
		            }
		        } while (0);
		            largv[4] = std_string_to_jsval(cx, larg4);
		            do {
		            if (larg5) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Value> > >>(cx, (cocos2d::Value> > >)larg5);
		                largv[5] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[5] = JSVAL_NULL;
		            }
		        } while (0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(6, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest : Error processing arguments");
        cobj->queryRequest(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest : Invalid Native Object");
    if (argc == 4) {
        cocos2d::ValueVector arg0;
        std::string arg1;
        std::string arg2;
        std::function<void (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg3;
        ok &= jsval_to_ccvaluevector(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        do {
		    if(JS_TypeOfValue(cx, args.get(3)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(3)));
		        auto lambda = [=](std::unordered_map<std::basic_string<char> larg0, cocos2d::Value larg1, std::hash<string> larg2, std::equal_to<std::basic_string<char> > larg3, std::allocator<std::pair<const std::basic_string<char> larg4, cocos2d::Value> > > larg5) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[6];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = ccvalue_to_jsval(cx, larg1);
		            do {
		            if (larg2) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::hash<string>>(cx, (std::hash<string>)larg2);
		                largv[2] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[2] = JSVAL_NULL;
		            }
		        } while (0);
		            do {
		            if (larg3) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::equal_to<std::basic_string<char> >>(cx, (std::equal_to<std::basic_string<char> >)larg3);
		                largv[3] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[3] = JSVAL_NULL;
		            }
		        } while (0);
		            largv[4] = std_string_to_jsval(cx, larg4);
		            do {
		            if (larg5) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Value> > >>(cx, (cocos2d::Value> > >)larg5);
		                largv[5] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[5] = JSVAL_NULL;
		            }
		        } while (0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(6, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg3 = lambda;
		    }
		    else
		    {
		        arg3 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest : Error processing arguments");
        cobj->confirmRequest(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest : wrong number of arguments: %d, was expecting %d", argc, 4);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc : Invalid Native Object");
    if (argc == 1) {
        std::function<void (std::basic_string<char>, std::basic_string<char>)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](std::basic_string<char> larg0, std::basic_string<char> larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[2];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = std_string_to_jsval(cx, larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc : Error processing arguments");
        cobj->setLoginFunc(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLevel : Invalid Native Object");
    if (argc == 1) {
        int arg0;
        ok &= jsval_to_int32(cx, args.get(0), (int32_t *)&arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLevel : Error processing arguments");
        cobj->setLevel(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLevel : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_share(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_share : Invalid Native Object");
    if (argc == 6) {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        std::function<void (bool)> arg5;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        do {
		    if(JS_TypeOfValue(cx, args.get(5)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(5)));
		        auto lambda = [=](bool larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[1];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg5 = lambda;
		    }
		    else
		    {
		        arg5 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_share : Error processing arguments");
        cobj->share(arg0, arg1, arg2, arg3, arg4, arg5);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_share : wrong number of arguments: %d, was expecting %d", argc, 6);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends : Invalid Native Object");
    if (argc == 1) {
        std::function<void (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](std::unordered_map<std::basic_string<char> larg0, cocos2d::Value larg1, std::hash<string> larg2, std::equal_to<std::basic_string<char> > larg3, std::allocator<std::pair<const std::basic_string<char> larg4, cocos2d::Value> > > larg5) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[6];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = ccvalue_to_jsval(cx, larg1);
		            do {
		            if (larg2) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::hash<string>>(cx, (std::hash<string>)larg2);
		                largv[2] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[2] = JSVAL_NULL;
		            }
		        } while (0);
		            do {
		            if (larg3) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::equal_to<std::basic_string<char> >>(cx, (std::equal_to<std::basic_string<char> >)larg3);
		                largv[3] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[3] = JSVAL_NULL;
		            }
		        } while (0);
		            largv[4] = std_string_to_jsval(cx, larg4);
		            do {
		            if (larg5) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Value> > >>(cx, (cocos2d::Value> > >)larg5);
		                largv[5] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[5] = JSVAL_NULL;
		            }
		        } while (0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(6, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends : Error processing arguments");
        cobj->getFriends(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::function<void (bool)> arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(1)));
		        auto lambda = [=](bool larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[1];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest : Error processing arguments");
        cobj->acceptRequest(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserID : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getUserID();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserID : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_isLogin(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_isLogin : Invalid Native Object");
    if (argc == 0) {
        bool ret = cobj->isLogin();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_isLogin : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc : Invalid Native Object");
    if (argc == 1) {
        std::function<void (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](std::unordered_map<std::basic_string<char> larg0, cocos2d::Value larg1, std::hash<string> larg2, std::equal_to<std::basic_string<char> > larg3, std::allocator<std::pair<const std::basic_string<char> larg4, cocos2d::Value> > > larg5) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[6];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = ccvalue_to_jsval(cx, larg1);
		            do {
		            if (larg2) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::hash<string>>(cx, (std::hash<string>)larg2);
		                largv[2] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[2] = JSVAL_NULL;
		            }
		        } while (0);
		            do {
		            if (larg3) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::equal_to<std::basic_string<char> >>(cx, (std::equal_to<std::basic_string<char> >)larg3);
		                largv[3] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[3] = JSVAL_NULL;
		            }
		        } while (0);
		            largv[4] = std_string_to_jsval(cx, larg4);
		            do {
		            if (larg5) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Value> > >>(cx, (cocos2d::Value> > >)larg5);
		                largv[5] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[5] = JSVAL_NULL;
		            }
		        } while (0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(6, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc : Error processing arguments");
        cobj->setAppLinkFunc(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_logout(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_logout : Invalid Native Object");
    if (argc == 0) {
        cobj->logout();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_logout : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::function<void (int)> arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(1)));
		        auto lambda = [=](int larg0) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[1];
		            largv[0] = int32_to_jsval(cx, larg0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(1, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel : Error processing arguments");
        cobj->getLevel(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_login(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_login : Invalid Native Object");
    if (argc == 0) {
        cobj->login();
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_login : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_openFacebookPage(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_openFacebookPage : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_openFacebookPage : Error processing arguments");
        cobj->openFacebookPage(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_openFacebookPage : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile : Invalid Native Object");
    if (argc == 1) {
        std::function<void (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](std::unordered_map<std::basic_string<char> larg0, cocos2d::Value larg1, std::hash<string> larg2, std::equal_to<std::basic_string<char> > larg3, std::allocator<std::pair<const std::basic_string<char> larg4, cocos2d::Value> > > larg5) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[6];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = ccvalue_to_jsval(cx, larg1);
		            do {
		            if (larg2) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::hash<string>>(cx, (std::hash<string>)larg2);
		                largv[2] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[2] = JSVAL_NULL;
		            }
		        } while (0);
		            do {
		            if (larg3) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::equal_to<std::basic_string<char> >>(cx, (std::equal_to<std::basic_string<char> >)larg3);
		                largv[3] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[3] = JSVAL_NULL;
		            }
		        } while (0);
		            largv[4] = std_string_to_jsval(cx, larg4);
		            do {
		            if (larg5) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Value> > >>(cx, (cocos2d::Value> > >)larg5);
		                largv[5] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[5] = JSVAL_NULL;
		            }
		        } while (0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(6, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile : Error processing arguments");
        cobj->getUserProfile(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getAccessToken(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETFacebookHelper* cobj = (IETFacebookHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getAccessToken : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getAccessToken();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getAccessToken : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETFacebookHelper* ret = IETFacebookHelper::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<IETFacebookHelper>(cx, (IETFacebookHelper*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInstance : wrong number of arguments");
    return false;
}


void js_IETFacebookHelper_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (IETFacebookHelper)", obj);
}
void js_register_cocos2dx_gameplugin_manual_IETFacebookHelper(JSContext *cx, JS::HandleObject global) {
    jsb_IETFacebookHelper_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_IETFacebookHelper_class->name = "IETFacebookHelper";
    jsb_IETFacebookHelper_class->addProperty = JS_PropertyStub;
    jsb_IETFacebookHelper_class->delProperty = JS_DeletePropertyStub;
    jsb_IETFacebookHelper_class->getProperty = JS_PropertyStub;
    jsb_IETFacebookHelper_class->setProperty = JS_StrictPropertyStub;
    jsb_IETFacebookHelper_class->enumerate = JS_EnumerateStub;
    jsb_IETFacebookHelper_class->resolve = JS_ResolveStub;
    jsb_IETFacebookHelper_class->convert = JS_ConvertStub;
    jsb_IETFacebookHelper_class->finalize = js_IETFacebookHelper_finalize;
    jsb_IETFacebookHelper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("getInvitableFriends", js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("queryRequest", js_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("confirmRequest", js_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLoginFunc", js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setLevel", js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLevel, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("share", js_cocos2dx_gameplugin_manual_IETFacebookHelper_share, 6, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getFriends", js_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("acceptRequest", js_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserID", js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isLogin", js_cocos2dx_gameplugin_manual_IETFacebookHelper_isLogin, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppLinkFunc", js_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logout", js_cocos2dx_gameplugin_manual_IETFacebookHelper_logout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getLevel", js_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("login", js_cocos2dx_gameplugin_manual_IETFacebookHelper_login, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("openFacebookPage", js_cocos2dx_gameplugin_manual_IETFacebookHelper_openFacebookPage, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserProfile", js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAccessToken", js_cocos2dx_gameplugin_manual_IETFacebookHelper_getAccessToken, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_IETFacebookHelper_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_IETFacebookHelper_class,
        dummy_constructor<IETFacebookHelper>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "IETFacebookHelper", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<IETFacebookHelper> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_IETFacebookHelper_class;
        p->proto = jsb_IETFacebookHelper_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

JSClass  *jsb_IETAmazonAWSHelper_class;
JSObject *jsb_IETAmazonAWSHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_setRemoteNotifyFunc(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAmazonAWSHelper* cobj = (IETAmazonAWSHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_setRemoteNotifyFunc : Invalid Native Object");
    if (argc == 1) {
        std::function<void (std::unordered_map<std::basic_string<char>, cocos2d::Value, std::hash<string>, std::equal_to<std::basic_string<char> >, std::allocator<std::pair<const std::basic_string<char>, cocos2d::Value> > >)> arg0;
        do {
		    if(JS_TypeOfValue(cx, args.get(0)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(0)));
		        auto lambda = [=](std::unordered_map<std::basic_string<char> larg0, cocos2d::Value larg1, std::hash<string> larg2, std::equal_to<std::basic_string<char> > larg3, std::allocator<std::pair<const std::basic_string<char> larg4, cocos2d::Value> > > larg5) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[6];
		            largv[0] = std_string_to_jsval(cx, larg0);
		            largv[1] = ccvalue_to_jsval(cx, larg1);
		            do {
		            if (larg2) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::hash<string>>(cx, (std::hash<string>)larg2);
		                largv[2] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[2] = JSVAL_NULL;
		            }
		        } while (0);
		            do {
		            if (larg3) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<std::equal_to<std::basic_string<char> >>(cx, (std::equal_to<std::basic_string<char> >)larg3);
		                largv[3] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[3] = JSVAL_NULL;
		            }
		        } while (0);
		            largv[4] = std_string_to_jsval(cx, larg4);
		            do {
		            if (larg5) {
		                js_proxy_t *jsProxy = js_get_or_create_proxy<cocos2d::Value> > >>(cx, (cocos2d::Value> > >)larg5);
		                largv[5] = OBJECT_TO_JSVAL(jsProxy->obj);
		            } else {
		                largv[5] = JSVAL_NULL;
		            }
		        } while (0);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(6, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg0 = lambda;
		    }
		    else
		    {
		        arg0 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_setRemoteNotifyFunc : Error processing arguments");
        cobj->setRemoteNotifyFunc(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_setRemoteNotifyFunc : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_connectFb(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAmazonAWSHelper* cobj = (IETAmazonAWSHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_connectFb : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_connectFb : Error processing arguments");
        cobj->connectFb(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_connectFb : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_sync(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAmazonAWSHelper* cobj = (IETAmazonAWSHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_sync : Invalid Native Object");
    if (argc == 2) {
        std::string arg0;
        std::function<void (bool, std::basic_string<char>)> arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        do {
		    if(JS_TypeOfValue(cx, args.get(1)) == JSTYPE_FUNCTION)
		    {
		        std::shared_ptr<JSFunctionWrapper> func(new JSFunctionWrapper(cx, args.thisv().toObjectOrNull(), args.get(1)));
		        auto lambda = [=](bool larg0, std::basic_string<char> larg1) -> void {
		            JSB_AUTOCOMPARTMENT_WITH_GLOBAL_OBJCET
		            jsval largv[2];
		            largv[0] = BOOLEAN_TO_JSVAL(larg0);
		            largv[1] = std_string_to_jsval(cx, larg1);
		            JS::RootedValue rval(cx);
		            bool succeed = func->invoke(2, &largv[0], &rval);
		            if (!succeed && JS_IsExceptionPending(cx)) {
		                JS_ReportPendingException(cx);
		            }
		        };
		        arg1 = lambda;
		    }
		    else
		    {
		        arg1 = nullptr;
		    }
		} while(0)
		;
        JSB_PRECONDITION2(ok, cx, false, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_sync : Error processing arguments");
        cobj->sync(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_sync : wrong number of arguments: %d, was expecting %d", argc, 2);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getUserId(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    IETAmazonAWSHelper* cobj = (IETAmazonAWSHelper *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getUserId : Invalid Native Object");
    if (argc == 0) {
        std::string ret = cobj->getUserId();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }

    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getUserId : wrong number of arguments: %d, was expecting %d", argc, 0);
    return false;
}
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        IETAmazonAWSHelper* ret = IETAmazonAWSHelper::getInstance();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<IETAmazonAWSHelper>(cx, (IETAmazonAWSHelper*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getInstance : wrong number of arguments");
    return false;
}


void js_IETAmazonAWSHelper_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (IETAmazonAWSHelper)", obj);
}
void js_register_cocos2dx_gameplugin_manual_IETAmazonAWSHelper(JSContext *cx, JS::HandleObject global) {
    jsb_IETAmazonAWSHelper_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_IETAmazonAWSHelper_class->name = "IETAmazonAWSHelper";
    jsb_IETAmazonAWSHelper_class->addProperty = JS_PropertyStub;
    jsb_IETAmazonAWSHelper_class->delProperty = JS_DeletePropertyStub;
    jsb_IETAmazonAWSHelper_class->getProperty = JS_PropertyStub;
    jsb_IETAmazonAWSHelper_class->setProperty = JS_StrictPropertyStub;
    jsb_IETAmazonAWSHelper_class->enumerate = JS_EnumerateStub;
    jsb_IETAmazonAWSHelper_class->resolve = JS_ResolveStub;
    jsb_IETAmazonAWSHelper_class->convert = JS_ConvertStub;
    jsb_IETAmazonAWSHelper_class->finalize = js_IETAmazonAWSHelper_finalize;
    jsb_IETAmazonAWSHelper_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("setRemoteNotifyFunc", js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_setRemoteNotifyFunc, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("connectFb", js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_connectFb, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sync", js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_sync, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserId", js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getUserId, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getInstance", js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getInstance, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_IETAmazonAWSHelper_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_IETAmazonAWSHelper_class,
        dummy_constructor<IETAmazonAWSHelper>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "IETAmazonAWSHelper", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<IETAmazonAWSHelper> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_IETAmazonAWSHelper_class;
        p->proto = jsb_IETAmazonAWSHelper_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

void register_all_cocos2dx_gameplugin_manual(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "ccg", &ns);

    js_register_cocos2dx_gameplugin_manual_IETGamePlugin(cx, ns);
    js_register_cocos2dx_gameplugin_manual_IETAdvertiseHelper(cx, ns);
    js_register_cocos2dx_gameplugin_manual_IETSystemUtil(cx, ns);
    js_register_cocos2dx_gameplugin_manual_IETFeedbackHelper(cx, ns);
    js_register_cocos2dx_gameplugin_manual_IETAmazonAWSHelper(cx, ns);
    js_register_cocos2dx_gameplugin_manual_IETAnalyticHelper(cx, ns);
    js_register_cocos2dx_gameplugin_manual_IETFacebookHelper(cx, ns);
}

