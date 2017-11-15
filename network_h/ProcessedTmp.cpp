#include "ProcessedTmp.h"

namespace network {

Processed_Tmp::Processed_Tmp( int instr, int order, int mat, std::string data, std::string vid_id ) : _instruction( instr ), _order( order ), mat_order( mat ), _data( data ), video_id( vid_id ) { }

Processed_Tmp::Processed_Tmp( int instr, int mat, std::string vid_id ) : _instruction( instr ), mat_order( mat ), video_id( vid_id ) {}

Processed_Tmp::Processed_Tmp() { }

Processed_Tmp& Processed_Tmp::operator =( const Processed_Tmp& prc_tmp ) {
	_instruction = prc_tmp._instruction;
	_order = prc_tmp._order;
	_data = prc_tmp._data;
	video_id = prc_tmp.video_id;
	return *this;
}


Processed_Tmp Processed_Tmp::mock() {
	return Processed_Tmp( 0, 0, 0, "NONE", "NONE" );
}

Processed_Tmp::~Processed_Tmp() { }

} /* namespace network */
