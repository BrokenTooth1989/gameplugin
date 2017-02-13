--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-04-28 18:17:18
--

local NodeUtil                  = class("NodeUtil")

local kDieJiaFangShi1           = "Diejia_Fangshi1"
local kDieJiaFangShi2           = "Diejia_Fangshi2"
local kDieJiaFangShi3           = "Diejia_Fangshi3"

function NodeUtil:ctor()
    self._dialogs               = {};
    self._dialogMaskLayer       = nil;
    self._rollInfos             = {}
    self._shakeInfos            = {}
end

-- 根据csb文件创建node
function NodeUtil:parseCsbFile(csbFile, isPlay, isLoop)
    isPlay = isPlay == nil and true or isPlay
    isLoop = isLoop == nil and true or isLoop
    
    local node      = cc.CSLoader:createNode(csbFile)
    node._action    = cc.CSLoader:createTimeline(csbFile)
    node:runAction(node._action)
    if isPlay then
        node._action:gotoFrameAndPlay(0, isLoop)
    else
        node._action:gotoFrameAndPause(0)
    end
        
    self:dealNode(node)

    return node
end

-- node处理
function NodeUtil:dealNode(node)
    local nodeType = tolua.type(node)
    if nodeType == "cc.ParticleSystemQuad" then
        node:setAutoRemoveOnFinish(true)
        node:setPositionType(cc.POSITION_TYPE_GROUPED)
    elseif nodeType == "cc.Sprite" then
        local name = node:getName()
        if string.sub(name, 1, #kDieJiaFangShi1) == kDieJiaFangShi1 then
            node:setBlendFunc(gl.DST_COLOR, gl.ONE)
        elseif string.sub(name, 1, #kDieJiaFangShi2) == kDieJiaFangShi2 then
            node:setBlendFunc(gl.ONE, gl.ONE)
        elseif string.sub(name, 1, #kDieJiaFangShi3) == kDieJiaFangShi3 then
            node:setBlendFunc(gl.SRC_ALPHA, gl.ONE)
        end
    elseif nodeType == "ccui.TextBMFont" then
        local languageCode = SystemUtil:getLanguageCode()
        local renderer = node:getVirtualRenderer()
        local fntPath = renderer:getBMFontFilePath()
        local newFntPath = string.sub(fntPath, 1, #fntPath-4).."_"..languageCode..".fnt"
        if cc.FileUtils:getInstance():isFileExist(newFntPath) then
            renderer:setBMFontFilePath(newFntPath)
        end
    end
    for i,child in ipairs(node:getChildren()) do
        self:dealNode(child)
    end
end

-- 根据路径获取节点，"Panel.Sprite.Label"
function NodeUtil:childWithPath(node, path)
    local paths = string.split(path, ".")
    for i,path in ipairs(paths) do
        node = node:getChildByName(path)
    end
    return node
end

-- 按钮启用
function NodeUtil:buttonEnable(...)
    for i,button in ipairs(arg) do
        button:setEnabled(true)
        button:setBright(true)
    end
end

-- 按钮禁用
function NodeUtil:buttonDisable(...)
    for i,button in ipairs(arg) do
        button:setEnabled(false)
        button:setBright(false)
    end
end

-- label自适应宽度
function NodeUtil:labelFix(label, width, str)
    label:setString(str)
    local currentWidth = label:getBoundingBox().width
    if currentWidth >= width then
        label:setScale(label:getScale()*width/currentWidth)
    end
end

-- imageview绑定
function NodeUtil:imageViewBind(imageview, url, path)
    local function bind(imageview, path)
        local textureCache = cc.Director:getInstance():getTextureCache()
        textureCache:addImageAsync(path, function(texture2d)
            imageview:loadTexture(path)
            imageview:release()--引用计数-1
        end)
    end
    imageview:retain()--引用计数+1
    imageview:setUnifySizeEnabled(false)
    imageview:ignoreContentAdaptWithSize(false)
    imageview._bindImage = nil
    local isExist = cc.FileUtils:getInstance():isFileExist(path)
    if isExist then
        bind(imageview, path)
        return
    end
    imageview._bindImage = url..path
    SystemUtil:downloadFile(url, path, function(first, second)
        if first == 0 then
            return
        end
        if first == 1 then
            if imageview._bindImage == url..path then
                bind(imageview, path)
            end
        else
            imageview:release()--引用计数-1
        end
    end)
end

-- 创建遮罩层，屏蔽touch事件
function NodeUtil:createMaskLayer(callback, alpha)
    callback = callback or function() end
    alpha = alpha or 150
    
    local maskLayer = display.newColorLayer(cc.c4b(0, 0, 0, alpha))
    local function onTouchBegan(touch, event)
        callback(touch, event)
        return true
    end
    local function onTouchMoved(touch, event)
        callback(touch, event)
    end
    local function onTouchEnded(touch, event)
        callback(touch, event)
    end
    local function onTouchCancelled(touch, event)
        callback(touch, event)
    end
    local listener = cc.EventListenerTouchOneByOne:create()
    listener:setSwallowTouches(true)
    listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN )
    listener:registerScriptHandler(onTouchMoved,cc.Handler.EVENT_TOUCH_MOVED )
    listener:registerScriptHandler(onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED )
    listener:registerScriptHandler(onTouchCancelled,cc.Handler.EVENT_TOUCH_CANCELLED )
    local eventDispatcher = maskLayer:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener, maskLayer)
    return maskLayer
end

-- 滚动
function NodeUtil:startRoll(node, duration, start, ended, callback)
    self:stopRoll(node)

    duration = duration or 1
    start = start or 1
    ended = ended or 10
    callback = callback or function() end

    local nodeType          = tolua.type(node)
    local offset            = ended-start
    local time              = 0
    local schedulerId       = nil

    node:retain()
    schedulerId = scheduler.scheduleUpdateGlobal(function(dt)
        time = time + dt
        local value
        if time >= duration then
            time = duration
            value = ended
        else
            value = time/duration*offset+start
        end
        if "ccui.TextBMFont" == nodeType 
            or "cc.Label" == nodeType then
            value = math.ceil(value)
            node:setString(string.formatNumThousands(value))
        elseif "ccui.LoadingBar" == nodeType
            or iskindof(node, "LoadingBar") then
            node:setPercent(value)
        end
        callback(value)
        if time >= duration then
            self:stopRoll(node)
        end
    end)
    self._rollInfos[node] = schedulerId
end

function NodeUtil:stopRoll(node)
    local schedulerId = self._rollInfos[node]
    if schedulerId == nil then return end
    node:release()
    scheduler.unscheduleGlobal(schedulerId)
    self._rollInfos[node] = nil
end

function NodeUtil:startShake(nodes, sx, sy)
    self:stopShake(nodes)

    sx = sx or 5
    sy = sy or 5

    local originPos = {}
    for i,node in ipairs(nodes) do
        table.insert(originPos, {node:getPosition()})
    end
    schedulerId = scheduler.scheduleGlobal(function(dt)
        local randx     = math.random(-sx, sx)
        local randy     = math.random(-sy, sy)
        for i,node in ipairs(nodes) do
            local posx      = originPos[i][1]
            local posy      = originPos[i][2]
            node:setPosition(posx+randx, posy+randy)
        end
    end, 0.03)
    self._shakeInfos[nodes] = {schedulerId, originPos}
end

function NodeUtil:stopShake(nodes)
    local shakeInfo = self._shakeInfos[nodes]
    if shakeInfo == nil then return end
    local schedulerId = shakeInfo[1]
    local originPos = shakeInfo[2]
    scheduler.unscheduleGlobal(schedulerId)
    for i,node in ipairs(nodes) do
        node:setPosition(unpack(originPos[i]))
    end
    self._shakeInfos[nodes] = nil
end

-- 检测是否点中
function NodeUtil:checkTouch(node, position)
    local cbb = node:getCascadeBoundingBox()
    if cc.rectContainsPoint(cbb, position) then
        return true
    else
        return false
    end
end

-- 改变锚点
function NodeUtil:changeAnchorPoint(node, anchorPoint) 
    local oldAnchorPoint = node:getAnchorPoint()
    local offsetAnchorPoint = cc.pSub(anchorPoint, oldAnchorPoint)
    local nodeSize = node:getContentSize()
    local offsetPoint = cc.p(offsetAnchorPoint.x*nodeSize.width, offsetAnchorPoint.y*nodeSize.height)
    node:setAnchorPoint(anchorPoint)
    node:setPosition(cc.pAdd(cc.p(node:getPosition()), offsetPoint))
end

-- 改变父节点
function NodeUtil:changeParent(node, parent)
    if node:getParent() == parent then return end
    -- 计算坐标
    local worldPoint    = node:convertToWorldSpaceAR(cc.p(0, 0))
    local nodePoint     = parent:convertToNodeSpace(worldPoint)
    -- 计算缩放
    local scale         = 1
    local tempNode      = node
    while true do
        if tempNode == nil then break end
        scale = scale*tempNode:getScale()
        tempNode = tempNode:getParent()
    end
    local tempParent    = parent
    while true do
        if tempParent == nil then break end
        scale = scale/tempParent:getScale()
        tempParent = tempParent:getParent()
    end
    -- 更改父节点
    node:retain()
    node:removeFromParent(false)
    node:addTo(parent):pos(nodePoint.x, nodePoint.y):scale(scale)
    node:release()
end

-- 显示弹框
function NodeUtil:pushDialog(dialog, callback)
    callback = callback or function() print("pushDialog callback is nil") end
    -- 增加遮罩层
    if self._dialogMaskLayer == nil then
        local dialogMaskLayer = cc.LayerColor:create(cc.c4b(0, 0, 0, 180))
        local listener = cc.EventListenerTouchOneByOne:create()
        listener:setSwallowTouches(true)
        listener:registerScriptHandler(function()return true; end, cc.Handler.EVENT_TOUCH_BEGAN)
        dialogMaskLayer:getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, dialogMaskLayer)
        display.getRunningScene():addChild(dialogMaskLayer, 1000)
        self._dialogMaskLayer = dialogMaskLayer
    end
    dialog:retain()
    local function addDialog()
        table.insert(self._dialogs, dialog)
        display.getRunningScene():addChild(dialog, 1001)
        dialog:setPosition(display.cx, display.cy)
        dialog:runInAnim(callback)
        dialog:release()
    end
    if #self._dialogs > 0 then
        local topDialog = self._dialogs[#self._dialogs]
        topDialog:runOutAnim(function()
            topDialog:hide()
            addDialog()
        end)
    else
        addDialog()
    end
end

-- 关闭弹框
function NodeUtil:popDialog(callback)
    callback = callback or function() print("popDialog callback is nil") end
    if #self._dialogs <= 0 then
        return
    end
    local topDialog = self._dialogs[#self._dialogs]
    table.remove(self._dialogs, #self._dialogs)
    topDialog:runOutAnim(function()
        topDialog:removeFromParent(true)
        callback()
        if #self._dialogs > 0 then
            local dialog = self._dialogs[#self._dialogs]
            dialog:show()
            dialog:runInAnim()
        else
            self._dialogMaskLayer:removeFromParent(true)
            self._dialogMaskLayer = nil
        end
    end)
end

-- 多语言适配
function NodeUtil:updateContent(node, configs)
    local languageCode = GamePlugin:getLanguageCode()
    local content = configs[languageCode] or configs["default"]
    local nodeType = tolua.type(node)
    if nodeType == "cc.Sprite" then
        node:setSpriteFrame(content)
    elseif nodeType == "ccui.TextBMFont" then
        node:setString(content)
    end
end

return NodeUtil







