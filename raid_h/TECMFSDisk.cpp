#include "TECMFSDisk.h"

namespace raid {

TECMFS_Disk::TECMFS_Disk() {
	b_size = std::stoi( XHandler::get_attribute( "b_size", "config.xml" ) );
	n_size = std::stoi( XHandler::get_attribute( "n_size", "config.xml" ) );
}

void TECMFS_Disk::set_disks( Disk_Nodes& nodes, u_int nodes_number, u_int block_number ) {

	for( u_int i = 0; i < nodes_number; i++ ) {
		nodes.push_back( new Disk_Node( n_size ) );
	}

	for( auto _node : nodes ) {
		for( u_int i = 0; i <  block_number; i++ ) {
			_node->add_block( b_size );
		}
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
