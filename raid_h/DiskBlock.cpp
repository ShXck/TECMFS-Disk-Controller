#include "DiskBlock.h"

namespace raid {

Disk_Block::Disk_Block( u_int mem_size ) : m_capacity( mem_size ) { }

void Disk_Block::set_id( std::string id ) {
	block_id = id;
}

void Disk_Block::insert_video_data( std::string bytes, std::string binary, std::string vid_id, int chunk_order, int mat ) {
	//TODO: Verify the size of the data before inserting it.
	m_collection.push_back( Video_Container( bytes, binary, vid_id, chunk_order, mat ) );
}

Video_Collection Disk_Block::group_by_mat_number( std::string vid_id, int mat ) {

	Video_Collection container_ptr;

	for( auto& vid : m_collection ) {
		if( vid.mat_number == mat && vid.video_id == vid_id )  container_ptr.push_back( vid );
	}

	return container_ptr;
}


Disk_Block::~Disk_Block() { }

} /* namespace raid */
