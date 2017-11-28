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
	/**
	 * Comprime un string.
	 * @param s el string.
	 * @param compress_lvl el nivel de compresión.
	 * @return el string comprimido.
	 */
	std::string compress( const std::string& s, int compress_lvl );
	/**
	 * Descomprime un string.
	 * @param s el string.
	 * @return el string descomprimido.
	 */
	std::string decompress( const std::string& s );
	virtual ~Compressor();
};

} /* namespace network */

#endif /* NETWORK_H_COMPRESSOR_H_ */
