#include "shell.hpp"

#include "CommandRegistry.hpp"
#include <filesystem>
#include <iostream>
#include <ranges>
#include <string>

auto Shell::run() -> int
{
    while (m_shouldContinue)
    {
        std::cout << "$ ";
        std::string input;
        std::getline(std::cin, input);
        auto cmd = CommandRegistry::GetCommand(input);
        if (cmd.has_value())
        {
            m_shouldContinue = cmd.value()->Execute();
        }
        else
        {
            std::cout << input << ": command not found\n";
        }
    }
    return 0;
}

auto Shell::GetEnv(std::string_view var) -> std::optional<std::string>
{
    if (const char* val = std::getenv(var.data()))
    {
        return std::optional<std::string>{val};
    }
    return std::nullopt;
}

auto Shell::SearchOnPath(std::string_view entry, std::string_view path) -> std::optional<std::filesystem::path>
{
    std::filesystem::path dir = path;
    auto candidate = dir / entry;
#ifdef _WIN32
    if (std::filesystem::exists(candidate))
    {
        return std::optional<std::filesystem::path>{dir};
    }
    if (std::filesystem::exists(candidate.string() + ".exe"))
    {
        return std::optional<std::filesystem::path>{dir};
    }
#else
    if (std::filesystem::exists(candidate) &&
        (std::filesystem::status(candidate).permissions() & std::filesystem::perms::owner_exec) !=
        std::filesystem::perms::none)
    {
        return std::optional<std::filesystem::path>{dir};
    }
#endif
    return std::nullopt;
}

auto Shell::GetExecutablePath(std::string_view bin) -> std::optional<std::filesystem::path>
{
    std::optional<std::string> path_var = GetEnv("PATH");
    if (path_var)
    {
        for (auto&& entry : path_var.value() | std::views::split(Shell::sep))
        {
            std::string_view path_to_check(&*entry.begin(), std::ranges::distance(entry));
            std::optional<std::filesystem::path> bin_path = Shell::SearchOnPath(bin, path_to_check);
            if (bin_path.has_value())
            {
                return bin_path;
            }
        }
    }
    return std::nullopt;
}
