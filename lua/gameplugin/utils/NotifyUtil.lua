--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-05-14 18:14:56
--

local NotifyUtil 				= class("NotifyUtil")

local kNotify 					= "__NOTIFY"
local kNotifyDefault 			= false

function NotifyUtil:ctor()
	self:setNotify(self:getNotify())
end

-- 设置通知状态
function NotifyUtil:setNotify(enable)
	DataUtil:setValueWithId(kNotify, enable)
	SystemUtil:setNotificationState(enable)
end

-- 获取通知状态
function NotifyUtil:getNotify()
	return DataUtil:getValueWithId(kNotify, kNotifyDefault)
end

return NotifyUtil