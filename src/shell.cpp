#include "shell.hpp"

#include "builtins.hpp"
#include <iostream>
#include <string>

int Shell::run()
{
    while (m_shouldContinue)
    {
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);
        if (!Parse(input))
        {
            m_shouldContinue = false;
        }
    }
    return 0;
}
