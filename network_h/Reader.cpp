
#include "Reader.h"

namespace network {

Reader::Reader() { }

void Reader::read( std::string msg ) {

	std::string dec_msg = m_compressor.decompress( msg );

	std::cout << "MSG: " << dec_msg << std::endl;
}

Reader::~Reader() { }

} /* namespace network */
