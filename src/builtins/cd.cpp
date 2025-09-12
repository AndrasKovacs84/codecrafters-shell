#include "cd.hpp"

#include <filesystem>

CdCommand::CdCommand(std::string_view cmd)
    : m_Command(cmd)
{}

void CdCommand::ParseArgs()
{}

auto CdCommand::Execute() -> bool
{
    size_t pos = m_Command.find(' ');
    if (pos == std::string::npos)
    {
        return false;
    }
    std::string_view args{m_Command.begin() + pos + 1, m_Command.end()};

    std::filesystem::current_path(std::filesystem::path(args));

    return true;
}
