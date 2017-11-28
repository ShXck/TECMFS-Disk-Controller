#include "rapidxml.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

typedef rapidxml::xml_document<> XDocument;
typedef rapidxml::xml_node<> XNode;

namespace XHandler {

	/**
	 * Lee un archivo XML y devuelve un atributo
	 * @param attr el atributo que se quiere.
	 * @param file_path el path del XML.
	 * @return el valor del atributo.
	 */
	std::string get_attribute( std::string attr, std::string file_path );

}

