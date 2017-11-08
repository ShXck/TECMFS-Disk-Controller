#ifndef RAID_H_DISKNODE_H_
#define RAID_H_DISKNODE_H_
#include <vector>
#include "DiskBlock.h"
#include "TECMFSDisk.h"
#include "../network_h/ProcessedTmp.h"

#define DISK_CAPACITY 1280
#define STORE_INSTR 1
#define RETRV_INSTR 2
#define NON_INSTR 3


namespace raid {

typedef std::vector<Disk_Block> Disk_Blocks;
typedef unsigned int u_int;

class Disk_Node {
public:
	Disk_Node();
	void execute( network::Processed_Tmp& tmp );
	void add_block( u_int b_capacity );
	void distribute_data( std::string binary, std::string vid_id, int chunk_order );
	virtual ~Disk_Node();
private:
	TECMFS_Disk mfs_disk;
	Disk_Blocks m_blocks;
	u_int m_capacity;
};

} /* namespace raid */

#endif /* RAID_H_DISKNODE_H_ */
