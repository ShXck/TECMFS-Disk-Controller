#ifndef NETWORK_H_READER_H_
#define NETWORK_H_READER_H_
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "Compressor.h"

namespace network {

class Reader {
public:
	Reader();
	void read( std::string msg );
	virtual ~Reader();
private:
	Compressor m_compressor;
};

} /* namespace network */

#endif /* NETWORK_H_READER_H_ */
