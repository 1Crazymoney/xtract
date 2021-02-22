//
// Created by demonic on 10/20/20.
//

#ifndef DEMONIC_STRINGS_H
#define DEMONIC_STRINGS_H

#include <iostream>
#include <vector>


namespace demonic {
    enum Styles {
        regular, bold, underline, italic
    };
    enum Colors {
        black, red, green, yellow, blue, purple, grey
    };

    bool string_in_string(const std::string &str, const std::string &full_str);

    std::vector<std::string> string_funnel(const std::string &s);

    std::string string_space(const std::string &s, size_t spaces);

    std::string string_color(const std::string &s, Colors color = Colors::black, Styles style = Styles::regular);

    std::string string_highlight(std::string s, const std::string &highlight, Colors color, Styles style);

    std::string string_lower(const std::string &s);

    std::string string_upper(const std::string &s);

    std::string string_from_bash(std::string s);

    bool string_has_char(const std::string &s, char c);

    std::string string_capitalized(const std::string &s);

    bool string_in_vector(std::string s, std::vector<std::string> vec);

}
#endif //DEMONIC_STRINGS_H
