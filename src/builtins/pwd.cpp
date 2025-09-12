#include "pwd.hpp"

#include <filesystem>

PwdCommand::PwdCommand(std::string_view cmd)
    : m_Command(cmd)
{}

void PwdCommand::ParseArgs()
{}

auto PwdCommand::Execute() -> bool
{
    std::cout << std::filesystem::current_path().native() << "\n";
    return true;
}
