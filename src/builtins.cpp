#include "builtins.hpp"
#include <sstream>
#include <vector>

namespace command
{

bool Parse(std::string_view cmd)
{
    return DelegateCommand(cmd);
}

bool DelegateCommand(std::string_view cmd)
{
    if (cmd.empty())
    {
        return true;
    }
    else if (cmd.starts_with("exit"))
    {
        return false;
    }
    else if (cmd.starts_with("echo"))
    {
        return Echo(cmd);
    }
    else
    {
        std::cout << cmd << ": command not found" << std::endl;
        return true;
    }
}

bool Echo(std::string_view cmd)
{
    cmd.remove_prefix(sizeof("echo"));
    std::cout << cmd << std::endl;
    return true;
}

} // command
