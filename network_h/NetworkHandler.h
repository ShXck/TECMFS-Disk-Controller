#ifndef NETWORK_H_NETWORKHANDLER_H_
#define NETWORK_H_NETWORKHANDLER_H_
#include <string>
#include <iostream>
#include <SFML/Network.hpp>
#include "Reader.h"
#include "XMLHandler.h"
#include "ProcessedTmp.h"
#include "../raid_h/DiskNode.h"

namespace network {

struct Data_Container {
	Processed_Tmp last_request_result;
	std::string container_folder;
};

class Network_Handler {
public:
	Network_Handler();
	void send( std::string msg );
	void run();
	Data_Container& data_container();
	virtual ~Network_Handler();
private:
	void setup();
private:
	raid::Disk_Node m_node;
	sf::TcpSocket m_socket;
	Reader m_reader;
	Data_Container m_container;
};

} /* namespace network */

#endif /* NETWORK_H_NETWORKHANDLER_H_ */
