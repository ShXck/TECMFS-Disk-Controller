#ifndef RAID_H_DISKNODE_H_
#define RAID_H_DISKNODE_H_
#include <vector>
#include "DiskBlock.h"

namespace raid {

typedef std::vector<Disk_Block*> Disk_Blocks;
typedef unsigned int u_int;

class Disk_Node {
public:
	Disk_Node( u_int mem_size );
	void add_block( u_int b_capacity );
	virtual ~Disk_Node();
private:
	Disk_Blocks m_blocks;
	u_int m_capacity;
};

} /* namespace raid */

#endif /* RAID_H_DISKNODE_H_ */
