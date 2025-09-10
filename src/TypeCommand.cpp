#include "TypeCommand.hpp"
#include "shell.hpp"

#include <filesystem>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

TypeCommand::TypeCommand(std::string_view cmd)
    : m_Command(cmd)
{}

void TypeCommand::ParseArgs()
{}

auto TypeCommand::Execute() -> bool
{
    std::vector<std::string> tokens;
    for (auto&& word : m_Command | std::views::split(' '))
    {
        tokens.emplace_back(std::string_view(&*word.begin(), std::ranges::distance(word)));
    }

    if (tokens.size() > 2)
    {
        std::cout << "too many arguments\n";
        return true;
    }
    if (tokens.size() == 1)
    {
        std::cout << "no provided argument\n";
        return true;
    }

    if (CommandRegistry::IsBuiltin(tokens[1]))
    {
        std::cout << tokens[1] << " is a shell builtin\n";
        return true;
    }

    auto path = Shell::GetEnv("PATH");
    if (path)
    {
        for (auto&& entry : path.value() | std::views::split(Shell::sep))
        {
            std::string_view path_to_check(&*entry.begin(), std::ranges::distance(entry));
            std::optional<std::filesystem::path> bin_path = Shell::SearchOnPath(tokens[1], path_to_check);
            if (bin_path.has_value())
            {
                std::cout << tokens[1] << " is " << bin_path.value().native() << "\n";
                return true;
            }
        }
    }

    std::cout << tokens[1] << ": not found\n";
    return true;
}
