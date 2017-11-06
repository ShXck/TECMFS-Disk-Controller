#ifndef RAID_H_DISKNODE_H_
#define RAID_H_DISKNODE_H_
#include <vector>
#include "DiskBlock.h"
#include "../network_h/NetworkHandler.h"
#include "TECMFSDisk.h"

#define DISK_CAPACITY 1280

namespace raid {

typedef std::vector<Disk_Block> Disk_Blocks;
typedef unsigned int u_int;

class Disk_Node {
public:
	Disk_Node();
	void start();
	void add_block( u_int b_capacity );
	virtual ~Disk_Node();
private:
	TECMFS_Disk mfs_disk;
	Disk_Blocks m_blocks;
	u_int m_capacity;
	network::Network_Handler m_handler;
};

} /* namespace raid */

#endif /* RAID_H_DISKNODE_H_ */
