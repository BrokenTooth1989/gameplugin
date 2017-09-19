--
-- Author: gaoyang
-- Date: 2016-12-16 18:49:13
--

local fileutils = cc.FileUtils:getInstance()
local writablePath = fileutils:getWritablePath()
local imagePath = string.format("%simages/", writablePath)
if not fileutils:isDirectoryExist(imagePath) then
	fileutils:createDirectory(imagePath)
end

local WebSprite = class("WebSprite", function()
	return display.newNode()
end)

--[[
opts.stencil 裁切
opts.default 默认图
opts.percent 进度图
opts.url 图片链接
opts.disk 图片路径
opts.retry 下载失败重试次数
]]
function WebSprite:ctor(opts)
	assert(opts.default)
	
	opts.retry = opts.retry or 5

	self.opts = opts

	local clipNode
	if opts.stencil ~= nil then
		local stencil = display.newSprite(opts.stencil)
		clipNode = cc.ClippingNode:create(stencil)
    		:addTo(self)
    	clipNode:setAlphaThreshold(0.5)
	else
		clipNode = display.newNode()
			:addTo(self)
	end
	self.sprite = display.newSprite(opts.default)
		:addTo(clipNode)
	self.size = self.sprite:getContentSize()
	if self.opts.percent ~= nil then
		self.progressBar = display.newProgressTimer(self.opts.percent, display.PROGRESS_TIMER_RADIAL)
			:opacity(0)
			:addTo(clipNode)
		self.progressBar:setScaleX(-1)
		self.progressBar:setPercentage(100)
	end
	if opts.url then
		self:loadFromUrl(opts.url)
	elseif opts.disk then
		self:loadFromDisk(opts.disk)
	end
end

function WebSprite:loadFromUrl(url)
	if url == nil then 
		return
	end

	if not string.match(url, "http") then
		return
	end

	self.url = url

	local function bind(path)
		if self.progressBar ~= nil then
			self.progressBar:setPercentage(0)
			self.progressBar:stopAllActions()
			self.progressBar:runAction(cc.FadeOut:create(0.3))
		end
		self:loadFromDisk(path)
	end

	local path = imagePath..crypto.md5(url)
	if fileutils:isFileExist(path) then
		return bind(path)
	end
	
	local function download(url, path, retryNum, cb)
		if self.progressBar ~= nil then
			self.progressBar:setPercentage(100)
			self.progressBar:stopAllActions()
			self.progressBar:runAction(cc.FadeIn:create(0.3))
		end
		SystemUtil:downloadFile(url, path, function(param1, param2)
			if param1 == 0 then
				if self.url ~= url then 
					return
				end
				if self.progressBar ~= nil then
					self.progressBar:setPercentage(100-param2)
				end
			elseif param1 == -1 then
				if self.url ~= url then
					return cb()
				end
				if retryNum <= 0 then
					if self.progressBar ~= nil then
						self.progressBar:setPercentage(0)
						self.progressBar:stopAllActions()
						self.progressBar:runAction(cc.FadeOut:create(0.3))
					end
					return cb()
				end
				scheduler.performWithDelayGlobal(function()
					download(url, path, retryNum-1, cb)
				end, 0)
			elseif param1 == 1 then
				if self.url ~= url then
                	return cb()
            	end
            	bind(path)
            	cb()
        	end
		end)
	end
	self.url = url
	self:retain()
	download(url, path, self.opts.retry, function(success)
		self:release()
	end)
end

function WebSprite:loadFromDisk(path)
	if path == nil then 
		print(path.."    is nil")
		return
	end
	if not cc.FileUtils:getInstance():isFileExist(path) then
		print(path.."    not exist")
		return
	end
	local sprite = cc.Sprite:create(path)
	if not sprite then
		print(path.."    new sprite failed")
		cc.FileUtils:getInstance():removeFile(path)
		self:loadFromUrl(self.url)
		return
	end
	local frame = sprite:getSpriteFrame()
	self.sprite:setSpriteFrame(frame)
	local size = self.sprite:getContentSize()
	self.sprite:setScale(self.size.width/size.width, self.size.height/size.height)
end

function WebSprite:loadFromApp(path)
	local sprite = display.newSprite(path)
	local frame = sprite:getSpriteFrame()
	self.sprite:setSpriteFrame(frame)
end

function WebSprite:reset()
	self.sprite:setSpriteFrame(display.newSprite(self.opts.default):getSpriteFrame())
	self.sprite:setScale(1)
	self.url = nil
end

return WebSprite