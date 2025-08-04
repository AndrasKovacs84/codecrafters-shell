#include <iostream>
#include "shell.hpp"

int main() {
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // std::string input = "";
    // while(input != "exit 0")
    // {
    //     std::cout << "$ ";
    //     std::getline(std::cin, input);
    //     if(input != "exit 0")
    //     {
    //         std::cout << input << ": command not found" << std::endl;
    //     }
    // }
    Shell shell;
    return shell.run();
}
