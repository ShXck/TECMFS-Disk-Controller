#include "DiskBlock.h"

namespace raid {

Disk_Block::Disk_Block( u_int mem_size ) : m_capacity( mem_size ) { }

void Disk_Block::set_id( std::string id ) {
	block_id = id;
}

Disk_Block::~Disk_Block() { }

} /* namespace raid */
