#include <iostream>
#include "raid_h/DiskNode.h"
#include "network_h/NetworkHandler.h"

int main() {
	network::Network_Handler net_handler;
	net_handler.run();
	return 0;
}


