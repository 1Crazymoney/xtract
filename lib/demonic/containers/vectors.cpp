//
// Created by demonic on 10/20/20.
//

#include "vectors.h"

std::vector<std::string> demonic::vector_from_string(std::string s, char delimit = ' ') {
    int pos = 0, len = 0;
    std::vector<std::string> vec;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == delimit) {
            vec.push_back(s.substr(pos, len));
            len = 0;
            pos = i + 1;
        } else if (i == s.length() - 1) {
            int end = s.length() - pos;
            vec.push_back(s.substr(pos, end));
        } else {
            len++;
        }
    }
    return vec;
}

std::vector<std::string> demonic::vector_from_file(std::string s, bool binary) {
    if (binary)
        std::fstream file_stream(s, std::ios::binary);
    else
        std::fstream file_stream(s);

    std::fstream file_stream(s);
    std::vector<std::string> vec;
    std::string str;
    while (file_stream >> str) {
        std::string result;
        for (char c : str) {
            if (c != '\n')
                result.push_back(c);
        }
        vec.push_back(result);
    }
    return vec;
}

std::vector<std::string> demonic::vector_from_bash(std::string s) {
    std::vector<std::string> data;
    FILE *stream;
    const int maxBuffer = 256;
    char buffer[maxBuffer];
    s.append(" 2>&1");
    stream = popen(s.c_str(), "r");
    if (stream) {
        while (!feof(stream))
            if (fgets(buffer, maxBuffer, stream) != nullptr)
                data.emplace_back(buffer);
        pclose(stream);
    }
    return data;
}

std::vector<std::string> demonic::vector_from_header(const std::string &header, const std::string &file) {
    std::ifstream file_in(file);
    std::vector<std::string> result;
    std::string s;
    bool trigger = false;
    while (getline(file_in, s)) {
        if (s == header) {
            while (getline(file_in, s)) {
                if (s.empty()) {
                    trigger = true;
                    break;
                } else {
                    result.push_back(s);
                }
            }
        }
        if (trigger)
            break;
    }
    file_in.close();
    return result;
}
