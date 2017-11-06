#ifndef NETWORK_H_JSONHANDLER_H_
#define NETWORK_H_JSONHANDLER_H_

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>

typedef rapidjson::Document::AllocatorType& Alloc;
typedef rapidjson::Writer<rapidjson::StringBuffer> Writer;
typedef const char* c_char;
typedef std::string str;

namespace JHandler {

rapidjson::Value& get_value( c_char json, c_char json_key );

} /* namespace JHandler */

#endif /* NETWORK_H_JSONHANDLER_H_ */
