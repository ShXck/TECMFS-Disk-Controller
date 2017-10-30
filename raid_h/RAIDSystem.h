#ifndef RAID_H_RAIDSYSTEM_H_
#define RAID_H_RAIDSYSTEM_H_
#include "TECMFSDisk.h"
#include "DiskBlock.h"
#include "DiskNode.h"
#include <vector>

#define NODES_NUMBER 4
#define BLOCKS_NUMBER 10

namespace raid {

typedef std::vector<Disk_Node*> Disk_Nodes;

class RAID_System {
public:
	RAID_System();
	virtual ~RAID_System();
private:
	void setup();
private:
	TECMFS_Disk mfs_disk;
	Disk_Nodes m_nodes;
};

} /* namespace raid */

#endif /* RAID_H_RAIDSYSTEM_H_ */
