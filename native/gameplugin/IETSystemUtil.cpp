//
//  IETSystemUtil.cpp
//  gameplugin
//
//  Created by geekgy on 15-3-18.
//
//

#include "IETSystemUtil.h"
#include <stdio.h>
#include "unzip/unzip.h"
#include "xxtea/xxtea.h"
#include "IETGamePlugin.h"
#include "IETAnalyticHelper.h"

using namespace std;
using namespace cocos2d;
using namespace cocos2d::extension;

std::string IETSystemUtil::_localConfigFile = "";

void IETSystemUtil::setLocalConfig(std::string file) {
    _localConfigFile = file;
}

std::string IETSystemUtil::getPlatformType() {
    string type = "mac";
    Application::Platform platform = Application::getInstance()->getTargetPlatform();
    if (platform == Application::Platform::OS_IPAD
            || platform == Application::Platform::OS_IPHONE) {
        type = "ios";
    } else if (platform == Application::Platform::OS_ANDROID) {
        type = "android";
    } else if (platform == Application::Platform::OS_MAC) {
        type = "mac";
    }
    return type;
}

long long IETSystemUtil::getCurrentTimeMills() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long timestamp = tv.tv_sec*1000+tv.tv_usec/1000;
    return timestamp;
}

unsigned char ToHex(unsigned char x) {
    return x > 9 ? x + 55 : x + 48;
}

unsigned char FromHex(unsigned char x) {
    unsigned char y = 0;
    if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
    else if (x >= '0' && x <= '9') y = x - '0';
    return y;
}

std::string IETSystemUtil::urlEncode(std::string url) {
    std::string strTemp = "";
    size_t length = url.length();
    for (size_t i = 0; i < length; i++) {
        if (isalnum((unsigned char) url[i]) ||
                (url[i] == '-') ||
                (url[i] == '_') ||
                (url[i] == '.') ||
                (url[i] == '~'))
            strTemp += url[i];
        else if (url[i] == ' ')
            strTemp += "+";
        else {
            strTemp += '%';
            strTemp += ToHex((unsigned char) url[i] >> 4);
            strTemp += ToHex((unsigned char) url[i] % 16);
        }
    }
    return strTemp;
}

std::string IETSystemUtil::urlDecode(std::string url) {
    std::string strTemp = "";
    size_t length = url.length();
    for (size_t i = 0; i < length; i++) {
        if (url[i] == '+') strTemp += ' ';
        else if (url[i] == '%') {
            unsigned char high = FromHex((unsigned char) url[++i]);
            unsigned char low = FromHex((unsigned char) url[++i]);
            strTemp += high * 16 + low;
        } else strTemp += url[i];
    }
    return strTemp;
}

std::string IETSystemUtil::xxteaEncrypt(std::string input, std::string key) {
    unsigned char *uc_input = (unsigned char *) input.c_str();
    xxtea_long uc_inputLen = (xxtea_long) strlen(input.c_str());
    unsigned char *uc_key = (unsigned char *) key.c_str();
    xxtea_long uc_keyLen = (xxtea_long) strlen(key.c_str());
    xxtea_long len;
    unsigned char *result = xxtea_encrypt(uc_input, uc_inputLen, uc_key, uc_keyLen, &len);
    if (len <= 0) {
        return "";
    } else {
        string s((const char *) result, len);
        free(result);
        return s;
    }
}

std::string IETSystemUtil::xxteaDecrypt(std::string input, std::string key) {
    unsigned char *uc_input = (unsigned char *) input.c_str();
    xxtea_long uc_inputLen = (xxtea_long) strlen(input.c_str());
    unsigned char *uc_key = (unsigned char *) key.c_str();
    xxtea_long uc_keyLen = (xxtea_long) strlen(key.c_str());
    xxtea_long len;
    unsigned char *result = xxtea_decrypt(uc_input, uc_inputLen, uc_key, uc_keyLen, &len);
    if (len <= 0) {
        return "";
    } else {
        string s((const char *) result, len);
        free(result);
        return s;
    }
}

std::string IETSystemUtil::base64Encode(std::string input) {
    unsigned char *uc_input = (unsigned char *) input.c_str();
    unsigned int uc_inputLen = (unsigned int) strlen(input.c_str());
    char *result = nullptr;
    int len = cocos2d::base64Encode(uc_input, uc_inputLen, &result);
    if (len <= 0) {
        return "";
    } else {
        string s(result, len);
        free(result);
        return s;
    }
}

