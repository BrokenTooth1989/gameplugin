
--------------------------------
-- @module IETGamePlugin
-- @parent_module ccg

--------------------------------
-- 
-- @function [parent=#IETGamePlugin] crashReportLogs 
-- @param self
-- @param #string message
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcShowArchievement 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcReportScore 
-- @param self
-- @param #int score
-- @param #string leaderboard
-- @param #bool h2l
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcShowChallenge 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] setSuspensiveIap 
-- @param self
-- @param #map_table iapInfo
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcReset 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcGetScore 
-- @param self
-- @param #string leaderboard
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] canDoIap 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] setIapVerifyUrlAndSign 
-- @param self
-- @param #string url
-- @param #string sign
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcIsAvailable 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcGetAchievement 
-- @param self
-- @param #string achievement
-- @return double#double ret (return value: double)
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] crashReportException 
-- @param self
-- @param #string reason
-- @param #array_table traceback
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcGetPlayerInfo 
-- @param self
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] getSuspensiveIap 
-- @param self
-- @return map_table#map_table ret (return value: map_table)
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcReportAchievement 
-- @param self
-- @param #string achievement
-- @param #double percent
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] gcShowLeaderBoard 
-- @param self
        
--------------------------------
-- 
-- @function [parent=#IETGamePlugin] getInstance 
-- @param self
-- @return IETGamePlugin#IETGamePlugin ret (return value: IETGamePlugin)
        
return nil
