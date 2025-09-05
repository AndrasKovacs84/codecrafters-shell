#include "builtins.hpp"
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
    auto it = CommandRegistry::Get().find(std::string(cmd));
    if (it != CommandRegistry::Get().end())
    {
        auto command = it->second(cmd);
        return command->Execute();
    }
    std::cout << cmd << ": command not found" << '\n';
    return true;
}

auto Echo(std::string_view cmd) -> bool
{
    cmd.remove_prefix(sizeof("echo"));
    std::cout << cmd << '\n';
    return true;
}

ExitCommand::ExitCommand(std::string_view cmd)
    : m_Command(cmd)
{}

void ExitCommand::ParseArgs(const std::vector<std::string>& args)
{}

auto ExitCommand::Execute() -> bool
{
    return false;
}
