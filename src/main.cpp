#include "../lib/demonic/demonic.h"
#include <getopt.h>


std::vector<std::string> dict = demonic::vector_from_file("english.txt");
std::vector<std::string> temp;
int min_chars = 6;
int write_rate = 1000;

void extract(std::string &s) {
    for (const std::string &word : dict) {
        if (demonic::string_in_string(word, s) && word.length() >= min_chars) {
            std::cout << word << std::endl;
            temp.push_back(word);
            s.replace(s.find(word), word.length(), "");
            extract(s);
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc < 5 || argv[1] == "-h" || argv[1] == "--help") {
        HelpMaker h;
        h.add_usage("xtract -p FILE -o FILE");
        h.add_option("-h", "Prints help");
        h.add_option("-p", "Define password file");
        h.add_option("-o", "Define output file");
        h.add_option("-w", "Define write rate");
        h.make();
        return 0;
    }

    int option;
    std::string file_in;
    std::string file_out;

    while ((option = getopt(argc, argv, "p:o:m:w:")) != -1) {
        switch (option) {
            case 'p':
                file_in = optarg;
                break;
            case 'o':
                file_out = optarg;
                break;
            case 'm':
                min_chars = atoi(optarg);
                break;
            case 'w':
                write_rate = atoi(optarg);
                break;
        }
    }

    std::ofstream stream_out(file_out, std::ios::app);

    std::vector<std::string> passwords = demonic::vector_from_file(file_in);
    for (std::string password : passwords) {
        extract(password);
        if (temp.size() > write_rate) {
            for (const std::string &s : temp) {
                stream_out << s << std::endl;
            }
            temp.clear();
        }
    }

    for (const std::string &s : temp) {
        stream_out << s << std::endl;
    }

    stream_out.close();

    return 0;
}
