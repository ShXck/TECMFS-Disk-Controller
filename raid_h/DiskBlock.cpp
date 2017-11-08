#include "DiskBlock.h"

namespace raid {

Disk_Block::Disk_Block( u_int mem_size ) : m_capacity( mem_size ) { }

void Disk_Block::set_id( std::string id ) {
	block_id = id;
}

void Disk_Block::insert_video_data( std::string binary, std::string vid_id, int chunk_order, int suborder ) {
	//TODO: Verify the size of the data before inserting it.
	m_collection.push_back( Video_Container( binary, vid_id, chunk_order, suborder ) );
}

Disk_Block::~Disk_Block() { }

} /* namespace raid */
