#include "cd.hpp"
#include "../shell/shell.hpp"

#include <algorithm>
#include <filesystem>
#include <forward_list>

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
        return true;
    }
    std::string args{m_Command.substr(pos + 1)};

    while ((pos = args.find('~')) != std::string::npos)
    {
        std::optional<std::string> home = Shell::GetEnv("HOME");
        if (home.has_value())
        {
            std::forward_list<char> home_container;
            std::ranges::reverse_copy(home.value(), std::front_inserter(home_container));
            args.replace_with_range(args.begin() + pos, args.begin() + pos + 1, home_container);
        }
    }

    std::error_code ec;
    std::filesystem::current_path(std::filesystem::path(args), ec);
    if (ec)
    {
        std::cout << "cd: " << args << ": No such file or directory\n";
        return true;
    }
    return true;
}
