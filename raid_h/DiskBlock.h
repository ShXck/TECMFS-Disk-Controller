#ifndef RAID_H_DISKBLOCK_H_
#define RAID_H_DISKBLOCK_H_
#include <vector>
#include <string>

namespace raid {

typedef unsigned int u_int;

class Disk_Block {
public:
	Disk_Block( u_int mem_size );
	void set_id( std::string id );
	virtual ~Disk_Block();
private:
	u_int m_capacity;
	std::string block_id;
};

} /* namespace raid */

#endif /* RAID_H_DISKBLOCK_H_ */
