#include "JSONHandler.h"

namespace JHandler {

	rapidjson::Value& get_value( c_char json, c_char json_key ) {
		rapidjson::Document _doc;
		_doc.Parse( json );

		Alloc _alloc = _doc.GetAllocator();

		rapidjson::Value str_key;
		str_key.SetString( json_key, _alloc );

		rapidjson::Value& _val = _doc[ str_key ];

		return _val;
	}


} /* namespace JHandler */
