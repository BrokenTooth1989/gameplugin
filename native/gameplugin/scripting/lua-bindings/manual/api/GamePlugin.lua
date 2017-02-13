
--------------------------------
-- @module GamePlugin
-- @parent_module ccg

--------------------------------
-- 显示Loading
-- @function [parent=#GamePlugin] showLoading 
-- @param self
        
--------------------------------
-- 打开浏览器<br>
-- param url
-- @function [parent=#GamePlugin] openUrl 
-- @param self
-- @param #string url
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] doIap 
-- @param self
-- @param #string iapId
-- @param #function func
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] isSalePromotionValid 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] isHotUpdateValid 
-- @param self
-- @param #int currentBuild
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, string, string         
-- @overload self, string         
-- @function [parent=#GamePlugin] onEvent
-- @param self
-- @param #string eventId
-- @param #string label

--------------------------------
-- 
-- @function [parent=#GamePlugin] showFeedBack 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] isRedirectGameValid 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] use 
-- @param self
-- @param #string name
-- @param #int amount
-- @param #double coin
        
--------------------------------
-- 提示框<br>
-- param title 标题<br>
-- param msg   消息<br>
-- param okMsg 确定文字
-- @function [parent=#GamePlugin] showAlertView 
-- @param self
-- @param #string title
-- @param #string msg
-- @param #string okMsg
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] charge 
-- @param self
-- @param #string name
-- @param #double cash
-- @param #double coin
-- @param #int type
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] isVedioReady 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] setLevel 
-- @param self
-- @param #int level
        
--------------------------------
-- 获取客户端版本号<br>
-- return
-- @function [parent=#GamePlugin] getVersionNum 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] showSpotAd 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] showNewVersionDialog 
-- @param self
        
--------------------------------
-- 检测是否有网<br>
-- return
-- @function [parent=#GamePlugin] checkNetWork 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] purchase 
-- @param self
-- @param #string name
-- @param #int amount
-- @param #double coin
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] showVedioAd 
-- @param self
-- @param #function func
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] showSalePromotionDialog 
-- @param self
-- @param #function func
        
--------------------------------
-- 选择框<br>
-- param title     标题<br>
-- param msg       内容<br>
-- param okMsg     确定文字<br>
-- param cancelMsg 取消文字<br>
-- param func      回调
-- @function [parent=#GamePlugin] showChooseView 
-- @param self
-- @param #string title
-- @param #string msg
-- @param #string okMsg
-- @param #string cancelMsg
-- @param #function func
        
--------------------------------
-- 隐藏Loading
-- @function [parent=#GamePlugin] hideLoading 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] showHotUpdateDialog 
-- @param self
-- @param #int currentBuild
-- @param #function func
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] isNewVersionValid 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] showRedirectGameDialog 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] reward 
-- @param self
-- @param #double coin
-- @param #int type
        
--------------------------------
-- 
-- @function [parent=#GamePlugin] getInstance 
-- @param self
-- @return GamePlugin#GamePlugin ret (return value: GamePlugin)
        
return nil