std::string IETSystemUtil::base64Decode(std::string input) {
    unsigned char *uc_input = (unsigned char *) input.c_str();
    unsigned int uc_inputLen = (unsigned int) strlen(input.c_str());
    unsigned char *result = nullptr;
    int len = cocos2d::base64Decode(uc_input, uc_inputLen, &result);
    if (len <= 0) {
        return "";
    } else {
        string s((const char *) result, len);
        free(result);
        return s;
    }
}

void IETSystemUtil::syncGameConfig(std::string configUrl, const std::function<void()> &func) {
    IETSystemUtil::requestUrl("get", configUrl, ValueMapNull, [=](bool success, std::string data) {
        if (success && data.length() > 0) {
            UserDefault::getInstance()->setStringForKey("online_config", data);
            UserDefault::getInstance()->flush();
        } else {
            data = UserDefault::getInstance()->getStringForKey("online_config", "");
        }
        if (data.length() > 0) {
            _onlineValueMap = FileUtils::getInstance()->getValueMapFromData(data.c_str(), (int) data.length());
        }
        func();
    });
}

std::string IETSystemUtil::getCfgValue(std::string key) {
    std::string v = getOnlineCfgValue(key);
    if (strcmp(v.c_str(), "")) {
        return v;
    }
    return getLocalCfgValue(key);
}

std::string IETSystemUtil::getLocalCfgValue(std::string key) {
    return _localValueMap[key].asString();
}

std::string IETSystemUtil::getOnlineCfgValue(std::string key) {
    return _onlineValueMap[key].asString();
}

void IETSystemUtil::downloadFile(std::string url, std::string path, const std::function<void(int, int)> &callback) {
    string key = url + "_" + path;
    vector<DownloadItem> v;
    bool isExist = false;
    if (_downloadItems.find(key) != _downloadItems.end()) {
        v = _downloadItems[key];
        isExist = true;
    }
    DownloadItem item;
    item.url = url;
    item.path = path;
    item.callback = callback;
    v.push_back(item);
    _downloadItems[key] = v;
    if (isExist) {
        return;
    }
    _downloader->downloadAsync(url, path, key);
}

bool IETSystemUtil::uncompressZip(std::string file, std::string path) {
    unzFile zipfile = unzOpen(file.c_str());


    if (zipfile == NULL) {
        // printf( "%s: not found" ,file.c_str());
        return false;
    }

    // Get info about the zip file
    unz_global_info global_info;
    if (unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK) {
        // printf( "could not read file global info" );
        unzClose(zipfile);
        return false;
    }

    // Loop to extract all files
    uLong i;
    for (i = 0; i < global_info.number_entry; ++i) {
        // Get info about current file.
        unz_file_info file_info;
        char filename[100];
        if (unzGetCurrentFileInfo(
                zipfile,
                &file_info,
                filename,
                100,
                NULL, 0, NULL, 0) != UNZ_OK) {
            // log( "could not read file info" );
            unzClose(zipfile);
            return false;
        }

        // Buffer to hold data read from the zip file.
        char read_buffer[8192];

        std::string str(filename);

        //if(str.find(".png") != string::npos || str.find(".gif") != string::npos){

        // log("debug extracting file %s",filename );
        // Check if this entry is a directory or file.
        const size_t filename_length = strlen(filename);
        if (filename[filename_length - 1] == '/') {
            // Entry is a directory, so create it.
            std::string dirPath = path + filename;
            // log( "dir:%s",  dirPath.c_str());
            if (!FileUtils::getInstance()->isDirectoryExist(dirPath)) {
                FileUtils::getInstance()->createDirectory(dirPath);
            }
        } else {
            // Entry is a file, so extract it.
            // log( "file:%s", filename );
            if (unzOpenCurrentFile(zipfile) != UNZ_OK) {
                // log( "could not open file" );
                unzClose(zipfile);
                return false;
            }

            // Open a file to write out the data.
            std::string filepath = path + filename;
            // log("%s",filepath.c_str());
            FILE *out = fopen(filepath.c_str(), "wb");
            if (out == NULL) {
                // log( "could not open destination file" );
            } else {
                int error = UNZ_OK;
                do {
                    error = unzReadCurrentFile(zipfile, read_buffer, 8192);
                    if (error < 0) {
                        // printf( "error %d", error );
                        unzCloseCurrentFile(zipfile);
                        unzClose(zipfile);
                        return false;
                    }

                    // Write data to file.
                    if (error > 0) {
                        unsigned long dbuf = fwrite(read_buffer, error, 1, out); // You should check return of fwrite...
                        CC_UNUSED_PARAM(dbuf);
                        // log("debug bytes written %d %s",dbuf,filename);
                    }
                } while (error > 0);

                fclose(out);
            }
        }

        unzCloseCurrentFile(zipfile);


        // Go the the next entry listed in the zip file.
        if ((i + 1) < global_info.number_entry) {
            if (unzGoToNextFile(zipfile) != UNZ_OK) {
                // printf( "cound not read next file" );
                unzClose(zipfile);
                return false;
            }
        }

    }

    unzClose(zipfile);
    return true;
}

