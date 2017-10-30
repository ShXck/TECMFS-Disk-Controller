#ifndef NETWORK_H_NETWORKHANDLER_H_
#define NETWORK_H_NETWORKHANDLER_H_
#include <string>
#include <iostream>
#include <SFML/Network.hpp>
#include "Reader.h"
#include "XMLHandler.h"

namespace network {

struct Data_Container {
	std::string last_msg;
	std::string container_folder;
};

class Network_Handler {
public:
	Network_Handler();
	void send( std::string msg );
	void wait_for_response();
	Data_Container& data_container();
	virtual ~Network_Handler();
private:
	void setup();
private:
	sf::TcpSocket m_socket;
	Reader m_reader;
	Data_Container m_container;
};

} /* namespace network */

#endif /* NETWORK_H_NETWORKHANDLER_H_ */
