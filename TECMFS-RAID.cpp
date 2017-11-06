#include <iostream>
#include "raid_h/DiskNode.h"

int main() {

	raid::Disk_Node disk_node( 1024 );
	disk_node.start();

	return 0;
}


