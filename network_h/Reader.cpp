
#include "Reader.h"

namespace network {

Reader::Reader() { }

Processed_Tmp Reader::read( sf::Packet packet ) {

	std::string dec_msg;
	std::string bytes;

	if( packet >> bytes >> dec_msg ) {

		dec_msg = m_compressor.decompress( dec_msg );
		bytes = m_compressor.decompress( bytes );

		std::cout << dec_msg << std::endl;

		int _instruction = JHandler::get_value( dec_msg.c_str(), "instruction" ).GetInt();

		switch( _instruction ) {
			case (int)Instruction::COLLECT_INSTR: {
				std::string video_id = JHandler::get_value( dec_msg.c_str(), "id" ).GetString();
				int _order = JHandler::get_value( dec_msg.c_str(), "order" ).GetInt();
				int _mat = JHandler::get_value( dec_msg.c_str(), "mat" ).GetInt();
				return Processed_Tmp( _instruction, _order, _mat, bytes, video_id );
			}
			case (int)Instruction::STORE_INSTR: {
				return Processed_Tmp( _instruction, 0, 0, "", "" );
			}
			case (int)Instruction::RETRV_INSTR: {
				std::string video_id = JHandler::get_value( dec_msg.c_str(), "id" ).GetString();
				int _mat = JHandler::get_value( dec_msg.c_str(), "mat" ).GetInt();
				return Processed_Tmp( _instruction, _mat, video_id );
			}
		}
	}
	return Processed_Tmp::mock();
}

Reader::~Reader() { }

} /* namespace network */
