#include "TECMFSDisk.h"

namespace raid {

TECMFS_Disk::TECMFS_Disk() {
	b_size = std::stoi( XHandler::get_attribute( "b_size", "config.xml" ) );
	n_size = std::stoi( XHandler::get_attribute( "n_size", "config.xml" ) );
	block_number = std::stoi( XHandler::get_attribute( "block_number", "config.xml" ) );
}

void TECMFS_Disk::setup_disk( Disk_Blocks& blocks ) {
	set_blocks( blocks );
	set_blocks_id( blocks );
}

void TECMFS_Disk::set_blocks( Disk_Blocks& blocks) {

	for( u_int i = 0; i < block_number; i++ ) {
		blocks.push_back(  Disk_Block( b_size ) );
	}
}

void TECMFS_Disk::set_blocks_id( Disk_Blocks& blocks ) {
	std::string _id[block_number] = {"A","B","C","F","G"};
	int id_ctr = 1;

	for( int i = 0; i < block_number; i++ ) {
		blocks[i].set_id( _id[0] + std::to_string( id_ctr++ ) );
	}
}

const u_int& TECMFS_Disk::block_size() const {
	return b_size;
}

const u_int& TECMFS_Disk::node_size() const {
	return n_size;
}

TECMFS_Disk::~TECMFS_Disk() { }

} /* namespace raid */
