
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
-- @return IETAnalyticHelper#IETAnalyticHelper self (return value: IETAnalyticHelper)
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] use 
-- @param self
-- @param #string name
-- @param #int amount
-- @param #double coin
-- @return IETAnalyticHelper#IETAnalyticHelper self (return value: IETAnalyticHelper)
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] setLevel 
-- @param self
-- @param #int level
-- @return IETAnalyticHelper#IETAnalyticHelper self (return value: IETAnalyticHelper)
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] charge 
-- @param self
-- @param #string name
-- @param #double cash
-- @param #double coin
-- @param #int type
-- @return IETAnalyticHelper#IETAnalyticHelper self (return value: IETAnalyticHelper)
        
--------------------------------
-- @overload self, string, string         
-- @overload self, string         
-- @function [parent=#IETAnalyticHelper] onEvent
-- @param self
-- @param #string eventId
-- @param #string label
-- @return IETAnalyticHelper#IETAnalyticHelper self (return value: IETAnalyticHelper)

--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] setAccountInfo 
-- @param self
-- @param #map_table userInfo
-- @return IETAnalyticHelper#IETAnalyticHelper self (return value: IETAnalyticHelper)
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] reward 
-- @param self
-- @param #double coin
-- @param #int type
-- @return IETAnalyticHelper#IETAnalyticHelper self (return value: IETAnalyticHelper)
        
--------------------------------
-- 
-- @function [parent=#IETAnalyticHelper] getInstance 
-- @param self
-- @return IETAnalyticHelper#IETAnalyticHelper ret (return value: IETAnalyticHelper)
        
return nil
