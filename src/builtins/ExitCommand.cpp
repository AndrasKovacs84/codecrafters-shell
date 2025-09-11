#include "ExitCommand.hpp"

ExitCommand::ExitCommand(std::string_view cmd)
    : m_Command(cmd)
{}

void ExitCommand::ParseArgs()
{}

auto ExitCommand::Execute() -> bool
{
    return false;
}
