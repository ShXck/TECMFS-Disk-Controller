#ifndef RAID_H_DISKBLOCK_H_
#define RAID_H_DISKBLOCK_H_
#include <vector>
#include <string>

namespace raid {

struct Video_Container {
	std::string video_binary_data;
	std::string video_id;
	int chunk_order;
	int chunk_suborder;
	Video_Container( std::string binary, std::string id, int order, int suborder ) : video_binary_data( binary ),video_id( id ), chunk_order( order ), chunk_suborder( suborder ) { }
};

typedef unsigned int u_int;
typedef std::vector<Video_Container> Video_Collection;

class Disk_Block {
public:
	Disk_Block( u_int mem_size );
	void set_id( std::string id );
	void insert_video_data( std::string binary, std::string vid_id, int chunk_order, int suborder );
	virtual ~Disk_Block();
private:
	u_int m_capacity;
	std::string block_id;
	Video_Collection m_collection;
};

} /* namespace raid */

#endif /* RAID_H_DISKBLOCK_H_ */
