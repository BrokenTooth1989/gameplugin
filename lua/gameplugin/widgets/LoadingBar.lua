--
-- Author: gaoyang
-- Date: 2016-12-01 11:38:54
--

local LoadingBar = class("LoadingBar", function()
	return display.newNode()
end)

--[[
bg: 进度条底衬
bar: 进度条
percent: 默认进度
type: 
	1、bar
	2、stencil
particle: 进度条粒子
]]
function LoadingBar:ctor(params)
	assert(params.bar~=nil, "bar shoud not be nil")

	params.percent = params.percent or 0
	params.btype = params.btype or 2

	self.params = params

	-- add bg
	if params.bg then
		display.newSprite(params.bg)
			:addTo(self)
	end

	self.barNode = display.newNode()
		:addTo(self)
	local stencil = display.newSprite(params.bar)
	local clipNode = cc.ClippingNode:create(stencil)
    	:addTo(self.barNode)
    clipNode:setAlphaThreshold(0.5)
    self.width = stencil:getContentSize().width
    if params.btype == 1 then
	    self.bar = display.newSprite(params.bar)
			:pos(0, 0)
			:addTo(clipNode)
	elseif params.btype == 2 then
		self.bar = cc.ProgressTimer:create(display.newSprite(params.bar))
			:pos(0, 0)
			:addTo(clipNode)
		self.bar:setType(cc.PROGRESS_TIMER_TYPE_BAR)
		self.bar:setMidpoint(cc.p(0, 1))
		self.bar:setBarChangeRate(cc.p(1, 0))
    end
	if params.particle then
    	self.particle = cc.ParticleSystemQuad:create(params.particle)
    		:pos(0, 0)
    		:addTo(clipNode)
    	self.particle:setAutoRemoveOnFinish(false)
    end
	-- label
	if params.font ~= nil then
		params.fontOffset = params.fontOffset or cc.p(0, 0)
		local isFnt = string.match(params.font, ".fnt")~=nil
		self.messageLabel = cc.ui.UILabel.new({
		        UILabelType = isFnt and 1 or 2, 
		        text        = "", 
		        font 		= params.font})
			:align(display.CENTER, 0, 0)
			:addTo(self.barNode)
		params.fontSize = params.fontSize or 1
		if isFnt then
			self.messageLabel:setScale(params.fontSize)
		else
			self.messageLabel:setSystemFontSize(params.fontSize)
		end
		params.color = params.color or cc.c3b(255, 255, 255)
		self.messageLabel:setColor(params.color)
		self.messageLabel:setPosition(params.fontOffset)
	end
	self:setPercent(params.percent)
end

function LoadingBar:setPercent(percent, message)
	message = message or string.format("%d%%", percent)
	self.percent = percent
	if self.params.btype == 1 then
		self.bar:setPositionX(self.width*(1-percent/100)*-1)
	elseif self.params.btype == 2 then
		self.bar:setPercentage(percent)
	end
	if self.messageLabel then
		self.messageLabel:setString(message)
	end
	if self.particle then
		self.particle:setPositionX(self.width*(percent/100)-self.width/2)
		if percent >= 100 then
			if self.particle:isActive() then
				self.particle:stopSystem()
			end
		else
			if not self.particle:isActive() then
				self.particle:resetSystem()
			end
		end
	end
end

function LoadingBar:getPercent()
	return self.percent
end

function LoadingBar:setBar(bar)
	if self.params.bar == bar then
		return
	end
	self.params.bar = bar
	local sprite = display.newSprite(bar)
	if self.params.btype == 1 then
		self.bar:setSpriteFrame(sprite:getSpriteFrame())
	elseif self.params.btype == 2 then
		self.bar:setSprite(sprite)
		local percent = self.bar:getPercentage()
		self.bar:setPercentage(0)
		self.bar:setPercentage(percent)
	end
end

function LoadingBar:setBarOffset(offset)
	self.barNode:setPosition(offset)
end

return LoadingBar

