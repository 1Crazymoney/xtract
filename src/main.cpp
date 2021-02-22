#include "../lib/demonic/demonic.h"
#include <getopt.h>

using namespace std;
using namespace demonic;

void help() {
    HelpMaker h;
    h.add_usage("xtract -f FILE -w FILE");
    h.add_option("f", "The file to extract from");
    h.add_option("w", "The file to write to");
    h.make();
}

int main(int argc, char *argv[]) {

    if (argc < 2 || argv[1] == "-h" || argv[1] == "--help") {
        help();
        return 0;
    }

    int option;
    bool flag;
    string file_in;
    string file_out;
    while ((option = getopt(argc, argv, "f:w:")) != -1) {
        switch (option) {
            case 'f':
                file_in = optarg;
                break;
            case 'w':
                file_out = optarg;
                break;
            default:
                help();
                break;
        }
    }

    vector<string> english = vector_from_file("english.txt");
    vector<string> temp;
    ifstream stream_in(file_in);
    ofstream stream_out(file_out, ios::app);
    string s;

    while (stream_in >> s) {
        for (const string &word : english) {
            if (string_in_string(word, string_lower(s)) && word.length() > 3) {
                cout << word << endl;
                temp.push_back(word);
                if (temp.size() >= 10000) {
                    for (const string &t : temp) {
                        stream_out << t << endl;
                    }
                    temp.clear();
                }
                continue;
            }
        }
    }

    for (const string &t : temp) {
        stream_out << t << endl;
    }

    stream_in.close();
    stream_out.close();

    return 0;
}
