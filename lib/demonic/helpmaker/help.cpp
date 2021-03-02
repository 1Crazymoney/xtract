#include "help.h"

Option::Option(std::string arg, std::string info) : option(std::move(arg)), info(std::move(info)) {}

void HelpMaker::add_usage(std::string usage) {
    this->usage = std::move(usage);
}

void HelpMaker::add_usage_info(std::string usage_info) {
    this->usage_info = std::move(usage_info);
}

void HelpMaker::add_example(std::string example) {
    this->example = std::move(example);
}

void HelpMaker::add_option(std::string option, std::string info) {
    Option a(std::move(option), std::move(info));
    this->options.push_back(a);
}

void HelpMaker::make() {
    if (!usage.empty()) { std::cout << "Usage:" << std::endl << usage << std::endl; }
    if (!usage_info.empty()) { std::cout << usage_info << std::endl; }
    if (!example.empty()) { std::cout << "Example:" << std::endl << example << std::endl; }
    if (!options.empty()) {
        std::cout << "Options:" << std::endl;
        for (const auto &a : options)
            std::cout << demonic::string_space((std::string) a.option, 20) << a.info << std::endl;

    }
    std::cout << std::endl;
}
