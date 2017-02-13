
--------------------------------
-- @module IETAnalyticHelper
-- @parent_module ccg

--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] purchase 
-- @param self
-- @param #string name
-- @param #int amount
-- @param #double coin
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] use 
-- @param self
-- @param #string name
-- @param #int amount
-- @param #double coin
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] missionStart 
-- @param self
-- @param #string missionId
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] missionFailed 
-- @param self
-- @param #string missionId
-- @param #string reason
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] setLevel 
-- @param self
-- @param #int level
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] charge 
-- @param self
-- @param #string name
-- @param #double cash
-- @param #double coin
-- @param #int type
        
--------------------------------
-- @overload self, string, string         
-- @overload self, string         
-- @overload self, string, map_table         
-- @function [parent=#IETAnalyticHelper] onEvent
-- @param self
-- @param #string eventId
-- @param #map_table map

--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] setAccountInfo 
-- @param self
-- @param #map_table userInfo
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] reward 
-- @param self
-- @param #double coin
-- @param #int type
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] missionSuccess 
-- @param self
-- @param #string missionId
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] getInstance 
-- @param self
-- @return IETAnalyticHelper#IETAnalyticHelper ret (return value: IETAnalyticHelper)
        
return nil
