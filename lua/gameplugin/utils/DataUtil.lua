--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-02-20 11:28:02
--

local DataUtil                  = class("DataUtil")

local kUserDefaultKey           = "gamestate"
local kCurrentUser              = "__CURRENT_USER"
local kCurrentUserDefault       = "user_default"

local secretKey = "7siyZY$q!Zt7s@h*qN!vFHyebPxA5PZI"

function DataUtil:ctor()
    local userDefault = cc.UserDefault:getInstance()
    local dataStr = userDefault:getStringForKey(kUserDefaultKey)
    if dataStr ~= nil and #dataStr > 0 then
        self._gameState = json.decode(dataStr)
        if self._gameState == nil then

          if device.platform == "ios" or device.platform == "mac" then
             self._gameState = json.decode(crypto.decryptAES256(crypto.decodeBase64(dataStr), secretKey))
          elseif device.platform == "android" then
             self._gameState = json.decode(crypto.decryptXXTEA(crypto.decodeBase64(dataStr), secretKey))
          end

        end
    end
    self._gameState = self._gameState or {}
    
    scheduler.scheduleGlobal(function()
        self:flush()
    end, 5)
end

function DataUtil:flush()
    
    local dataStr 
    if device.platform == "ios" or device.platform == "mac" then
        dataStr = crypto.encodeBase64(crypto.encryptAES256(json.encode(self._gameState), secretKey))
    elseif device.platform == "android" then
        dataStr = crypto.encodeBase64(crypto.encryptXXTEA(json.encode(self._gameState), secretKey))
    end

    local userDefault = cc.UserDefault:getInstance()
    userDefault:setStringForKey(kUserDefaultKey, dataStr)
    userDefault:flush()
end

-- 清空本地数据
function DataUtil:clear()
    self._gameState = {}
end

-- 设置
function DataUtil:setValue(key,value)
    self._gameState[key] = value
end

-- 读取
function DataUtil:getValue(key,defaultValue)
    local value = self._gameState[key]
    return value==nil and defaultValue or value
end

-- 设置当前玩家ID
function DataUtil:setCurrentId(id)
    print("user change to "..tostring(id))
    if id == nil then 
        return
    end
    local currentId = self:getCurrentId()
    if id == currentId then
        return
    end
    self:setValue(kCurrentUser, id)
    if currentId == kCurrentUserDefault then
        self:setUserTab(id, self:getUserTab(currentId))
        self:setValue(currentId, nil)
    end
end

-- 获取当前玩家ID
function DataUtil:getCurrentId()
	return self:getValue(kCurrentUser, kCurrentUserDefault)
end

-- 设置某一个用户的数据
function DataUtil:setUserTab(id, tab)
    self._gameState[id] = tab
end

-- 读取某一个用户的数据
function DataUtil:getUserTab(id)
    if self._gameState[id] == nil then
        self._gameState[id] = {}
    end
    return self._gameState[id]
end

-- 设置
function DataUtil:setValueWithId(key,value)
	local userTab = self:getUserTab(self:getCurrentId())
    userTab[key] = value
end

-- 读取
function DataUtil:getValueWithId(key,defaultValue)
    local userTab = self:getUserTab(self:getCurrentId())
    local value = userTab[key]
    return value==nil and defaultValue or value
end

-- 输出当前存档
function DataUtil:print()
    dump(self._gameState, "gameState", 5)
end

return DataUtil
