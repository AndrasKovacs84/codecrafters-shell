#include "ExitCommand.hpp"

ExitCommand::ExitCommand(std::string_view cmd)
    : m_Command(cmd)
{}

void ExitCommand::ParseArgs(const std::vector<std::string>& args)
{}

auto ExitCommand::Execute() -> bool
{
    return false;
}
