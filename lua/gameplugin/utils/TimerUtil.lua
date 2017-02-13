--
-- Author: geekgaoyang@gmail.com
-- Date: 2016-08-24 17:14:26
--

local TimerUtil 					= class("TimerUtil")

local kTimerConfig 					= "__TIMER_CONFIG"
local kTimerConfigDefault 			= {fix_time=0,run_time=0}

function TimerUtil:ctor()
	self.offset = 0
end

function TimerUtil:getGameTime()
	local timerConfig 		= DataUtil:getValueWithId(kTimerConfig, kTimerConfigDefault)
	local fixTime 			= timerConfig["fix_time"]
	local runTime 			= timerConfig["run_time"]
	local cpuTime 			= SystemUtil:getCpuTime()
	local time 				= cpuTime
	if cpuTime < runTime then--设备重新启动过
		time = cpuTime + fixTime
	else
		time = (cpuTime-runTime)+fixTime
	end
	timerConfig["fix_time"] = time
	timerConfig["run_time"] = cpuTime
	DataUtil:setValueWithId(kTimerConfig, timerConfig)
	return time+100000000
end

function TimerUtil:getTime()
	return os.time()+self.offset
end

function TimerUtil:setTime(time)
	self.offset = time/1000-os.time()
end

return TimerUtil