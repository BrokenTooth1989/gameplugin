#include "base/ccConfig.h"
#ifndef __cocos2dx_gameplugin_manual_h__
#define __cocos2dx_gameplugin_manual_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_IETSystemUtil_class;
extern JSObject *jsb_IETSystemUtil_prototype;

bool js_cocos2dx_gameplugin_manual_IETSystemUtil_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_manual_IETSystemUtil_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_manual_IETSystemUtil(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_manual(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_isSalePromotionValid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_isRedirectGameValid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewBuildDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getOnLineValue(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_showRedirectGameDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getBuildPath(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_downloadFile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getValue(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_showSalePromotionDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewVersionValid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_syncGameConfig(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getLocalValue(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_isNewBuildValid(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_checkVersionBuild(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_showNewVersionDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_urlEncode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getInstance(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_uncompressZip(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_urlDecode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getServerRoot(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_requestUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_exitGame(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getDebugMode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getPlatformType(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_getCurrentTimeMills(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETSystemUtil_relaunchGame(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETGamePlugin_class;
extern JSObject *jsb_IETGamePlugin_prototype;

bool js_cocos2dx_gameplugin_manual_IETGamePlugin_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_manual_IETGamePlugin_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_manual_IETGamePlugin(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_manual(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_postNotification(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_openUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_hideProgressDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showGameLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_rate(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getGameClock(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getLanguageCode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getAppVersion(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getDeviceName(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_setGenVerifyUrlCallFunc(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getNetworkState(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showProgressDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_hideGameLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getCountryCode(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showImageDialog(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_sendEmail(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_doIap(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_showChooseView(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getSystemVersion(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_hideLoading(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_setNotificationState(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_saveImageToAlbum(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_chartviewShow(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_copyToPasteboard(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETGamePlugin_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETAdvertiseHelper_class;
extern JSObject *jsb_IETAdvertiseHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_manual_IETAdvertiseHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_manual(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_isVedioReady(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showVedioAd(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_showSpotAd(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAdvertiseHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETAnalyticHelper_class;
extern JSObject *jsb_IETAnalyticHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_manual_IETAnalyticHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_manual_IETAnalyticHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_manual(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_purchase(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_use(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setLevel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_charge(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_onEvent(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_setAccountInfo(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_reward(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAnalyticHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETFeedbackHelper_class;
extern JSObject *jsb_IETFeedbackHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETFeedbackHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_manual_IETFeedbackHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_manual_IETFeedbackHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_manual(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_manual_IETFeedbackHelper_checkFeedback(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFeedbackHelper_showFeedBack(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFeedbackHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETFacebookHelper_class;
extern JSObject *jsb_IETFacebookHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_manual_IETFacebookHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_manual_IETFacebookHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_manual(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInvitableFriends(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_queryRequest(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_confirmRequest(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLoginFunc(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_setLevel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_share(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getFriends(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_acceptRequest(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserID(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_isLogin(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_setAppLinkFunc(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_logout(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getLevel(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_login(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_openFacebookPage(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getUserProfile(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getAccessToken(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETFacebookHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

extern JSClass  *jsb_IETAmazonAWSHelper_class;
extern JSObject *jsb_IETAmazonAWSHelper_prototype;

bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_finalize(JSContext *cx, JSObject *obj);
void js_register_cocos2dx_gameplugin_manual_IETAmazonAWSHelper(JSContext *cx, JS::HandleObject global);
void register_all_cocos2dx_gameplugin_manual(JSContext* cx, JS::HandleObject obj);
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_setRemoteNotifyFunc(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_connectFb(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_sync(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getUserId(JSContext *cx, uint32_t argc, jsval *vp);
bool js_cocos2dx_gameplugin_manual_IETAmazonAWSHelper_getInstance(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __cocos2dx_gameplugin_manual_h__
