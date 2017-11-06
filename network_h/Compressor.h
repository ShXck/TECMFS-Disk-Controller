#ifndef NETWORK_H_COMPRESSOR_H_
#define NETWORK_H_COMPRESSOR_H_
#include <string>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <zlib.h>

namespace network {

class Compressor {
public:
	Compressor();
	std::string compress( const std::string& s, int compress_lvl );
	std::string decompress( const std::string& s );
	virtual ~Compressor();
};

} /* namespace network */

#endif /* NETWORK_H_COMPRESSOR_H_ */
