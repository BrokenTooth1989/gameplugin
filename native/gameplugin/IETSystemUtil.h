//
//  IETSystemUtil.h
//  gameplugin
//
//  Created by geekgy on 15-3-18.
//
//

/**
 *  TODO:
 *  下载文件断点续传
 *  下载文件进行校验
 *  下载文件解压缩在异步线程
 */

#ifndef gameplugin_SystemUtil_h
#define gameplugin_SystemUtil_h

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "IETGamePluginDefine.h"

typedef struct {
    std::string url;
    std::string path;
    std::function<void (int,int)> callback;
} DownloadItem;

class IETSystemUtil {
public:
    SINGLETON(IETSystemUtil)
    // 设置本地配置文件
    static void setLocalConfig(std::string filePath);
    // 获取当前是debug包还是release包
    bool getDebugMode();
    // 获取平台类别:ios/android/mac
    std::string getPlatformType();
    // 获取当前系统时间毫秒
    long getCurrentTimeMills();
    // urlencode
    std::string urlEncode(std::string url);
    // urldecode
    std::string urlDecode(std::string url);
    // xxtea加密
    std::string xxteaEncrypt(std::string input, std::string key);
    // xxtea解密
    std::string xxteaDecrypt(std::string input, std::string key);
    // base64编码
    std::string base64Encode(std::string input);
    // base64解码
    std::string base64Decode(std::string input);
    // 获取文件服务器地址
    std::string getFileServerRoot();
    // 获取web服务器地址
    std::string getWebServerRoot();
    // get url
    void requestUrl(std::string requestType, std::string url, std::string data, const std::function<void (bool, std::string)> &func);
    // 同步服务器配置
    void syncGameConfig(std::string configUrl, const std::function<void ()> &func);
    // 获取参数，优先获取在线，没有在获取本地
    cocos2d::Value getValue(std::string key);
    // 获取本地参数
    cocos2d::Value getLocalValue(std::string key);
    // 获取在线参数
    cocos2d::Value getOnLineValue(std::string key);
    // 下载文件
    void downloadFile(std::string url, std::string path, const std::function<void (int state, int progress)> &callback);
    // 解压缩
    bool uncompressZip(std::string file, std::string path);
    // 设置启动lua文件
    void setMainLuaFile(std::string file);
    // 检测客户端版本号和build号
    void checkVersionBuild(std::string configUrl, int currentBuild, const std::function<void ()> &func);
    // 打开浏览器
    void openUrl(std::string url);
    // 退出
    void exitGame();
#pragma mark 平台单独实现
    long getCpuTime();
    std::string getConfigValue(std::string key);
    std::string getBundleId();
    std::string getAppName();
    int getAppVersion();
    std::string getCountryCode();
    std::string getLanguageCode();
    std::string getDeviceName();
    std::string getSystemVersion();
    std::string getNetworkState();
    void showAlertDialog(std::string title, std::string message, std::string cancelBtnTitle, cocos2d::ValueVector otherBtnTitles, const std::function<void (int)> &func);
    void showProgressDialog(std::string message, int percent);
    void hideProgressDialog();
    void showLoading(std::string message);
    void hideLoading();
    void showMessage(std::string message);
    void vibrate();
    void saveImage(std::string imgPath, std::string album, const std::function<void (bool, std::string)> &func);
    void sendEmail(std::string subject, cocos2d::ValueVector, std::string emailBody, const std::function<void (bool, std::string)> &func);
    void setNotificationState(bool enable);
    void postNotification(cocos2d::ValueMap map);
    void share(cocos2d::ValueVector items);
    void keychainSet(std::string key, std::string value);
    std::string keychainGet(std::string key);
    void copyToPasteboard(std::string str);
private:
    IETSystemUtil();
    ~IETSystemUtil();
    void init();
    bool isNewVersionValid();
    void showNewVersionDialog(const std::function<void (int)> &func);
    bool isNewBuildValid(int currentBuild);
    void showNewBuildDialog(int currentBuild, const std::function<void (int)> &func);
private:
    static std::string _localConfigFile;
    CC_SYNTHESIZE_READONLY(std::string, _buildPath, BuildPath);
    CC_SYNTHESIZE_READONLY(std::string, _cachePath, CachePath);
    std::shared_ptr<cocos2d::extension::Downloader> _downloader;
    std::map<std::string, std::vector<DownloadItem>> _downloadItems;    //下载任务队列
    cocos2d::ValueMap _localValueMap;           //本地配置
    cocos2d::ValueMap _onlineValueMap;          //线上配置
    std::string _mainLuaFile;
};

#endif
