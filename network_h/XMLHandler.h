#include "rapidxml.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

typedef rapidxml::xml_document<> XDocument;
typedef rapidxml::xml_node<> XNode;

namespace XHandler {

	std::string get_attribute( std::string attr, std::string file_path );

}

