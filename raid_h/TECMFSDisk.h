#ifndef RAID_H_TECMFSDISK_H_
#define RAID_H_TECMFSDISK_H_
#include "../network_h/XMLHandler.h"
#include "DiskBlock.h"
#include <vector>

typedef unsigned int u_int;

namespace raid {

typedef std::vector<Disk_Block> Disk_Blocks;

class TECMFS_Disk {
public:
	TECMFS_Disk();
	void setup_disk( Disk_Blocks& blocks );
	void set_blocks( Disk_Blocks& blocks );
	void set_blocks_id( Disk_Blocks& blocks );
	void set_node_size( unsigned int n_size );
	void set_blocks_size( unsigned int b_size );
	const u_int& block_size() const;
	const u_int& node_size() const;
	const u_int& blocks() const;
	virtual ~TECMFS_Disk();
private:
	u_int b_size;
	u_int n_size;
	u_int block_number;
};

} /* namespace raid */

#endif /* RAID_H_TECMFSDISK_H_ */
