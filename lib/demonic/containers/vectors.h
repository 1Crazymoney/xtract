//
// Created by demonic on 10/20/20.
//

#ifndef DEMONIC_VECTORS_H
#define DEMONIC_VECTORS_H

#include <iostream>
#include <vector>
#include <fstream>

namespace demonic {

    std::vector<std::string> vector_from_bash(std::string s);

    std::vector<std::string> vector_from_string(std::string s, char delimit);

    std::vector<std::string> vector_from_file(std::string s, bool binary = false);

    std::vector<std::string> vector_from_header(const std::string &header, const std::string &file);
}
#endif //DEMONIC_VECTORS_H
