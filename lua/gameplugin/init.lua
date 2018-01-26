--
-- Author: geekgaoyang@gmail.com
-- Date: 2015-02-18 11:15:07
--

cc.FileUtils:getInstance():addSearchPath("gameplugin")

-- 设备类型
device.aspect_ratio = display.widthInPixels/display.heightInPixels
if device.aspect_ratio >= 3/4 then
    device.type = "ipad"
elseif device.aspect_ratio >= 2/3 then
	device.type = "iphone4"
else
	device.type = "iphone5"
end
printInfo(string.format("# display.type                 = %s", device.type))

-- set random seed
math.randomseed(tostring(os.time()):reverse():sub(1, 6))  
math.random()
math.random()
math.random()
math.random()
math.random()

-- enhance
require("enhance")

-- third part
require("libs.quick.shortcodes")
scheduler 			= require("libs.quick.scheduler")
StateMachine 		= require("libs.quick.StateMachine")
url 				= require("libs.url.url")
deferred 			= require("libs.deferred.deferred")
inspect 			= require("libs.inspect.inspect")
lume 				= require("libs.lume.lume")
MessagePack 		= require("libs.msgpack.MessagePack")

-- utils export from cpp
GamePlugin 			= ccg.IETGamePlugin:getInstance()
SystemUtil 			= ccg.IETSystemUtil:getInstance()
AnalyticHelper 		= ccg.IETAnalyticHelper:getInstance()
AdvertiseHelper		= ccg.IETAdvertiseHelper:getInstance()
AmazonAWSHelper 	= ccg.IETAmazonAWSHelper:getInstance()
FacebookHelper 		= ccg.IETFacebookHelper:getInstance()

-- utils
NodeUtil 			= require("utils.NodeUtil").new()
ActionUtil 			= require("utils.ActionUtil").new()
DataUtil 			= require("utils.DataUtil").new()
AudioUtil 			= require("utils.AudioUtil").new()
NotifyUtil 			= require("utils.NotifyUtil").new()
TimerUtil 			= require("utils.TimerUtil").new()
FacebookUtil 		= require("utils.FacebookUtil").new()
CsvUtil 			= require("utils.CsvUtil").new()

-- widgets
UIBaseDialog 		= require("widgets.BaseDialog")
UISwitchButton 		= require("widgets.SwitchButton")
UINavigationDot 	= require("widgets.NavigationDot")
UILoadingBar 		= require("widgets.LoadingBar")
UIWebSprite 		= require("widgets.WebSprite")
UIScratchSprite 	= require("widgets.ScratchSprite")
UIJellyButton 		= require("widgets.JellyButton")
