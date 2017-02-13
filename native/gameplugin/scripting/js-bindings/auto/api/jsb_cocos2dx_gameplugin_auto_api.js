/**
 * @module cocos2dx_gameplugin_auto
 */
var ccg = ccg || {};

/**
 * @class IETSystemUtil
 */
ccg.IETSystemUtil = {

/**
 * @method isSalePromotionValid
 * @return {bool}
 */
isSalePromotionValid : function (
)
{
    return false;
},

/**
 * @method isRedirectGameValid
 * @return {bool}
 */
isRedirectGameValid : function (
)
{
    return false;
},

/**
 * @method showNewBuildDialog
 * @param {int} arg0
 */
showNewBuildDialog : function (
int 
)
{
},

/**
 * @method getOnLineValue
 * @param {String} arg0
 * @return {cc.Value}
 */
getOnLineValue : function (
str 
)
{
    return cc.Value;
},

/**
 * @method showRedirectGameDialog
 */
showRedirectGameDialog : function (
)
{
},

/**
 * @method getBuildPath
 * @return {String}
 */
getBuildPath : function (
)
{
    return ;
},

/**
 * @method getValue
 * @param {String} arg0
 * @return {cc.Value}
 */
getValue : function (
str 
)
{
    return cc.Value;
},

/**
 * @method isNewVersionValid
 * @return {bool}
 */
isNewVersionValid : function (
)
{
    return false;
},

/**
 * @method getLocalValue
 * @param {String} arg0
 * @return {cc.Value}
 */
getLocalValue : function (
str 
)
{
    return cc.Value;
},

/**
 * @method isNewBuildValid
 * @param {int} arg0
 * @return {bool}
 */
isNewBuildValid : function (
int 
)
{
    return false;
},

/**
 * @method showNewVersionDialog
 */
showNewVersionDialog : function (
)
{
},

/**
 * @method urlEncode
 * @param {String} arg0
 * @return {String}
 */
urlEncode : function (
str 
)
{
    return ;
},

/**
 * @method getInstance
 * @return {IETSystemUtil}
 */
getInstance : function (
)
{
    return IETSystemUtil;
},

/**
 * @method uncompressZip
 * @param {String} arg0
 * @param {String} arg1
 * @return {bool}
 */
uncompressZip : function (
str, 
str 
)
{
    return false;
},

/**
 * @method urlDecode
 * @param {String} arg0
 * @return {String}
 */
urlDecode : function (
str 
)
{
    return ;
},

/**
 * @method getServerRoot
 * @return {String}
 */
getServerRoot : function (
)
{
    return ;
},

/**
 * @method exitGame
 */
exitGame : function (
)
{
},

/**
 * @method getDebugMode
 * @return {bool}
 */
getDebugMode : function (
)
{
    return false;
},

/**
 * @method getPlatformType
 * @return {String}
 */
getPlatformType : function (
)
{
    return ;
},

/**
 * @method getCurrentTimeMills
 * @return {long}
 */
getCurrentTimeMills : function (
)
{
    return 0;
},

/**
 * @method relaunchGame
 */
relaunchGame : function (
)
{
},

};

/**
 * @class IETGamePlugin
 */
ccg.IETGamePlugin = {

/**
 * @method showLoading
 * @param {String} arg0
 */
showLoading : function (
str 
)
{
},

/**
 * @method postNotification
 * @param {map_object} arg0
 */
postNotification : function (
map 
)
{
},

/**
 * @method openUrl
 * @param {String} arg0
 */
openUrl : function (
str 
)
{
},

/**
 * @method hideProgressDialog
 */
hideProgressDialog : function (
)
{
},

/**
 * @method showGameLoading
 * @param {String} arg0
 * @param {vec2_object} arg1
 * @param {float} arg2
 */
showGameLoading : function (
str, 
vec2, 
float 
)
{
},

/**
 * @method rate
 * @param {bool} arg0
 */
rate : function (
bool 
)
{
},

/**
 * @method getGameClock
 * @return {long}
 */
getGameClock : function (
)
{
    return 0;
},

/**
 * @method getLanguageCode
 * @return {String}
 */
getLanguageCode : function (
)
{
    return ;
},

/**
 * @method getAppVersion
 * @return {int}
 */
getAppVersion : function (
)
{
    return 0;
},

/**
 * @method getDeviceName
 * @return {String}
 */
getDeviceName : function (
)
{
    return ;
},

/**
 * @method getNetworkState
 * @return {String}
 */
getNetworkState : function (
)
{
    return ;
},

/**
 * @method showProgressDialog
 * @param {String} arg0
 * @param {float} arg1
 */
showProgressDialog : function (
str, 
float 
)
{
},

/**
 * @method hideGameLoading
 */
hideGameLoading : function (
)
{
},

/**
 * @method getCountryCode
 * @return {String}
 */
getCountryCode : function (
)
{
    return ;
},

/**
 * @method showImageDialog
 * @param {String} arg0
 * @param {String} arg1
 * @param {function} arg2
 */
showImageDialog : function (
str, 
str, 
func 
)
{
},

/**
 * @method getSystemVersion
 * @return {String}
 */
getSystemVersion : function (
)
{
    return ;
},

/**
 * @method hideLoading
 */
hideLoading : function (
)
{
},

/**
 * @method setNotificationState
 * @param {bool} arg0
 */
setNotificationState : function (
bool 
)
{
},

/**
 * @method chartviewShow
 * @param {Array} arg0
 * @param {float} arg1
 */
chartviewShow : function (
array, 
float 
)
{
},

/**
 * @method copyToPasteboard
 * @param {String} arg0
 */
copyToPasteboard : function (
str 
)
{
},

/**
 * @method getInstance
 * @return {IETGamePlugin}
 */
getInstance : function (
)
{
    return IETGamePlugin;
},

};

