#include "shell.hpp"
#include <iostream>

auto main() -> int
{
    // Flush after every std::cout / std:cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    Shell shell;
    return shell.run();
}
