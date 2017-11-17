--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-11-01 22:14:28
--

local BaseDialog = class("BaseDialog", function()
	return display.newNode()
end)

function BaseDialog:ctor(rootPos)
    self.rootPos = rootPos or cc.p(0, 0)
    
    self.m_scaleFactor = 1

    -- background layer
    local bgLayer = cc.LayerColor:create(cc.c4b(0, 0, 0, 150))
        :zorder(-1)
        :addTo(self)
    self.bgLayer = bgLayer
    
    -- background layer touch event
    local bgLayerListener = cc.EventListenerTouchOneByOne:create()
    bgLayerListener:setSwallowTouches(true)
    bgLayerListener:registerScriptHandler(function(touch, event)
        return self:isVisible()
    end, cc.Handler.EVENT_TOUCH_BEGAN)
    bgLayer:getEventDispatcher():addEventListenerWithSceneGraphPriority(bgLayerListener, bgLayer)
    self.bgLayerListener = bgLayerListener
    
    -- create root node
    local root = display.newNode()
        :pos(self.rootPos.x, self.rootPos.y)
        :addTo(self)
    self.root = root
    
    -- foreground layer
    local fgLayer = display.newColorLayer(cc.c4b(0, 0, 0, 0))
        :zorder(1)
        :addTo(self)
    self.fgLayer = fgLayer

    -- foreground layer touch event
    local fgLayerListener = cc.EventListenerTouchOneByOne:create()
    fgLayerListener:setSwallowTouches(true)
    fgLayerListener:registerScriptHandler(function(touch, event)
        return self:isVisible()
    end, cc.Handler.EVENT_TOUCH_BEGAN)
    fgLayer:getEventDispatcher():addEventListenerWithSceneGraphPriority(fgLayerListener, fgLayer)
    self.fgLayerListener = fgLayerListener

    -- 默认关闭前置Layer的touch事件
    fgLayerListener:setEnabled(false)

    -- 开启onEnter和onExit等生命周期函数
    self:setNodeEventEnabled(true)
end

function BaseDialog:runEnterAnim(_cb)
    _cb()
end

function BaseDialog:startRunning()
    
end

function BaseDialog:stopRunning()
    
end

function BaseDialog:runExitAnim(_cb)
    _cb()
end

function BaseDialog:setCloseCb(_cb)
    self.m_closeCb = _cb
end

function BaseDialog:closeMe(_msg)
    if self.m_closeCb then
        self.m_closeCb(_msg)
    end
end

function BaseDialog:setBgOpacity(opacity)
    self.bgLayer:setOpacity(opacity)
end

function BaseDialog:setScaleFactor(_scaleFactor)
    self.m_scaleFactor = _scaleFactor
    self.root:scale(self.m_scaleFactor)
end

function BaseDialog:animStart()
    self.fgLayerListener:setEnabled(true)
    self.root:stopAllActions()
end

function BaseDialog:animEnded()
    self.fgLayerListener:setEnabled(false)
end

function BaseDialog:showEaseScale(cb)
	cb = cb or function() end
    self:animStart()
	self.root:scale(0)
    self.root:runAction(cc.Sequence:create({
        cc.EaseBackOut:create(cc.ScaleTo:create(0.3, self.m_scaleFactor)),
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
    self.root:pos(self.rootPos.x, self.rootPos.y-display.height)
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineOut:create(cc.MoveTo:create(0.3, self.rootPos)),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissToBottom(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineIn:create(cc.MoveTo:create(0.3, cc.p(self.rootPos.x, self.rootPos.y-display.height))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:showFromRight(cb)
    cb = cb or function() end
    self:animStart()
    self.root:pos(self.rootPos.x+display.width, self.rootPos.y)
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineOut:create(cc.MoveTo:create(0.2, self.rootPos)),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissToRight(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineIn:create(cc.MoveTo:create(0.2, cc.p(self.rootPos.x+display.width, self.rootPos.y))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:showFromTop(cb)
    cb = cb or function() end
    self:animStart()
    self.root:pos(self.rootPos.x, self.rootPos.y+display.height)
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineOut:create(cc.MoveTo:create(0.2, self.rootPos)),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissToTop(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineIn:create(cc.MoveTo:create(0.2, cc.p(self.rootPos.x, self.rootPos.y+display.height))),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:showFromLeft(cb)
    cb = cb or function() end
    self:animStart()
    self.root:pos(self.rootPos.x-display.width, self.rootPos.y)
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineOut:create(cc.MoveTo:create(0.2, self.rootPos)),
        cc.CallFunc:create(handler(self, self.animEnded)),
        cc.CallFunc:create(cb),
    }))
end

function BaseDialog:dismissToLeft(cb)
    cb = cb or function() end
    self:animStart()
    self.root:runAction(cc.Sequence:create({
        cc.EaseSineIn:create(cc.MoveTo:create(0.2, cc.p(self.rootPos.x-display.width, self.rootPos.y))),
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