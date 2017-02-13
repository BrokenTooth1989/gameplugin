--
-- Author: gaoyang
-- Date: 2017-02-07 18:41:05
--
local ScratchSprite = class("ScratchSprite", function()
	return display.newNode()
end)
--[[
params.content
params.mask
params.eraser
]]
function ScratchSprite:ctor(params)
	display.newSprite(params.content)
		:addTo(self)
	local maskSpr = display.newSprite(params.mask)
	local maskSize = maskSpr:getContentSize()
	local render = cc.RenderTexture:create(display.width, display.height)
		:addTo(self)
	render:beginWithClear(0, 0, 0, 0)
	maskSpr:visit()
	render:endToLua()
	-- local eraser = cc.DrawNode:create()
	-- eraser:drawSolidCircle(cc.p(0 ,0), 50, math.pi/2, 50, cc.c4f(0,0,0,0.9))
	-- eraser:setBlendFunc(gl.ONE, gl.ZERO)
	-- eraser:retain()

	-- render:beginWithClear(0, 0, 0, 1)
	-- eraser:pos(50, 50)
	-- eraser:visit()
	-- render:endToLua()
end

return ScratchSprite