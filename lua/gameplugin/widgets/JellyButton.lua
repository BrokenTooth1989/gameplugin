--
-- Author: gaoyang
-- Date: 2017-02-07 17:05:10
--

local JellyButton = class("JellyButton", cc.ui.UIPushButton)

function JellyButton:ctor(params, options)
	JellyButton.super.ctor(self, params, options)
    self:addButtonPressedEventListener(handler(self, self.touchDown))
    self:addButtonReleaseEventListener(handler(self, self.touchUp))
end

function JellyButton:show()
	self:stopAllActions()
	self:scale(0)
    local rotation, scale, loopNum = 12, 0.5, 5
    local actions = {}
    for i=loopNum-1,0,-1 do
    	local r = rotation*i/loopNum
        r = i%2==0 and r or -r
        local s = scale*i/loopNum+1
        local sx = i%2==0 and s or 1
        local sy = i%2==0 and 1 or s
        local spawn = cc.Spawn:create({
        	cc.RotateTo:create(0.08, r),
        	cc.ScaleTo:create(0.08, sx, sy),
    	})
    	table.insert(actions, spawn)
    end
    self:runAction(cc.Sequence:create(actions))
end

function JellyButton:hide()
	self:stopAllActions()
	self:runAction(cc.Sequence:create({
		cc.ScaleTo:create(0.1, 0),
		cc.Hide:create(),
	}))
end

function JellyButton:touchDown()
    self:stopAllActions()
    self:runAction(cc.Sequence:create({
        cc.EaseElasticOut:create(cc.ScaleTo:create(0.5, 0.85)),
    }))
end

function JellyButton:touchUp()
    self:stopAllActions()
    self:runAction(cc.Sequence:create({
        cc.EaseElasticOut:create(cc.ScaleTo:create(0.5, 1)),
    }))
end

return JellyButton