#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_
#include "network_h/NetworkHandler.h"
#include "raid_h/RAIDSystem.h"

class File_System {
public:
	File_System();
	virtual ~File_System();
private:
	network::Network_Handler m_handler;
	raid::RAID_System m_raid;
};

#endif /* FILESYSTEM_H_ */
