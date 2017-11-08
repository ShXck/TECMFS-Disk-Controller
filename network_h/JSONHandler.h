#ifndef NETWORK_H_JSONHANDLER_H_
#define NETWORK_H_JSONHANDLER_H_

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
#include <vector>

typedef rapidjson::Document JDocument;
typedef rapidjson::Document::AllocatorType& Alloc;
typedef rapidjson::Writer<rapidjson::StringBuffer> Writer;
typedef const char* c_char;
typedef std::string str;

namespace JHandler {

	str build_store_ret_msg( std::vector<str> blocks_used, int instruction );
	rapidjson::Value& get_value( c_char json, c_char json_key );

} /* namespace JHandler */

#endif /* NETWORK_H_JSONHANDLER_H_ */
