#include <fstream>
#include <sstream>
#include <iostream>

int main(int argc, char **argv) {
    std::ifstream infile;
    std::ofstream outfile;
    std::stringstream buffer;
    std::string text;

    if (argc != 4) {
        std::cout << "error; number of arguments" << std::endl;
    exit (EXIT_FAILURE);
    }

    infile.open(argv[1]);
    if (infile.fail()) {
        std::cout << "error; file can't open" << std::endl;
    exit(EXIT_FAILURE);
    }

    buffer << infile.rdbuf();
    infile.close();
    text = buffer.str();
    int j = 0;
    int index = 0;
    if (argv[2][0] == '\0')
        j = 1;
    if (!j)
    {
        while ((index = text.find((std::string)argv[2], index)) != -1) {
            text.erase(index, ((std::string)argv[2]).length());
            text.insert(index, (std::string)argv[3]);
            index += ((std::string)argv[3]).length();
        }
    }
    outfile.open(argv[1] + (std::string) ".replace");
    outfile << text;
    outfile.close();
    return (EXIT_SUCCESS);
}