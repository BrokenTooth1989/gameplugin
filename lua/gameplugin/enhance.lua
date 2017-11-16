--
-- Author: geekgaoyang@gmail.com
-- Date: 2016-08-09 12:28:36
--

-------------------------------------------------------------------------
-------------------------------------------------------------------------
-- table
-------------------------------------------------------------------------
-------------------------------------------------------------------------

function table.shuffle(tab)
	local tab 		= clone(tab)
	local newTab 	= clone(tab)
	local index 	= 1
	while true do
		if #tab <= 0 then break end
		local r = math.random(#tab)
		newTab[index] = tab[r]
		table.remove(tab, r)
		index = index + 1
	end
    return newTab
end

function table.containsElement(tab, element)
	local key
	for k,v in pairs(tab) do
		if v == element then
			key = k
		end
		if key then 
			break 
		end
	end
	return key
end

local function testTable()
	local tab = {1,2,3, haha="hehe", heihei="huhu"}
	dump(tab)

	-- shuffle
	print("============", "shuffle")
	local shuffleTab = table.shuffle(tab)
	dump(tab)
	dump(shuffleTab)
	
	-- contains element
	print("============", "contains element")
	local index = table.containsElement(tab, "hehe")
	dump(tab)
	dump(index)
end

-- testTable()

-------------------------------------------------------------------------
-------------------------------------------------------------------------
-- string
-------------------------------------------------------------------------
-------------------------------------------------------------------------

function string.formatNumThousands(num)
    if nil == num then return "" end
    num = tonumber(num)
    local sign = num >= 0 and "" or "-"
    num = math.abs(num)
    local integerPart = math.floor(num)
    local floatPart = num - integerPart
    local integerStr = tostring(integerPart)
    local tab = {}
    local ended = #integerStr
    while true do
        if ended < 1 then break end
        local start = ended - 2
        start = start < 1 and 1 or start
        table.insert(tab, 1, string.sub(integerStr,start,ended))
        ended = start-1
    end
    if floatPart <= 0 then
    	return sign..table.concat(tab,",")
    else
    	local floatStr = string.sub(tostring(floatPart), 3, 5)
    	return sign..table.concat(tab,",").."."..floatStr
    end

end

function string.formatNumShort(num)
    if nil == num then return "" end
    local suffixTab   = {"","K","M","B","T","Q","Q","S","S"} 
    num = math.round(tonumber(num))
    local suffixIdx = 1
    while true do
        local result = num/1000
        if result < 10 then break end
        num = math.floor(result)
        suffixIdx = suffixIdx+1
    end
    return tostring(num..suffixTab[suffixIdx] or suffixTab[#suffixTab])
end

function string.formatNumHMS(num)
    num = tonumber(num) or 0
    num = math.round(num)
    local second = num%60
    local minute = num/60%60
    local hour = num/60/60
    return string.format("%02d:%02d:%02d",hour, minute, second)
end

function string.formatNumMDY(num, format)
	format = format or "[%b.%d.%Y]"
    num = num or os.time()
    num = math.round(num)
    return os.date(format, num)
end

local function testString()
	print(string.formatNumThousands(10000000000))
	print(string.formatNumShort(10000000000))
	print(string.formatNumHMS(60*30))
	print(string.formatNumMDY(os.time()))
end

-- testString()

-------------------------------------------------------------------------
-------------------------------------------------------------------------
-- Node
-------------------------------------------------------------------------
-------------------------------------------------------------------------

local Node = cc.Node

function Node:scheduleUpdate(_listener)
    return self:schedule(_listener, 0)
end

function Node:schedule(_listener, _interval)
    self.m_timeMap = self.m_timeMap or {}
    local action
    action = cc.RepeatForever:create(cc.Sequence:create(
        cc.DelayTime:create(_interval),
        cc.CallFunc:create(function()
            local time = SystemUtil:getCurrentTimeMills()
            local offset = (time-self.m_timeMap[action])/1000
            self.m_timeMap[action] = time
            _listener(offset)
        end)
    ))
    self.m_timeMap[action] = SystemUtil:getCurrentTimeMills()
    self:runAction(action)
    return action
end

function Node:unschedule(_handler)
    self.m_timeMap = self.m_timeMap or {}
    self:stopAction(_handler)
    self.m_timeMap[_handler] = nil
end

function Node:performWithDelay(_listener, _time)
    local _handler
    _handler = self:schedule(function()
        self:unschedule(_handler)
        _listener()
    end, _time)
    return _handler
end

-- 开始计数
function Node:startCount(_duration, _start, _ended, _progressCb, _finishCb)
    _progressCb = _progressCb or function() end
    _finishCb = _finishCb or function() end

    if _start == _ended then
        _finishCb()
        return
    end

    local offset            = _ended-_start
    local time              = 0
    local schedulerId       = nil
    schedulerId = self:scheduleUpdate(function(dt)
        time = time + dt
        local value
        if time >= _duration then
            time = _duration
            value = _ended
        else
            value = _start+time/_duration*offset
        end
        _progressCb(value)
        if time >= _duration then
            self:unschedule(schedulerId)
            _finishCb()
        end
    end)
    return schedulerId
end

-- 停止计数
function Node:stopCount(_handler)
    self:unschedule(_handler)
end

local function testNode()
    
end

-- testNode