/**
 * @class IETAdvertiseHelper
 */
ccg.IETAdvertiseHelper = {

/**
 * @method isVedioReady
 * @return {bool}
 */
isVedioReady : function (
)
{
    return false;
},

/**
 * @method showSpotAd
 */
showSpotAd : function (
)
{
},

/**
 * @method getInstance
 * @return {IETAdvertiseHelper}
 */
getInstance : function (
)
{
    return IETAdvertiseHelper;
},

};

/**
 * @class IETAnalyticHelper
 */
ccg.IETAnalyticHelper = {

/**
 * @method purchase
 * @param {String} arg0
 * @param {int} arg1
 * @param {double} arg2
 */
purchase : function (
str, 
int, 
double 
)
{
},

/**
 * @method use
 * @param {String} arg0
 * @param {int} arg1
 * @param {double} arg2
 */
use : function (
str, 
int, 
double 
)
{
},

/**
 * @method setLevel
 * @param {int} arg0
 */
setLevel : function (
int 
)
{
},

/**
 * @method charge
 * @param {String} arg0
 * @param {double} arg1
 * @param {double} arg2
 * @param {int} arg3
 */
charge : function (
str, 
double, 
double, 
int 
)
{
},

/**
 * @method onEvent
* @param {String|String} str
* @param {String} str
*/
onEvent : function(
str,
str 
)
{
},

/**
 * @method setAccountInfo
 * @param {map_object} arg0
 */
setAccountInfo : function (
map 
)
{
},

/**
 * @method reward
 * @param {double} arg0
 * @param {int} arg1
 */
reward : function (
double, 
int 
)
{
},

/**
 * @method getInstance
 * @return {IETAnalyticHelper}
 */
getInstance : function (
)
{
    return IETAnalyticHelper;
},

};

/**
 * @class IETFeedbackHelper
 */
ccg.IETFeedbackHelper = {

/**
 * @method checkFeedback
 * @return {int}
 */
checkFeedback : function (
)
{
    return 0;
},

/**
 * @method showFeedBack
 * @param {map_object} arg0
 */
showFeedBack : function (
map 
)
{
},

/**
 * @method getInstance
 * @return {IETFeedbackHelper}
 */
getInstance : function (
)
{
    return IETFeedbackHelper;
},

};

/**
 * @class IETFacebookHelper
 */
ccg.IETFacebookHelper = {

/**
 * @method setLevel
 * @param {int} arg0
 */
setLevel : function (
int 
)
{
},

/**
 * @method getUserID
 * @return {String}
 */
getUserID : function (
)
{
    return ;
},

/**
 * @method isLogin
 * @return {bool}
 */
isLogin : function (
)
{
    return false;
},

/**
 * @method logout
 */
logout : function (
)
{
},

/**
 * @method login
 */
login : function (
)
{
},

/**
 * @method openFacebookPage
 * @param {String} arg0
 * @param {String} arg1
 */
openFacebookPage : function (
str, 
str 
)
{
},

/**
 * @method getAccessToken
 * @return {String}
 */
getAccessToken : function (
)
{
    return ;
},

/**
 * @method getInstance
 * @return {IETFacebookHelper}
 */
getInstance : function (
)
{
    return IETFacebookHelper;
},

};

/**
 * @class IETAmazonAWSHelper
 */
ccg.IETAmazonAWSHelper = {

/**
 * @method connectFb
 * @param {String} arg0
 */
connectFb : function (
str 
)
{
},

/**
 * @method getUserId
 * @return {String}
 */
getUserId : function (
)
{
    return ;
},

/**
 * @method getInstance
 * @return {IETAmazonAWSHelper}
 */
getInstance : function (
)
{
    return IETAmazonAWSHelper;
},

};
