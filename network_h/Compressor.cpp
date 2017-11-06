#include "Compressor.h"

namespace network {

Compressor::Compressor() { }

std::string Compressor::compress( const std::string& s, int compress_lvl ) {
	z_stream z_strm;
	memset( &z_strm, 0, sizeof( z_strm ) );

	if( deflateInit( &z_strm, compress_lvl ) != Z_OK ) {
		throw( std::runtime_error( "deflateInit failed while compressing." ) );
	}
	z_strm.next_in = (Bytef*) s.data();
	z_strm.avail_in = s.size();

	int _ret;
	char out_buffer[32768];
	std::string out_str;

	do {
		z_strm.next_out = reinterpret_cast<Bytef*>( out_buffer );
		z_strm.avail_out = sizeof( out_buffer );
		_ret = deflate( &z_strm, Z_FINISH );
		if( out_str.size() < z_strm.total_out ) {
			out_str.append( out_buffer, z_strm.total_out - out_str.size() );
		}
	} while( _ret == Z_OK );

	deflateEnd( &z_strm );

	if( _ret != Z_STREAM_END ) {
		std::ostringstream _oss;
		_oss << "Exception during zlib compression: (" << _ret << ") " << z_strm.msg;
		throw( std::runtime_error( _oss.str() ) );
	}

	return out_str;
}

std::string Compressor::decompress( const std::string& s ) {
	z_stream z_strm;
	memset( &z_strm, 0, sizeof( z_strm ) );

	if ( inflateInit( &z_strm ) != Z_OK )
		throw(std::runtime_error("inflateInit failed while decompressing."));

	z_strm.next_in = ( Bytef* ) s.data();
	z_strm.avail_in = s.size();

	int _ret;
	char out_buffer[32768];
	std::string out_str;

	do {
		z_strm.next_out = reinterpret_cast<Bytef*>( out_buffer );
		z_strm.avail_out = sizeof(out_buffer);

		_ret = inflate(&z_strm, 0);

		if ( out_str.size() < z_strm.total_out ) {
			out_str.append(out_buffer,
							 z_strm.total_out - out_str.size());
		}

	} while ( _ret == Z_OK );

	inflateEnd(&z_strm);

	if ( _ret != Z_STREAM_END ) {
		std::ostringstream oss;
		oss << "Exception during zlib decompression: (" << _ret << ") "
			<< z_strm.msg;
		throw(std::runtime_error( oss.str() ) );
	}

	return out_str;
}

Compressor::~Compressor() { }

} /* namespace network */
