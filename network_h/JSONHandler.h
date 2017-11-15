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
	str build_retrv_msg( std::string video_id, int order, int mat, int instruction );
	str build_instruction_msg( int instr );
	str build_empty();
	rapidjson::Value& get_value( c_char json, c_char json_key );

} /* namespace JHandler */

#endif /* NETWORK_H_JSONHANDLER_H_ */
