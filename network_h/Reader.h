#ifndef NETWORK_H_READER_H_
#define NETWORK_H_READER_H_
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "Compressor.h"
#include "JSONHandler.h"
#include "ProcessedTmp.h"
#include "Instructions.h"

namespace network {

class Reader {
public:
	Reader();
	Processed_Tmp read( sf::Packet packet );
	virtual ~Reader();
private:
	Compressor m_compressor;
};

} /* namespace network */

#endif /* NETWORK_H_READER_H_ */
