#include "DiskNode.h"

namespace raid {

Disk_Node::Disk_Node() : m_capacity( DISK_CAPACITY ) {
	mfs_disk.setup_disk( m_blocks );
}

void Disk_Node::execute( network::Processed_Tmp& tmp ) {

	switch( tmp._instruction ) {
		case STORE_INSTR: {
			distribute_data( tmp._data, tmp.video_id ,tmp._order );
			break;
		}
		case RETRV_INSTR: {
			//retrieve code
			break;
		}
	}
}

void Disk_Node::add_block( u_int b_capacity ) {
	m_blocks.push_back( Disk_Block( b_capacity ) );
}

void Disk_Node::distribute_data( std::string binary, std::string vid_id, int chunk_order ) {

	int _lenght = binary.length();
	int _parts =  mfs_disk.blocks();

	std::vector<std::string> _chunks;

	//Divide el string binario en pedazos.
    int _at, _pre = 0, i;
    for( _pre = i = 0; i < _parts; i++ ) {
        _at = ( _lenght + _lenght * i ) / _parts;
        _chunks.push_back( binary.substr( _pre, _at - _pre ) );
        _pre = _at;
    }

    //Divide los pedazos en los bloques.
    for( unsigned int i = 0; i < _chunks.size(); i++ ) {
    	m_blocks[i].insert_video_data( _chunks[i], vid_id, chunk_order, i );
    }

    std::cout << "STORED!" << std::endl;
}

Disk_Node::~Disk_Node() { }

} /* namespace raid */
