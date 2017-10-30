#include "XMLHandler.h"


namespace XHandler {

	std::string get_attribute( std::string attr, std::string file_path ) {

		XDocument _doc;
		XNode* root_node;

		std::ifstream _file( file_path );
		std::vector<char> _buffer( ( std::istreambuf_iterator<char>( _file ) ), std::istreambuf_iterator<char>() );
		_buffer.push_back( '\0' );
		_doc.parse<0>( &_buffer[0] );

		root_node = _doc.first_node( "TECMFS_Config_File" );

		XNode* config_node = root_node->first_node( "config" );

		return config_node->first_attribute( attr.c_str() )->value();
	}
} /* namespace XHandler */
