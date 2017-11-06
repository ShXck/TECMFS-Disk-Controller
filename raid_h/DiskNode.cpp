#include "DiskNode.h"

namespace raid {

Disk_Node::Disk_Node() : m_capacity( DISK_CAPACITY ) {
	mfs_disk.setup_disk( m_blocks );
}

void Disk_Node::start() {
	m_handler.run();
}

void Disk_Node::add_block( u_int b_capacity ) {
	m_blocks.push_back( Disk_Block( b_capacity ) );
}

Disk_Node::~Disk_Node() { }

} /* namespace raid */
