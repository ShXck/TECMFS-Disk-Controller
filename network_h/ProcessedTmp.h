#ifndef NETWORK_H_PROCESSEDTMP_H_
#define NETWORK_H_PROCESSEDTMP_H_
#include <string>

namespace network {

class Processed_Tmp {
public:
	Processed_Tmp( int instr, int order, int mat, std::string data, std::string vid_id );
	Processed_Tmp( int instr, int mat, std::string vid_id );
	Processed_Tmp();
	Processed_Tmp& operator=( const Processed_Tmp& prc_tmp );
	void set_mat_order( int order );
	static Processed_Tmp mock();
	virtual ~Processed_Tmp();
public:
	int _instruction;
	int _order;
	int mat_order;
	std::string _data;
	std::string video_id;
};

} /* namespace network */

#endif /* NETWORK_H_PROCESSEDTMP_H_ */
