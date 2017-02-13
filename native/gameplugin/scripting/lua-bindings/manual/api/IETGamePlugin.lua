
--------------------------------
-- @module IETGamePlugin
-- @parent_module ccg

--------------------------------
-- 显示Loading
-- @function [parent=#IETGamePlugin] showLoading 
-- @param self
-- @param #string msg
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 打开浏览器<br>
-- param url
-- @function [parent=#IETGamePlugin] openUrl 
-- @param self
-- @param #string url
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 发起内购<br>
-- param iapIds      所有计费点id<br>
-- param userId      玩家id<br>
-- param iapId       计费点id<br>
-- param bool        是否成功<br>
-- param std::string 额外信息
-- @function [parent=#IETGamePlugin] doIap 
-- @param self
-- @param #array_table iapIds
-- @param #string userId
-- @param #string iapId
-- @param #function func
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 获取App的版本好，是build号<br>
-- return
-- @function [parent=#IETGamePlugin] getAppVersion 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 发送邮件<br>
-- param subject      主题<br>
-- param toRecipients 收件人数组<br>
-- param emailBody    内容，html<br>
-- param bool         是否发送成功<br>
-- param std::string  额外信息<br>
-- return 是否发送成功
-- @function [parent=#IETGamePlugin] sendEmail 
-- @param self
-- @param #string subject
-- @param #array_table toRecipients
-- @param #string emailBody
-- @param #function func
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 显示游戏loading<br>
-- param img   图片路径<br>
-- param point 位置百分比<br>
-- param scale 缩放比例
-- @function [parent=#IETGamePlugin] showGameLoading 
-- @param self
-- @param #string img
-- @param #vec2_table point
-- @param #float scale
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 选择框<br>
-- param title     标题<br>
-- param msg       内容<br>
-- param okMsg     确定文字<br>
-- param cancelMsg 取消文字<br>
-- param func      回调
-- @function [parent=#IETGamePlugin] showChooseView 
-- @param self
-- @param #string title
-- @param #string msg
-- @param #string okMsg
-- @param #string cancelMsg
-- @param #function func
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 获取设备名称<br>
-- return
-- @function [parent=#IETGamePlugin] getDeviceName 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 获取系统版本<br>
-- return
-- @function [parent=#IETGamePlugin] getSystemVersion 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 隐藏Loading
-- @function [parent=#IETGamePlugin] hideLoading 
-- @param self
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 设置生成验证支付URL回调函数<br>
-- param cocos2d::ValueMap
-- @function [parent=#IETGamePlugin] setGenVerifyUrlCallFunc 
-- @param self
-- @param #function func
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 检测是否有网<br>
-- return
-- @function [parent=#IETGamePlugin] getNetworkState 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 显示钜形图<br>
-- param vec<br>
-- param multiply
-- @function [parent=#IETGamePlugin] chartviewShow 
-- @param self
-- @param #array_table vec
-- @param #float multiply
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 获取系统运行时间，设备启动开始计时，设备重启时间归零<br>
-- return
-- @function [parent=#IETGamePlugin] getGameClock 
-- @param self
-- @return long#long ret (return value: long)
        
--------------------------------
-- 获取语言代码<br>
-- return
-- @function [parent=#IETGamePlugin] getLanguageCode 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 复制到剪切版<br>
-- param str
-- @function [parent=#IETGamePlugin] copyToPasteboard 
-- @param self
-- @param #string str
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 评论游戏<br>
-- param force 强制
-- @function [parent=#IETGamePlugin] rate 
-- @param self
-- @param #bool force
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 保存图片到相册<br>
-- param imgPath     图片路径<br>
-- param album       相册名称<br>
-- param bool        保存是否成功<br>
-- param std::string 额外信息
-- @function [parent=#IETGamePlugin] saveImageToAlbum 
-- @param self
-- @param #string imgPath
-- @param #string album
-- @param #function func
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 隐藏游戏loading
-- @function [parent=#IETGamePlugin] hideGameLoading 
-- @param self
-- @return IETGamePlugin#IETGamePlugin self (return value: IETGamePlugin)
        
--------------------------------
-- 获取国家代码<br>
-- return
-- @function [parent=#IETGamePlugin] getCountryCode 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] getInstance 
-- @param self
-- @return IETGamePlugin#IETGamePlugin ret (return value: IETGamePlugin)
        
return nil
