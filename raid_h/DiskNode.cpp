#include "DiskNode.h"

namespace raid {

Disk_Node::Disk_Node() : m_capacity( DISK_CAPACITY ) {
	mfs_disk.setup_disk( m_blocks );
}

void Disk_Node::execute( network::Processed_Tmp tmp, sf::TcpSocket* socket ) {

	switch( tmp._instruction ) {
		case (int)Instruction::COLLECT_INSTR: {
			m_collector.push_back( tmp );
			break;
		}
		case (int)Instruction::STORE_INSTR: {
			int disk = 0;
			for( unsigned int i = 0; i < m_collector.size(); i++ ) {
				distribute_data( m_collector[i]._data, m_collector[i].video_id ,m_collector[i]._order, m_collector[i].mat_order, disk++ );
				if( disk == m_blocks.size() ) disk = 0;
			}
			m_collector.clear();
			break;
		}
		case (int)Instruction::RETRV_INSTR: {

			Video_Collection chunk_container;

			for( unsigned int i = 0; i < m_blocks.size(); i++ ) {
				Video_Collection tmp_cont = m_blocks[i].group_by_mat_number( tmp.video_id, tmp.mat_order );
				chunk_container.insert( chunk_container.end(), tmp_cont.begin(), tmp_cont.end() );
			}

			std::sort( chunk_container.begin(), chunk_container.end() );

			for( auto& vc : chunk_container ) {
				std::string og_bytes;
				std::vector<std::string> sub_bins;
				std::string curr_bin = vc.video_binary_data;
				for( int i = 0; i < curr_bin.length() / 8; i++ ) {
					sub_bins.push_back( curr_bin.substr( 0, 8 ) );
					curr_bin.erase( 0, 8 );
				}
				for( unsigned int j = 0; j < sub_bins.size(); j++ ) {
					og_bytes += bit_to_byte( sub_bins[j] );
				}

				std::string ret_msg = JHandler::build_retrv_msg( tmp.video_id, vc.chunk_order, vc.mat_number , (int)Instruction::RETRV_INSTR );
				sf::Packet _packet;
				_packet << og_bytes << ret_msg;
				socket->send( _packet );
			}
			send_ready_msg( socket );
		}
	}
}

void Disk_Node::send_ready_msg( sf::TcpSocket* socket ) {
	std::string msg = JHandler::build_instruction_msg( (int)Instruction::JOIN_INSTR );
	sf::Packet _packet;
	_packet << JHandler::build_empty() << msg;
	socket->send( _packet );
}

void Disk_Node::add_block( u_int b_capacity ) {
	m_blocks.push_back( Disk_Block( b_capacity ) );
}

void Disk_Node::distribute_data( std::string bytes, std::string vid_id, int chunk_order, int mat, int disk_block ) {

	std::string _binary = binary( bytes );

	m_blocks[disk_block].insert_video_data( _binary, vid_id, chunk_order, mat );
}

std::string Disk_Node::byte_to_binary( byte source ) {
	std::bitset<8> bits_aux( source );
	std::string bits = bits_aux.to_string();
	return bits;
}

std::string Disk_Node::binary( std::string bytes ) {

	std::string _binary = "";

	const char* c_bytes = bytes.c_str();

	for( int i = 0; i < bytes.length(); i++ ) {
		std::string _bin = byte_to_binary( c_bytes[i] );
		_binary += _bin;
	}

	return _binary;
}

byte Disk_Node::bit_to_byte( std::string bit ) {
	std::bitset<8> _byte( bit );
	byte _result = ( _byte.to_ulong() & 0xFF );
	return _result;
}


Disk_Node::~Disk_Node() { }

} /* namespace raid */
