#include "TypeCommand.hpp"

#include <iostream>
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
        tokens.emplace_back(
            std::string_view(&*word.begin(), std::ranges::distance(word)));
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

    auto it = CommandRegistry::Get().find(tokens[1]);
    if (it != CommandRegistry::Get().end())
    {
        std::cout << it->first << " is a shell builtin\n";
        return true;
    }

    auto path = GetEnv("PATH");
    if (path)
    {
        for (auto&& entry : path.value() | std::views::split(sep))
        {
        }
    }

    std::cout << tokens[1] << ": not found\n";
    return true;
}

auto TypeCommand::GetEnv(std::string_view var) -> std::optional<std::string>
{
    if (const char* val = std::getenv(var.data()))
    {
        return std::string(val);
    }
    return std::nullopt;
}
