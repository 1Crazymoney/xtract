#ifndef HELP_MAKER_HELPMAKER_H
#define HELP_MAKER_HELPMAKER_H

#include <iostream>
#include <utility>
#include <vector>
#include "../strings/strings.h"

struct Option {
    std::string option, info;

    Option(std::string arg, std::string info);
};

class HelpMaker {
public:
    void add_usage(std::string usage);

    void add_usage_info(std::string usage_info);

    void add_example(std::string example);

    void add_option(std::string option, std::string info);

    void make();

private:
    std::vector<Option> options;
    std::string usage, usage_info, example;
};

#endif //HELP_MAKER_HELPMAKER_H
