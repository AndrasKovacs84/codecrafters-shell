#include "builtins.hpp"
#include "CommandRegistry.hpp"
#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>

auto Parse(std::string_view cmd) -> bool
{
    return DelegateCommand(cmd);
}

auto DelegateCommand(std::string_view cmd) -> bool
{
    size_t pos = cmd.find(' ');
    auto it = CommandRegistry::Get().find(std::string(cmd.substr(0, pos)));
    if (it != CommandRegistry::Get().end())
    {
        auto command = it->second(cmd);
        return command->Execute();
    }
    std::cout << cmd << ": command not found" << '\n';
    return true;
}
