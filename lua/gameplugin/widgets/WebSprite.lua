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
opts.url 图片链接
opts.disk 图片路径
]]
function WebSprite:ctor(opts)
	assert(opts.default)

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
	if opts.url then
		self:loadFromUrl(opts.url)
	elseif opts.disk then
		self:loadFromDisk(opts.disk)
	end
end

function WebSprite:loadFromUrl(url, cb)
	if url == nil then return end
	self.url = url
	cb = cb or function() end

	local function bind(path)
		self:loadFromDisk(path)
		cb(true)
	end
	local path = imagePath..crypto.md5(url)
	if fileutils:isFileExist(path) then
		return bind(path)
	end
	self:retain()
	SystemUtil:downloadFile(url, path, function(param1, param2)
		if param1 == 0 then
			-- show download percent
		else
			if param1 == -1 then
				cb(false)
			elseif param1 == 1 then
				if self.url == url then
                	bind(path)
            	end
        	end
        	self:release()
        end
	end)
end

function WebSprite:loadFromDisk(path)
	local sprite = display.newSprite(path)
	local frame = sprite:getSpriteFrame()
	self.sprite:setSpriteFrame(frame)
	local size = self.sprite:getContentSize()
	self.sprite:setScale(self.size.width/size.width, self.size.height/size.height)
end

return WebSprite