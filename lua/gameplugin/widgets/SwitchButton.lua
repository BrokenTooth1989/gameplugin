--
-- Author: geekgaoyang@gmail.com
-- Date: 2016-08-19 18:56:37
--

local SwitchButton = class("SwitchButton", function()
	return display.newNode()
end)

function SwitchButton:ctor(params)
	local bg 		= params.bg
	local on 		= params.on
	local dotOn		= params.dotOn
	local dotOff	= params.dotOff
	local bgSpr = display.newSprite(bg)
		:addTo(self)
	local onSpr = display.newSprite(on)
		:addTo(self)
	self.onSpr = onSpr
	local dotOnSpr = display.newSprite(dotOn)
		:addTo(self)
	self.dotOnSpr = dotOnSpr
	local dotOffSpr = display.newSprite(dotOff)
		:addTo(self)
	self.dotOffSpr = dotOffSpr
	local ocsize = onSpr:getContentSize()
	local dcsize = dotOnSpr:getContentSize()
	self.offset = (ocsize.width-dcsize.width)/2
	self:setEnabled(true)
	bgSpr:setTouchEnabled(true)
	bgSpr:setTouchSwallowEnabled(false)
	local start, result
	bgSpr:addNodeEventListener(cc.NODE_TOUCH_EVENT, function(event)
    	if event.name == "began" then
    		start = cc.p(event.x, event.y)
    		result = "click"
		elseif event.name == "moved" then
			local distance = cc.pGetDistance(start, cc.p(event.x, event.y))
    		if distance > 5 then
    			result = "move"
    		end
		elseif event.name == "ended" then
			if result == "click" then
				self:setEnabled(not self.enabled, false)
			end
    	end
    	return true
	end)
end

function SwitchButton:setEnabled(enabled, direct)
	direct = direct == nil and true or direct
	if self.enabled == enabled then return end
	self.enabled = enabled
	if self.listener ~= nil then
		self.listener(enabled)
	end
	local fade = enabled and 255 or 0
	local posx = enabled and self.offset or -self.offset
	self.onSpr:stopAllActions()
	self.dotOnSpr:stopAllActions()
	self.dotOffSpr:stopAllActions()
	if direct then
		self.onSpr:setOpacity(fade)
		self.dotOnSpr:setOpacity(fade)
		self.dotOffSpr:setOpacity(255-fade)
		self.dotOnSpr:setPosition(cc.p(posx, 0))
		self.dotOffSpr:setPosition(cc.p(posx, 0))
	else
		self.onSpr:runAction(cc.FadeTo:create(0.2, fade))
		self.dotOnSpr:runAction(cc.Spawn:create(
			cc.EaseSineInOut:create(cc.MoveTo:create(0.2, cc.p(posx, 0))),
			cc.FadeTo:create(0.2, fade)
		))
		self.dotOffSpr:runAction(cc.Spawn:create(
			cc.EaseSineInOut:create(cc.MoveTo:create(0.2, cc.p(posx, 0))),
			cc.FadeTo:create(0.2, 255-fade)
		))
	end
end

function SwitchButton:isEnabled()
	return self.enabled
end

function SwitchButton:addEventListener(listener)
	self.listener = listener
end

return SwitchButton
