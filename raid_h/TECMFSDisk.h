#ifndef RAID_H_TECMFSDISK_H_
#define RAID_H_TECMFSDISK_H_
#include "../network_h/XMLHandler.h"
#include "DiskNode.h"
#include "DiskBlock.h"

typedef unsigned int u_int;

namespace raid {

typedef std::vector<Disk_Node*> Disk_Nodes;

class TECMFS_Disk {
public:
	TECMFS_Disk();
	void set_disks( Disk_Nodes& nodes, u_int nodes_number, u_int block_number );
	bool check_nodes_size();
	bool check_blocks_size();
	void set_nodes_size( unsigned int n_size );
	void set_blocks_size( unsigned int b_size );
	const u_int& block_size() const;
	const u_int& node_size() const;
	virtual ~TECMFS_Disk();
private:
	u_int b_size;
	u_int n_size;
};

} /* namespace raid */

#endif /* RAID_H_TECMFSDISK_H_ */
