--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-06-08 10:19:51
--

local ActionUtil                  = class("ActionUtil")

function ActionUtil:ctor()
	
end

--0 -> 1.2 -> 1
function ActionUtil:easeScale1(node, callback)
    callback = callback or function() end
    node:show()
    node:setScale(0)
    local scale = cc.EaseBackOut:create(cc.ScaleTo:create(0.3,1))
    local callfunc = cc.CallFunc:create(callback)
    node:runAction(cc.Sequence:create(scale, callfunc))
end

-- 1 -> 1.2 -> 0
function ActionUtil:easeScale0(node, callback)
    callback = callback or function() end
    node:show()
    node:setScale(1)
    local scale = cc.EaseBackIn:create(cc.ScaleTo:create(0.3,0))
    local callfunc = cc.CallFunc:create(callback)
    node:runAction(cc.Sequence:create(scale, callfunc))
end

function ActionUtil:fadeTo(node, opacity, callback)
    callback = callback or function() end
    node:show()
    local fade = cc.FadeTo:create(0.3, opacity)
    local callfunc = cc.CallFunc:create(callback)
    node:runAction(cc.Sequence:create(fade, callfunc))
end

-- slow -> fast -> slow
function ActionUtil:easeMoveInOut(node, pos, callback)
    callback = callback or function() end
    node:show()
    local move = cc.EaseSineInOut:create(cc.MoveTo:create(0.3, pos))
    local callfunc = cc.CallFunc:create(callback)
    node:runAction(cc.Sequence:create(move, callfunc))
end

function ActionUtil:blink(node, times, callback)
    callback = callback or function() end
    node:show()
    local blink = cc.Blink:create(times*0.3, times)
    local callfunc = cc.CallFunc:create(callback)
    node:runAction(cc.Sequence:create(blink, callfunc))
end

function ActionUtil:rotateShake(node, times, callback)
    callback = callback or function() end
    node:runAction(cc.Sequence:create(
        cc.Repeat:create(cc.Sequence:create(
            cc.RotateBy:create(0.03, 5),
            cc.RotateBy:create(0.03, -5),
            cc.RotateBy:create(0.03, -5),
            cc.RotateBy:create(0.03, 5)
        ), times),
        cc.CallFunc:create(callback)
    ))
end

return ActionUtil


