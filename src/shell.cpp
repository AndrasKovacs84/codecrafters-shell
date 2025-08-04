#include "shell.hpp"

#include <string>
#include <iostream>
#include "builtins.hpp"

int Shell::run()
{
    while(!m_shouldContinue)
    {
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);
        if(!command::Parse(input))
        {
            m_shouldContinue = false;
        }

    }
    return 0;
}
