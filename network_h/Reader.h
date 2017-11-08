#ifndef NETWORK_H_READER_H_
#define NETWORK_H_READER_H_
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include "Compressor.h"
#include "JSONHandler.h"
#include "ProcessedTmp.h"

#define STORE_INSTR 1
#define RETRV_INSTR 2
#define NON_INSTR 3

namespace network {

class Reader {
public:
	Reader();
	Processed_Tmp read( std::string msg );
	virtual ~Reader();
private:
	Compressor m_compressor;
};

} /* namespace network */

#endif /* NETWORK_H_READER_H_ */
