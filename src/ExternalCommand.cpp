#include "ExternalCommand.hpp"
#include <iostream>
#include <utility>

ExternalCommand::ExternalCommand(std::string_view cmd, std::filesystem::path binPath)
    : m_Command(cmd)
    , m_BinPath(std::move(binPath))
{}

void ExternalCommand::ParseArgs()
{}

auto ExternalCommand::Execute() -> bool
{
    std::cout << "External command" << m_BinPath.native() << std::filesystem::path::preferred_separator << m_Command
              << "\n";
    return true;
}
