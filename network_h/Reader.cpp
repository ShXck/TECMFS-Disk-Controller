
#include "Reader.h"

namespace network {

Reader::Reader() { }

Processed_Tmp Reader::read( std::string msg ) {

	std::string dec_msg = m_compressor.decompress( msg );

	std::cout << dec_msg << std::endl;

	int _instruction = JHandler::get_value( dec_msg.c_str(), "instruction" ).GetInt();

	switch( _instruction ) {
		case STORE_INSTR: {
			std::string binary_data = JHandler::get_value( dec_msg.c_str(), "data" ).GetString();
			std::string video_id = JHandler::get_value( dec_msg.c_str(), "id" ).GetString();
			int _order = JHandler::get_value( dec_msg.c_str(), "order" ).GetInt();
			return Processed_Tmp( _instruction, _order, binary_data, video_id );
		}
		case RETRV_INSTR: {
			//retrieve code.
			break;
		}
	}
	return Processed_Tmp::mock();
}

Reader::~Reader() { }

} /* namespace network */
