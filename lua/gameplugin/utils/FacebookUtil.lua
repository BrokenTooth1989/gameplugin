--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-05-26 11:04:08
--

local FacebookUtil        		= class("FacebookUtil")

-- 给游戏外好友发送request数据
local kInvitableFriends 		= "__FB_INVITABLE_FRIENDS"
-- 给游戏内好友发送request数据
local kFriends 					= "__FB_FRIENDS"
-- 给游戏内好友发送request数量
local kAcceptRequest 			= "__FB_ACCEPT_REQUEST"
-- 发送request冷却时间
local kRequestDelay 			= 60*60*24
-- 发送request数量
local kRequestMaxNum 			= 5
-- picSize
local kDefaultPicSize 			= 320
local kLoadingStr 				= "Loading..."

function FacebookUtil:ctor()
end

-- 增加观察者
function FacebookUtil:addStateListener(listener)
	self._stateListeners = self._stateListeners or {}
	table.insert(self._stateListeners, listener)
	return listener
end

-- 移除观察者
function FacebookUtil:delStateListener(listener)
	self._stateListeners = self._stateListeners or {}
	for i,_stateListener in ipairs(self._stateListeners) do
		if _stateListener == listener then
			table.remove(self._stateListeners, i)
			break
		end
	end
end

-- 登录
function FacebookUtil:login()
	FacebookHelper:setLoginFunc(function(fid, token)
		if fid == nil or #fid <= 0 then return end
		self._stateListeners = self._stateListeners or {}
		for i,_stateListener in ipairs(self._stateListeners) do
			_stateListener(true, fid, token)
		end
	end)
	FacebookHelper:login()
end

-- 登出
function FacebookUtil:logout()
	FacebookHelper:logout()
	for i,_stateListener in ipairs(self._stateListeners) do
		_stateListener(false)
	end
end


-- 可邀请好友
function FacebookUtil:getInvitableFriends(cb)
	cb = cb or function() end
	if SystemUtil:getNetworkState() == "NotReachable" then 
		return cb()
	end
	if not FacebookHelper:isLogin() then 
		return cb() 
	end
	-- 读取本地已发送邀请的token，如果没有超过24小时，在发送请求时传递给facebook，过期的直接移除
	local invitableFriendsTab = DataUtil:getValueWithId(kInvitableFriends, {})
	local excludedTab = {}
	for confirmedToken,time in pairs(invitableFriendsTab) do
		local currentTime = TimerUtil:getGameTime()
		if currentTime-time <= kRequestDelay then
			table.insert(excludedTab, confirmedToken)
		else
			invitableFriendsTab[confirmedToken] = nil
		end
	end
	FacebookHelper:getInvitableFriends(excludedTab, kDefaultPicSize, function(result)
		if result == nil then
			return cb()
		end
		local invitableFriends 			= result["data"] or {}
		cb(invitableFriends)
	end)
end

-- 游戏内好友
function FacebookUtil:getFriends(cb)
	cb = cb or function() end
	if SystemUtil:getNetworkState() == "NotReachable" then 
		return cb()
	end
	if not FacebookHelper:isLogin() then 
		return cb()
	end
	FacebookHelper:getFriends(kDefaultPicSize, function(result)
		if result == nil then
			return cb()
		end
		local friends 			= result["data"] or {}
		local retFriends		= {}
		local friendsTab 		= DataUtil:getValueWithId(kFriends, {})
		for i,friend in ipairs(friends) do
			local id 			= friend["id"]
			local time 			= friendsTab[id] or -kRequestDelay
			local currentTime 	= TimerUtil:getGameTime()
			if currentTime-time > kRequestDelay then
				table.insert(retFriends, friend)
			end
		end
		cb(retFriends)
	end)
end

-- 收到的request
function FacebookUtil:getRequests(cb)
	cb = cb or function() end
	if SystemUtil:getNetworkState() == "NotReachable" then 
		return cb(false, "network not reachable")
	end
	if not FacebookHelper:isLogin() then 
		return cb(false, "facebook is not login")
	end
	FacebookHelper:queryRequest(function(result)
		if result == nil then
			return cb(false, "result is nil")
		end
		local requests = result["data"] or {}
		cb(true, requests)
	end)
end

-- 发送request
function FacebookUtil:confirmRequest(fids, tokens, title, msg, callback, fromType)
	fids = fids or {}
	tokens = tokens or {}
	callback = callback or function() end

	local fidAndToken = {}
	table.insertto(fidAndToken, fids, #fidAndToken+1)
	table.insertto(fidAndToken, tokens, #fidAndToken+1)
	if #fidAndToken <= 0 then return end
	SystemUtil:showLoading(kLoadingStr)
	FacebookHelper:confirmRequest(fidAndToken, title, msg, function(result)
		SystemUtil:hideLoading()
		local request = result["request"]
		if request ~= nil then--成功
			if fromType == "accept" then
				-- 更新游戏内好友互发礼物数据
				local acceptRequest = DataUtil:getValueWithId(kAcceptRequest, {})
				for i,fid in ipairs(fids) do
					acceptRequest[fid] = acceptRequest[fid] or {time=-kRequestDelay,count=0}
					local time = acceptRequest[fid].time
					local currentTime = TimerUtil:getGameTime()
					local count = acceptRequest[fid].count
					if currentTime-time > kRequestDelay then
						time = TimerUtil:getGameTime()
						count = 0
					end
					count = count + 1
					acceptRequest[fid].time = time
					acceptRequest[fid].count = count
				end
				DataUtil:setValueWithId(kAcceptRequest, acceptRequest)
			else
				-- 更新游戏外好友数据
				local invitableFriendsTab = DataUtil:getValueWithId(kInvitableFriends, {})
				for i,token in ipairs(tokens) do
					invitableFriendsTab[token] = TimerUtil:getGameTime()
				end
				DataUtil:setValueWithId(kInvitableFriends, invitableFriendsTab)
				-- 更新游戏内好友数据
				local friendsTab = DataUtil:getValueWithId(kFriends, {})
				for i,fid in ipairs(fids) do
					friendsTab[fid] = TimerUtil:getGameTime()
				end
				dump(friendsTab)
				DataUtil:setValueWithId(kFriends, friendsTab)
			end
			callback()
		end
	end)
end

-- 删除request，并向发送者回馈礼物
function FacebookUtil:acceptRequest(request, title, msg, callback)
	callback 			= callback or function() end

	local requestId = request["id"]
	SystemUtil:showLoading(kLoadingStr)
	FacebookHelper:acceptRequest(requestId, function(result)
		SystemUtil:hideLoading()
		if result then
			-- 如果已经超过冷却时间，或者次数小于5次，回馈礼物
			local fromId 			= request.from.id
			local acceptRequest 	= DataUtil:getValueWithId(kAcceptRequest, {})
			acceptRequest[fromId] 	= acceptRequest[fromId] or {time=-kRequestDelay,count=0}
			local time 				= acceptRequest[fromId].time
			local count 			= acceptRequest[fromId].count
			local currentTime 		= TimerUtil:getGameTime()
			if currentTime-time > kRequestDelay or count < kRequestMaxNum then
				self:confirmRequest({fromId}, nil, title, msg, nil, "accept")
			end
			callback(true)
		else
			callback(false)
		end
	end)
end

function FacebookUtil:getFbAvatarUrl(fid, size)
	return string.format("http://graph.facebook.com/%s/picture?width=%d&height=%d", fid, size, size)
end

return FacebookUtil