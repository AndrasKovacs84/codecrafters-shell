#include "EchoCommand.hpp"

EchoCommand::EchoCommand(std::string_view cmd)
    : m_Command(cmd)
{}

void EchoCommand::ParseArgs()
{}

auto EchoCommand::Execute() -> bool
{
    std::cout << m_Command.substr(sizeof("echo")) << "\n";
    return true;
}
