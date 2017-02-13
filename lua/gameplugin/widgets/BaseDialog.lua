--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-11-01 22:14:28
--

local BaseDialog = class("BaseDialog", function()
	return display.newNode()
end)

function BaseDialog:ctor()
    -- background layer
    local bgLayer = cc.LayerColor:create(cc.c4b(0, 0, 0, 150))
        :zorder(-1)
        :addTo(self)
    self.bgLayer = bgLayer
    local bgListener = cc.EventListenerTouchOneByOne:create()
    bgListener:setSwallowTouches(true)
    bgListener:registerScriptHandler(function() return true end, cc.Handler.EVENT_TOUCH_BEGAN)
    bgLayer:getEventDispatcher():addEventListenerWithSceneGraphPriority(bgListener, bgLayer)
    -- create root node
    local root = display.newNode()
        :addTo(self)
    self.root = root
    -- foreground layer
    local fgLayer = cc.LayerColor:create(cc.c4b(0, 0, 0, 0))
        :zorder(1)
        :addTo(self)
    self.fgLayer = fgLayer
    local fgListener = cc.EventListenerTouchOneByOne:create()
    self.fgListener = fgListener
    fgListener:setSwallowTouches(true)
    fgListener:registerScriptHandler(function() return true end, cc.Handler.EVENT_TOUCH_BEGAN)
    fgLayer:getEventDispatcher():addEventListenerWithSceneGraphPriority(fgListener, fgLayer)
    
    self:setNodeEventEnabled(true)
end

function BaseDialog:setCloseCb(closeCb)
    self.closeCb = closeCb
end

function BaseDialog:getCloseCb()
    return self.closeCb or function() end
end

function BaseDialog:setBgOpacity(opacity)
    self.bgLayer:setOpacity(opacity)
end

function BaseDialog:animStart()
    self.fgListener:setSwallowTouches(true)
    self.root:stopAllActions()
end

function BaseDialog:animEnded()
    self.fgListener:setSwallowTouches(false)
end

function BaseDialog:showEaseScale(cb)
	cb = cb or function() end
    self:animStart()
	self.root:scale(0)
    self.root:runAction(cc.Sequence:create({
        cc.EaseBackOut:create(cc.ScaleTo:create(0.3, 1)),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissEaseScale(cb)
	cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseBackIn:create(cc.ScaleTo:create(0.3, 0)),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:showFromBottom(cb)
    cb = cb or function() end
    self:animStart()
    self.root:pos(0, -display.height)
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineOut:create(cc.MoveTo:create(0.3, cc.p(0, 0))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissToBottom(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineIn:create(cc.MoveTo:create(0.3, cc.p(0, -display.height))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:showFromRight(cb)
    cb = cb or function() end
    self:animStart()
    self.root:pos(display.width, 0)
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineOut:create(cc.MoveTo:create(0.2, cc.p(0, 0))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissToRight(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineIn:create(cc.MoveTo:create(0.2, cc.p(display.width, 0))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

return BaseDialog