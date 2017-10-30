#include "DiskNode.h"

namespace raid {

Disk_Node::Disk_Node( u_int mem_size ) : m_capacity( mem_size ) { }

void Disk_Node::add_block( u_int b_capacity ) {
	m_blocks.push_back( new Disk_Block( b_capacity ) );
}

Disk_Node::~Disk_Node() { }

} /* namespace raid */
