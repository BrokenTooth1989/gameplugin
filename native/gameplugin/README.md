# Plugin-Cpp

## Usage

基于 cocos2d-x3.8

```
git clone https://github.com/ietstudio/PluginCpp.git project_name/frameworks/gameplugin
```

代码增加到 xcode ，排除以下目录
```
tojs tolua [scripting/js-bindings scripting/lua-bindings] [ios_mac/ios ios_mac/mac]
```

在 AppDelegate.cpp 中增加以下代码
```
#include "lua_cocos2dx_gameplugin_auto.hpp"
#include "lua_cocos2dx_gameplugin_manual.hpp"

register_all_cocos2dx_gameplugin_auto(stack->getLuaState());
register_all_cocos2dx_gameplugin_manual(stack->getLuaState());
```

在 AppController.mm 中增加以下代码
```
#import "IOSGamePlugin.h"

[[IOSGamePlugin getInstance] application:application didFinishLaunchingWithOptions:launchOptions];

[[IOSGamePlugin getInstance] applicationWillResignActive:application];

[[IOSGamePlugin getInstance] applicationDidBecomeActive:application];

[[IOSGamePlugin getInstance] applicationDidEnterBackground:application];

[[IOSGamePlugin getInstance] applicationWillEnterForeground:application];

[[IOSGamePlugin getInstance] application:application
                                            openURL:url
                                  sourceApplication:sourceApplication
                                         annotation:annotation];

[[IOSGamePlugin getInstance] application:application didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];

[[IOSGamePlugin getInstance] application:application didFailToRegisterForRemoteNotificationsWithError:error];

[[IOSGamePlugin getInstance] application:application didReceiveRemoteNotification:userInfo];

[[IOSGamePlugin getInstance] application:application handleActionWithIdentifier:identifier forRemoteNotification:userInfo completionHandler:completionHandler];
```


## Author

gaoyang, geekgaoyang@gmail.com

