#include "shell.hpp"

#include "CommandRegistry.hpp"
#include <iostream>
#include <string>

auto Shell::run() -> int
{
    while (m_shouldContinue)
    {
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);
        auto cmd = CommandRegistry::GetCommand(input);
        if (cmd)
        {
            m_shouldContinue = cmd.value()->Execute();
        }
    }
    return 0;
}
