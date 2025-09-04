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
    using CommandFactory =
        std::function<std::unique_ptr<ICommand>(std::string_view)>;

    std::unordered_map<std::string_view, CommandFactory> commandRegistry = {
        {"exit",
         [](std::string_view cmd)
         { return std::make_unique<ExitCommand>(cmd); }}
    };

    if (cmd.empty())
    {
        return true;
    }
    if (cmd.starts_with("exit"))
    {
        return false;
    }
    if (cmd.starts_with("echo"))
    {
        // return Echo(cmd);
        return false;
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

auto ExitCommand::operator()() -> bool
{
    return false;
}
