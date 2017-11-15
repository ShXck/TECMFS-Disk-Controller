#include "JSONHandler.h"

namespace JHandler {

	str build_store_ret_msg( std::vector<str> blocks_used, int instruction ) {

		JDocument _doc;
		_doc.SetObject();
		Alloc _alloc = _doc.GetAllocator();
		rapidjson::Value _array( rapidjson::kArrayType );

		for( unsigned int i = 0; i < blocks_used.size(); i++ ) {
			rapidjson::Value str_val;
			str_val.SetString( blocks_used[i].c_str(), _alloc );
			_array.PushBack( str_val, _alloc );
		}

		_doc.AddMember( "blocks", _array, _alloc );
		_doc.AddMember( "instruction", instruction, _alloc );

		rapidjson::StringBuffer str_buffer;
		Writer _writer( str_buffer );
		_doc.Accept( _writer );

		return str_buffer.GetString();
	}

	str build_retrv_msg( std::string video_id, int order, int mat, int instruction ) {

		JDocument _doc;
		_doc.SetObject();
		Alloc _alloc = _doc.GetAllocator();

		{
			rapidjson::Value str_id;
			str_id.SetString( video_id.c_str(), _alloc );
			_doc.AddMember( "id", str_id, _alloc );
		}

		_doc.AddMember( "instruction", instruction, _alloc );
		_doc.AddMember( "order", order, _alloc );
		_doc.AddMember( "mat", mat, _alloc );

		rapidjson::StringBuffer str_buffer;
		Writer _writer( str_buffer );
		_doc.Accept( _writer );

		return str_buffer.GetString();

	}

	str build_instruction_msg( int instr ) {
		JDocument _doc;
		_doc.SetObject();
		Alloc _alloc = _doc.GetAllocator();

		_doc.AddMember( "instruction", instr, _alloc );

		rapidjson::StringBuffer str_buffer;
		Writer _writer( str_buffer );
		_doc.Accept( _writer );

		return str_buffer.GetString();
	}

	str build_empty() {
		JDocument _doc;
		_doc.SetObject();
		Alloc _alloc = _doc.GetAllocator();

		_doc.AddMember( "data", 0, _alloc );

		rapidjson::StringBuffer str_buffer;
		Writer _writer( str_buffer );
		_doc.Accept( _writer );

		return str_buffer.GetString();
	}

	rapidjson::Value& get_value( c_char json, c_char json_key ) {

		JDocument _doc;
		_doc.Parse( json );

		Alloc _alloc = _doc.GetAllocator();

		rapidjson::Value str_key;
		str_key.SetString( json_key, _alloc );

		rapidjson::Value& _val = _doc[ str_key ];

		return _val;
	}


} /* namespace JHandler */
