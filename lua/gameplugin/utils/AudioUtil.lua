--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-02-20 11:28:02
--

local AudioUtil             = class("AudioUtil")

-- 音乐开关以及默认值
local kMusic                = "__MUSIC"
local kMusicDefault         = 1
-- 音效开关以及默认值
local kEffect               = "__EFFECT"
local kEffectDefault        = 1
-- 是否使用新引擎
local kUseNewEngine         = false

function AudioUtil:ctor()
    if kUseNewEngine then
        self._musicId = -1
        self._effectIds = {}
    end
    self:setMusic(self:getMusic())
    self:setEffect(self:getEffect())
end

-- 缓存
function AudioUtil:cache(sounds)
    
end

-- 清除缓存
function AudioUtil:uncache(sounds)
    if kUseNewEngine then
        if sounds == nil then
            ccexp.AudioEngine:uncacheAll()
        else
            for i,sound in ipairs(sounds) do
                ccexp.AudioEngine:uncache(sound)
            end
        end
    end
end

-- 设置音乐大小
function AudioUtil:setMusic(volume)
    DataUtil:setValueWithId(kMusic, volume)
    DataUtil:flush()
    if kUseNewEngine then
        ccexp.AudioEngine:setVolume(self._musicId, volume)
    else
        AudioEngine.setMusicVolume(volume)
    end
    if volume <= 0 then
        self:stopMusic()
    end
    self.musicListeners = self.musicListeners or {}
    for i,listener in ipairs(self.musicListeners) do
        listener(volume)
    end
end

-- 获取音乐大小
function AudioUtil:getMusic()
    return DataUtil:getValueWithId(kMusic, kMusicDefault)
end

-- 增加音量变化监听
function AudioUtil:addMusicListener(listener)
    self.musicListeners = self.musicListeners or {}
    if not table.containsElement(self.musicListeners, listener) then
        table.insert(self.musicListeners, listener)
        return listener
    end
    return nil
end

-- 删除音量变化监听
function AudioUtil:delMusicListener(listener)
    self.musicListeners = self.musicListeners or {}
    local index = table.containsElement(self.musicListeners, listener)
    if index then
        table.remove(self.musicListeners, index)
    end
end

-- 设置音效大小
function AudioUtil:setEffect(volume)
    DataUtil:setValueWithId(kEffect, volume)
    DataUtil:flush()
    if kUseNewEngine then
        for i,_effectId in ipairs(self._effectIds) do
            ccexp.AudioEngine:setVolume(_effectId, volume)
        end
    else
        AudioEngine.setEffectsVolume(volume)
    end
    if volume <= 0 then
        self:stopAllEffect()
    end
    self.effectListeners = self.effectListeners or {}
    for i,listener in ipairs(self.effectListeners) do
        listener(volume)
    end
end

-- 获取音效大小
function AudioUtil:getEffect()
    return DataUtil:getValueWithId(kEffect, kEffectDefault)
end

-- 增加音效变化监听
function AudioUtil:addEffectListener(listener)
    self.effectListeners = self.effectListeners or {}
    if not table.containsElement(self.effectListeners, listener) then
        table.insert(self.effectListeners, listener)
        return listener
    end
    return nil
end

-- 删除音效变化监听
function AudioUtil:delEffectListener(listener)
    self.effectListeners = self.effectListeners or {}
    local index = table.containsElement(self.effectListeners, listener)
    if index then
        table.remove(self.effectListeners, index)
    end
end

-- 播放音乐，是否循环
function AudioUtil:playMusic(filename, isLoop)
    isLoop = isLoop or true
    if kUseNewEngine then
        self:stopMusic()
        self._musicId = ccexp.AudioEngine:play2d(filename, true, self:getMusic())
    else
        self:stopMusic()
        AudioEngine.playMusic(filename, isLoop)
    end
end

-- 暂停音乐
function AudioUtil:pauseMusic()
    if kUseNewEngine then
        if self._musicId == -1 then return end
        local musicId = self._musicId
        self:setSoundVolumeSmoth(musicId, 0, function()
            ccexp.AudioEngine:pause(musicId)
        end)
    else
        AudioEngine.pauseMusic()
    end
end

