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
#include <algorithm>
#include <SFML/Network.hpp>
#include "../network_h/JSONHandler.h"
#include "../network_h/Instructions.h"
#include <thread>

#define DISK_CAPACITY 1280

namespace raid {

typedef std::vector<Disk_Block> Disk_Blocks;
typedef unsigned int u_int;
typedef unsigned char byte;
typedef std::vector<network::Processed_Tmp> Tmp_Collector;
typedef std::vector<Video_Container*> Container_Ptr;

class Disk_Node {
public:
	Disk_Node();
	void execute( network::Processed_Tmp tmp, sf::TcpSocket* socket );
	void add_block( u_int b_capacity );
	void distribute_data( std::string bytes, std::string vid_id, int chunk_order, int mat, int disk_block );
	virtual ~Disk_Node();
private:
	std::string byte_to_binary( byte source );
	std::string binary( std::string bytes );
	byte bit_to_byte( std::string bit );
	void send_ready_msg( sf::TcpSocket* socket );
private:
	TECMFS_Disk mfs_disk;
	Disk_Blocks m_blocks;
	u_int m_capacity;
	Tmp_Collector m_collector;

};

} /* namespace raid */

#endif /* RAID_H_DISKNODE_H_ */
