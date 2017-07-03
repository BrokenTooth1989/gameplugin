
#ifndef gameplugin_IETTool_h
#define gameplugin_IETTool_h


#include "cocos2d.h"

#include "json/rapidjson.h"
#include "json/writer.h"
#include "json/document.h"
#include "json/prettywriter.h"
#include "json/stringbuffer.h"


USING_NS_CC;

class IETTool{
private:

	static void addObjectToJson(const std::string& key, const cocos2d::Value& value, rapidjson::StringBuffer& oBuffer);
public:

	static const char* valueMapToJson(cocos2d::ValueMap map);

};

#endif