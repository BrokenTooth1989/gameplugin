#include "base/ccConfig.h"
#ifndef __cocos2dx_gameplugin_auto_h__
#define __cocos2dx_gameplugin_auto_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_IETSystemUtil_class;
extern JSObject *jsb_IETSystemUtil_prototype;

bool js_cocos2dx_gameplugin_auto_IETSystemUtil_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_auto_IETSystemUtil_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_auto_IETSystemUtil(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_auto(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_isSalePromotionValid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_isRedirectGameValid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_showNewBuildDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getOnLineValue(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_showRedirectGameDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getBuildPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getValue(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_isNewVersionValid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getLocalValue(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_isNewBuildValid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_showNewVersionDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_urlEncode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getInstance(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_uncompressZip(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_urlDecode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getServerRoot(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_exitGame(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getPlatformType(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_getCurrentTimeMills(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETSystemUtil_relaunchGame(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETGamePlugin_class;
extern JSObject *jsb_IETGamePlugin_prototype;

bool js_cocos2dx_gameplugin_auto_IETGamePlugin_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_auto_IETGamePlugin_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_auto_IETGamePlugin(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_auto(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_showLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_postNotification(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_openUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_hideProgressDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_showGameLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_rate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_getGameClock(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_getLanguageCode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_getAppVersion(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_getDeviceName(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_getNetworkState(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_showProgressDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_hideGameLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_getCountryCode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_showImageDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_getSystemVersion(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_hideLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_setNotificationState(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_chartviewShow(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_copyToPasteboard(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETGamePlugin_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETAdvertiseHelper_class;
extern JSObject *jsb_IETAdvertiseHelper_prototype;

bool js_cocos2dx_gameplugin_auto_IETAdvertiseHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_auto_IETAdvertiseHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_auto_IETAdvertiseHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_auto(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_auto_IETAdvertiseHelper_isVedioReady(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAdvertiseHelper_showSpotAd(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAdvertiseHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETAnalyticHelper_class;
extern JSObject *jsb_IETAnalyticHelper_prototype;

bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_auto_IETAnalyticHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_auto_IETAnalyticHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_auto(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_purchase(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_use(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_setLevel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_charge(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_onEvent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_setAccountInfo(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_reward(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAnalyticHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETFeedbackHelper_class;
extern JSObject *jsb_IETFeedbackHelper_prototype;

bool js_cocos2dx_gameplugin_auto_IETFeedbackHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_auto_IETFeedbackHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_auto_IETFeedbackHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_auto(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_auto_IETFeedbackHelper_checkFeedback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFeedbackHelper_showFeedBack(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFeedbackHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETFacebookHelper_class;
extern JSObject *jsb_IETFacebookHelper_prototype;

bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_auto_IETFacebookHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_auto_IETFacebookHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_auto(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_setLevel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_getUserID(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_isLogin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_logout(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_login(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_openFacebookPage(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_getAccessToken(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETFacebookHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETAmazonAWSHelper_class;
extern JSObject *jsb_IETAmazonAWSHelper_prototype;

bool js_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_auto_IETAmazonAWSHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_auto(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_connectFb(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getUserId(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_auto_IETAmazonAWSHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __cocos2dx_gameplugin_auto_h__
