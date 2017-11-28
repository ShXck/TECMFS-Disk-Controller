#ifndef NETWORK_H_JSONHANDLER_H_
#define NETWORK_H_JSONHANDLER_H_

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
#include <vector>

typedef rapidjson::Document JDocument;
typedef rapidjson::Document::AllocatorType& Alloc;
typedef rapidjson::Writer<rapidjson::StringBuffer> Writer;
typedef const char* c_char;
typedef std::string str;

namespace JHandler {
	/**
	 * Construye el mensaje de retorno al guardar información de un video.
	 * @param blocks_used los bloques usados.
	 * @param instruction la instrucción.
	 * @return el mensaje JSON construido.
	 */
	str build_store_ret_msg( std::vector<str> blocks_used, int instruction );
	/**
	 * Construye el mensaje de recuperación de datos.
	 * @param video_id la id del video.
	 * @param order el orden de la parte.
	 * @param mat el número de frame.
	 * @param instruction la instrucción.
	 * @return el mensaje JSON construido.
	 */
	str build_retrv_msg( std::string video_id, int order, int mat, int instruction );
	/**
	 * Construye un mensaje con una instrucción.
	 * @param instr la instrucción.
	 * @return el mensaje JSON construido.
	 */
	str build_instruction_msg( int instr );
	/**
	 * Construye un JSON vacío.
	 * @return el mensaje JSON construido.
	 */
	str build_empty();
	/**
	 * Obtiene el valor de una key.
	 * @param json el JSON.
	 * @param json_key la key.
	 * @return el valor correspondiente a la key.
	 */
	rapidjson::Value& get_value( c_char json, c_char json_key );

} /* namespace JHandler */

#endif /* NETWORK_H_JSONHANDLER_H_ */
