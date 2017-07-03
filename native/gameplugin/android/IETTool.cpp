#include "IETTool.h"

rapidjson::Document oWriteDoc;

void IETTool::addObjectToJson(const std::string& key, const cocos2d::Value& value, rapidjson::StringBuffer& oBuffer)
{

	// log("call IETTool::addObjectToJson");

	// log("key : %s  - value : %s",key.c_str(),value.asString().c_str());

	
    rapidjson::Document::AllocatorType& allocator = oWriteDoc.GetAllocator();
    

    if (value.getType() == Value::Type::MAP)
    {
        rapidjson::Value oArray(rapidjson::kArrayType);
        rapidjson::StringBuffer buffer;
        ValueMap subDict = value.asValueMap();
        for (auto iter = subDict.begin(); iter != subDict.end(); ++iter)
        {
            addObjectToJson(iter->first, iter->second, buffer);
        }
        
        oWriteDoc.AddMember(key.c_str(), buffer.GetString(), allocator);
        return;
    }

	if (value.getType() == Value::Type::FLOAT) {
    	oWriteDoc.AddMember(key.c_str(), value.asFloat(), allocator);
	}

	if (value.getType() == Value::Type::STRING) {
    	oWriteDoc.AddMember(key.c_str(), value.asString().c_str(), allocator);
	}

	if (value.getType() == Value::Type::INTEGER) {
    	oWriteDoc.AddMember(key.c_str(), value.asInt(), allocator);
	}

	if (value.getType() == Value::Type::DOUBLE) {
    	oWriteDoc.AddMember(key.c_str(), value.asDouble(), allocator);
	}

	if (value.getType() == Value::Type::BOOLEAN) {
    	oWriteDoc.AddMember(key.c_str(), value.asBool(), allocator);
	}


    // log("1 oWriter %s",oBuffer.GetString());

}


const char* IETTool::valueMapToJson(cocos2d::ValueMap map)
{

	// log("call IETTool::valueMapToJson :%d",map.size());
	rapidjson::StringBuffer oBuffer;

    oWriteDoc.SetObject();

	for (auto iter = map.begin(); iter != map.end(); ++iter)
    {
        addObjectToJson(iter->first,iter->second,oBuffer);
    }

    rapidjson::Writer<rapidjson::StringBuffer> oWriter(oBuffer);
    oWriteDoc.Accept(oWriter);

	// log("2 oWriter %s",oBuffer.GetString());
	return oBuffer.GetString();
}

