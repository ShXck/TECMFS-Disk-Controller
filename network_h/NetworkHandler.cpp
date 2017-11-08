#include "NetworkHandler.h"

namespace network {

Network_Handler::Network_Handler() {
	setup();
}

void Network_Handler::setup() {

	std::string _ip = XHandler::get_attribute( "ip", "config.xml" );
	sf::IpAddress _address( _ip );
	unsigned int _port = std::stoi( XHandler::get_attribute( "port", "config.xml" ) );
	std::string folder_path = XHandler::get_attribute( "path", "config.xml" );
	m_container.container_folder = folder_path;

	m_socket.setBlocking( false );
	m_socket.connect( _address, _port );
}

void Network_Handler::run() {

	std::cout << "Running!" << std::endl;

	sf::Packet _packet;
	std::string _message;

	while ( true ) {
		if ( m_socket.receive( _packet ) == sf::Socket::Done ) {
			if( _packet >> _message ) {
				Processed_Tmp tmp_obj = m_reader.read( _message );
				m_node.execute( tmp_obj );
				m_container.last_request_result = tmp_obj;
			}
		}
	}
}

void Network_Handler::send( std::string msg ) {
	sf::Packet _packet;
	_packet << msg;
	m_socket.send( _packet );
}

Data_Container& Network_Handler::data_container() {
	return m_container;
}

Network_Handler::~Network_Handler() { }

} /* namespace network */
