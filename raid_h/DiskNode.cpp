#include "DiskNode.h"

namespace raid {

Disk_Node::Disk_Node() : m_capacity( DISK_CAPACITY ) {
	mfs_disk.setup_disk( m_blocks );
}

void Disk_Node::execute( network::Processed_Tmp tmp ) {

	std::cout << "INSTR TMP: " << tmp._instruction << std::endl;

	switch( tmp._instruction ) {
		case (int)Instruction::COLLECT_INSTR: {
			m_collector.push_back( tmp );
			std::cout << "DATA COLLECTED" << std::endl;
			break;
		}
		case (int)Instruction::STORE_INSTR: {
			for( unsigned int i = 0; i < m_collector.size(); i++ ) {
				distribute_data( m_collector[i]._data, m_collector[i].video_id ,m_collector[i]._order );
				std::cout << "DATA STORED" << std::endl;
			}
			m_collector.clear();
			break;
		}
		case (int)Instruction::RETRV_INSTR: {
			//retrieve code
			break;
		}
	}
}

void Disk_Node::add_block( u_int b_capacity ) {
	m_blocks.push_back( Disk_Block( b_capacity ) );
}

void Disk_Node::distribute_data( std::string bytes, std::string vid_id, int chunk_order ) {

	std::string _binary = binary( bytes );
	int _lenght = _binary.length();
	int _parts =  mfs_disk.blocks();

	std::vector<std::string> _chunks;

	//Divide el string binario en pedazos.
    int _at, _pre = 0, i;
    for( _pre = i = 0; i < _parts; i++ ) {
        _at = ( _lenght + _lenght * i ) / _parts;
        _chunks.push_back( _binary.substr( _pre, _at - _pre ) );
        _pre = _at;
    }

    //Divide los pedazos en los bloques.
    for( unsigned int i = 0; i < _chunks.size(); i++ ) {
    	m_blocks[i].insert_video_data( _chunks[i], vid_id, chunk_order, i );
    }

    std::cout << "STORED!" << std::endl;
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

Disk_Node::~Disk_Node() { }

} /* namespace raid */
