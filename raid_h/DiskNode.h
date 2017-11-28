#ifndef RAID_H_DISKNODE_H_
#define RAID_H_DISKNODE_H_
#include <vector>
#include "DiskBlock.h"
#include "TECMFSDisk.h"
#include "../network_h/ProcessedTmp.h"
#include <bitset>
#include <string>
#include <iostream>
#include "../network_h/Instructions.h"
#include <algorithm>
#include <SFML/Network.hpp>
#include "../network_h/JSONHandler.h"
#include "../network_h/Instructions.h"
#include <thread>

#define DISK_CAPACITY 1280

namespace raid {

typedef std::vector<Disk_Block> Disk_Blocks;
typedef unsigned int u_int;
typedef unsigned char byte;
typedef std::vector<network::Processed_Tmp> Tmp_Collector;
typedef std::vector<Video_Container*> Container_Ptr;

class Disk_Node {
public:
	Disk_Node();
	/**
	 * Ejecuta una acción basado en la información recuperada del controller.
	 * @param tmp el objeto con los datos obtenidos.
	 * @param socket el socket del disco.
	 */
	void execute( network::Processed_Tmp tmp, sf::TcpSocket* socket );
	/**
	 * Añade un bloque al disco.
	 * @param b_capacity la capacidad del bloque.
	 */
	void add_block( u_int b_capacity );
	/**
	 * Distribuye la información en los bloques del disco.
	 * @param bytes los bytes.
	 * @param vid_id la id del video.
	 * @param chunk_order el orden de la parte.
	 * @param mat el número de frame.
	 * @param disk_block el bloque donde se guarda la información.
	 */
	void distribute_data( std::string bytes, std::string vid_id, int chunk_order, int mat, int disk_block );
	virtual ~Disk_Node();
private:
	/**
	 * Convierte bytes en binario.
	 * @param source el byte que se quiere convertir.
	 * @return la representación binario.
	 */
	std::string byte_to_binary( byte source );
	/**
	 * Construye el binario de una lista de bytes.
	 * @param bytes los bytes.
	 * @return el binario construido.
	 */
	std::string binary( std::string bytes );
	/**
	 * Construye bytes a partir de binario.
	 * @param bit el binario.
	 * @return los bytes construidos.
	 */
	byte bit_to_byte( std::string bit );
	/**
	 * Envía un mensaje de acción.
	 * @param socket el socket del disco.
	 */
	void send_ready_msg( sf::TcpSocket* socket );
private:
	TECMFS_Disk mfs_disk;
	Disk_Blocks m_blocks;
	u_int m_capacity;
	Tmp_Collector m_collector;

};

} /* namespace raid */

#endif /* RAID_H_DISKNODE_H_ */
