--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-11-01 22:14:28
--

local BaseDialog = class("BaseDialog", function()
	return display.newNode()
end)

function BaseDialog:ctor(rootPos)
    rootPos = rootPos or cc.p(0, 0)
    -- background layer
    local bgLayer = display.newColorLayer(cc.c4b(0, 0, 0, 150))
        :zorder(-1)
        :addTo(self)
    bgLayer:setCascadeOpacityEnabled(true)
    bgLayer:setCascadeColorEnabled(true)
    self.bgLayer = bgLayer
    -- create root node
    local root = display.newNode()
        :pos(rootPos.x, rootPos.y)
        :addTo(self)
    self.root = root
    -- foreground layer
    local fgLayer = display.newColorLayer(cc.c4b(0, 0, 0, 0))
        :zorder(1)
        :addTo(self)
    self.fgLayer = fgLayer
    fgLayer:hide()
    
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
    self.fgLayer:show()
    self.root:stopAllActions()
end

function BaseDialog:animEnded()
    self.fgLayer:hide()
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

function BaseDialog:showFromTop(cb)
    cb = cb or function() end
    self:animStart()
    self.root:pos(0, display.height)
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineOut:create(cc.MoveTo:create(0.2, cc.p(0, 0))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissToTop(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineIn:create(cc.MoveTo:create(0.2, cc.p(0, display.height))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:showFromLeft(cb)
    cb = cb or function() end
    self:animStart()
    self.root:pos(-display.width, 0)
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineOut:create(cc.MoveTo:create(0.2, cc.p(0, 0))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissToLeft(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineIn:create(cc.MoveTo:create(0.2, cc.p(-display.width, 0))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:fadeIn(cb)
    cb = cb or function() end
    self:animStart()
    self.root:opacity(0)
    self.root:runAction(cc.Sequence:create({
        cc.FadeIn:create(0.2),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:fadeOut(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.FadeOut:create(0.2),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

return BaseDialog