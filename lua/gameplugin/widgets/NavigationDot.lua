--
-- Author: gaoyang
-- Date: 2016-09-26 16:12:57
--

local NavigationDot = class(NavigationDot, function()
	return display.newNode()
end)

NavigationDot.Orientation = 
{
	Horizontal = "Horizontal",
	Vertical = "Vertical",
}
local kSpeed = 300

function NavigationDot:ctor(params)
	local inactive = params.inactive
	local active = params.active
	local orientation = params.orientation or self.Orientation.Horizontal
	local space = params.space or 40
	local size = params.size or 5

	local dots = {}
	for i=1,size do
		local offset = (i-(size+1)/2)*space
		local posx = orientation==self.Orientation.Horizontal and offset or 0
		local posy = orientation==self.Orientation.Horizontal and 0 or -offset
		dot = display.newSprite(inactive)
			:pos(posx, posy):addTo(self)
		table.insert(dots, dot)
	end
	self.dots = dots

	local cursor = display.newSprite(active)
		:addTo(self)
	self.cursor = cursor

	self:place(1)
end

function NavigationDot:place(index)
	self.cursor:pos(self.dots[index]:getPosition())
	self.currentIndex = index
end

function NavigationDot:navigate(index, callback)
	callback = callback or function() end
	if index == self.currentIndex then
		return callback()
	end
	self.currentIndex = index
	index = index or 1
	index = index < 1 and 1 or index
	index = index > #self.dots and #self.dots or index
	local dot = self.dots[index]
	local startPos = cc.p(self.cursor:getPosition())
	local endedPos = cc.p(dot:getPosition())
	local distance = cc.pGetDistance(startPos, endedPos)
	local duration = distance/kSpeed
	self.cursor:stopAllActions()
	self.cursor:runAction(cc.Sequence:create(
		cc.ScaleTo:create(0.1, 0),
		cc.Place:create(endedPos),
		cc.ScaleTo:create(0.1, 1),
		cc.CallFunc:create(callback)
	))
end

function NavigationDot:getIndex()
	return self.currentIndex or 1
end

return NavigationDot