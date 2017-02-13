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
    	return table.concat(tab,",")
    else
    	local floatStr = string.sub(tostring(floatPart), 3)
    	return table.concat(tab,",").."."..floatStr
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
    local hour = num/60/60%60
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