-- 恢复音乐
function AudioUtil:resumeMusic()
    if kUseNewEngine then
        if self._musicId == -1 then return end
        local musicId = self._musicId
        self:setSoundVolumeSmoth(musicId, self:getMusic(), function()
            ccexp.AudioEngine:resume(musicId)
        end)
    else
        AudioEngine.resumeMusic()
    end
end

-- 重新播放音乐
function AudioUtil:rewindMusic()
    if kUseNewEngine then
        if self._musicId == -1 then return end
        ccexp.AudioEngine:setCurrentTime(self._musicId, 0)
    else
        AudioEngine.rewindMusic()
    end
end

-- 停止音乐
function AudioUtil:stopMusic()
    if kUseNewEngine then
        if self._musicId == -1 then return end
        local musicId = self._musicId
        self:setSoundVolumeSmoth(musicId, 0, function()
            ccexp.AudioEngine:stop(musicId)
        end)
    else
        AudioEngine.stopMusic(true)
    end
end

-- 播放音效
function AudioUtil:playEffect(filename, isLoop)
    if self:getEffect() <= 0 then return end
    isLoop = isLoop or false
    local effectId = nil
    if kUseNewEngine then
        effectId = ccexp.AudioEngine:play2d(filename, isLoop, self:getEffect())
        ccexp.AudioEngine:setFinishCallback(effectId, function()
            table.removebyvalue(self._effectIds, effectId, true)
        end)
        table.insert(self._effectIds, effectId)
    else
        effectId = AudioEngine.playEffect(filename, isLoop)
    end
    return effectId
end

-- 暂停某一个音效
function AudioUtil:pauseEffect(effectId)
    if kUseNewEngine then
        self:setSoundVolumeSmoth(effectId, 0, function()
            ccexp.AudioEngine:pause(effectId)
        end)
    else
        AudioEngine.pauseEffect(effectId)
    end
end

-- 恢复某一个音效
function AudioUtil:resumeEffect(effectId)
    if kUseNewEngine then
        self:setSoundVolumeSmoth(effectId, self:getEffect(), function()
            ccexp.AudioEngine:resume(effectId)
        end)
    else
        AudioEngine.resumeEffect(effectId)
    end
end

-- 停止某一个音效
function AudioUtil:stopEffect(effectId)
    if effectId == nil then return end
    if kUseNewEngine then
        for idx,_effectId in ipairs(self._effectIds) do
            if _effectId == effectId then
                self:setSoundVolumeSmoth(effectId, 0, function()
                    ccexp.AudioEngine:stop(effectId)
                    table.removebyvalue(self._effectIds, effectId, true)
                end)
            end
        end
    else
        AudioEngine.stopEffect(effectId)
    end
end

-- 暂停所有音效
function AudioUtil:pauseAllEffect()
    if kUseNewEngine then
        for i,_effectId in ipairs(self._effectIds) do
            self:setSoundVolumeSmoth(_effectId, 0, function()
                ccexp.AudioEngine:pause(_effectId)
            end)
        end
    else
        AudioEngine.pauseAllEffects()
    end
end

-- 恢复所有音效
function AudioUtil:resumeAllEffect()
    if kUseNewEngine then
        for i,_effectId in ipairs(self._effectIds) do
            self:setSoundVolumeSmoth(_effectId, self:getEffect(), function()
                ccexp.AudioEngine:resume(_effectId)
            end)
        end
    else
        AudioEngine.resumeAllEffects()
    end
end

-- 停止所有音效
function AudioUtil:stopAllEffect()
    if kUseNewEngine then
        for i,_effectId in ipairs(self._effectIds) do
            self:stopEffect(_effectId)
        end
    else
        AudioEngine.stopAllEffects()
    end
end

-- 平滑变化音量(仅适用新引擎)
function AudioUtil:setSoundVolumeSmoth(soundId, newVolume, callback)
    callback = callback or function() end
    local stepNum = 10
    local volume = ccexp.AudioEngine:getVolume(soundId)
    local offset = (newVolume - volume)/stepNum
    local schedulerId = nil
    schedulerId = scheduler.scheduleGlobal(function(dt)
        if stepNum <= 0 then
            ccexp.AudioEngine:setVolume(soundId, newVolume)
            scheduler.unscheduleGlobal(schedulerId)
            callback()
        else
            volume = volume + offset
            ccexp.AudioEngine:setVolume(soundId, volume)
        end
        stepNum = stepNum - 1
    end, 0.05)
end

return AudioUtil
