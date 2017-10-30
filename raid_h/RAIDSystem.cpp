#include "RAIDSystem.h"

namespace raid {

RAID_System::RAID_System() {
	setup();
}

void RAID_System::setup() {
	mfs_disk.set_disks( m_nodes, NODES_NUMBER, BLOCKS_NUMBER );
}

RAID_System::~RAID_System() { }

} /* namespace raid */
