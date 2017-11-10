#ifndef RAID_H_DISKNODE_H_
#define RAID_H_DISKNODE_H_
#include <vector>
#include "DiskBlock.h"
#include "TECMFSDisk.h"
#include "../network_h/ProcessedTmp.h"
#include <bitset>
#include <string>
#include <iostream>
#include "../network_h/Instructions.h"

#define DISK_CAPACITY 1280

namespace raid {

typedef std::vector<Disk_Block> Disk_Blocks;
typedef unsigned int u_int;
typedef unsigned char byte;
typedef std::vector<network::Processed_Tmp> Tmp_Collector;

class Disk_Node {
public:
	Disk_Node();
	void execute( network::Processed_Tmp tmp );
	void add_block( u_int b_capacity );
	void distribute_data( std::string bytes, std::string vid_id, int chunk_order );
	virtual ~Disk_Node();
private:
	std::string byte_to_binary( byte source );
	std::string binary( std::string bytes );
private:
	TECMFS_Disk mfs_disk;
	Disk_Blocks m_blocks;
	u_int m_capacity;
	Tmp_Collector m_collector;

};

} /* namespace raid */

#endif /* RAID_H_DISKNODE_H_ */