void IETSystemUtil::openUrl(std::string url) {
    Application::getInstance()->openURL(url);
}

void IETSystemUtil::exitGame() {
    Director::getInstance()->end();
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    exit(0);
#endif
}


bool IETSystemUtil::getRandom(float probability) {
    int _probability = probability * 100;
    int odds = rand()%100;
    if(probability >= 1) {
        return true;
    }
    if(odds < _probability)
    {
        return  true;
    }else{
        return  false;
    }
}


//本地存储数据
void IETSystemUtil::setUserLocalData(std::string key, std::string value) {
    UserDefault::getInstance()->setStringForKey(key.c_str(), value.c_str());
    UserDefault::getInstance()->flush();
}
//获取本地数据
std::string IETSystemUtil::getUserLocalData(std::string key) {
    std::string data = UserDefault::getInstance()->getStringForKey(key.c_str(), "");
    return data;
}

#pragma mark private

IETSystemUtil::IETSystemUtil()
:_downloader(nullptr)
{
    _downloadItems.clear();
    _downloader = std::make_shared<Downloader>();
    _downloader->setProgressCallback([&](double total, double current, string url, string id) {
        // CCLOG("setProgressCallback: %f,%f,%s,%s", total, current, url.c_str(), id.c_str());
        if (_downloadItems.find(id) != _downloadItems.end()) {
            vector<DownloadItem> items = _downloadItems[id];
            for (int i = 0; i < items.size(); i++) {
                DownloadItem item = items.at(i);
                item.callback(0, current / total * 100);
            }
        }
    });
    _downloader->setSuccessCallback([&](string url, string path, string id) {
        // CCLOG("setSuccessCallback: %s,%s,%s", url.c_str(), path.c_str(), id.c_str());
        if (_downloadItems.find(id) != _downloadItems.end()) {
            vector<DownloadItem> items = _downloadItems[id];
            for (int i = 0; i < items.size(); i++) {
                DownloadItem item = items.at(i);
                item.callback(1, 0);
            }
            _downloadItems.erase(id);
        }
    });
    _downloader->setErrorCallback([&](Downloader::Error error) {
        Downloader::ErrorCode code = error.code;
        int curle_code = error.curle_code;
        int curlm_code = error.curlm_code;
        CC_UNUSED_PARAM(code);
        CC_UNUSED_PARAM(curle_code);
        CC_UNUSED_PARAM(curlm_code);
        string message = error.message;
        string customId = error.customId;
        string url = error.url;
        CCLOG("setErrorCallback: %d, %d, %d, %s, %s, %s", code, curle_code, curlm_code, message.c_str(), customId.c_str(), url.c_str());
        if (_downloadItems.find(customId) != _downloadItems.end()) {
            vector<DownloadItem> items = _downloadItems[customId];
            for (int i = 0; i < items.size(); i++) {
                DownloadItem item = items.at(i);
                item.callback(-1, 0);
            }
            _downloadItems.erase(customId);
        }
    });
    assert(_localConfigFile.size() > 0);
}

IETSystemUtil::~IETSystemUtil() {

}

void IETSystemUtil::init() {
    // 读取本地配置文件
    _localValueMap = FileUtils::getInstance()->getValueMapFromFile(_localConfigFile);
}
