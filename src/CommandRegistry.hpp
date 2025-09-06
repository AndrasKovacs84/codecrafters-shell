#pragma once

#include "ICommand.hpp"
#include <functional>
#include <memory>
#include <optional>

using CommandFactory =
    std::function<std::unique_ptr<ICommand>(std::string_view)>;

struct CommandRegistry
{
    static auto Get() -> std::unordered_map<std::string, CommandFactory>&
    {
        static std::unordered_map<std::string, CommandFactory> registry;
        return registry;
    }

    static auto GetCommand(std::string_view cmd)
        -> std::optional<std::unique_ptr<ICommand>>
    {
        size_t pos = cmd.find(' ');
        auto it = CommandRegistry::Get().find(std::string(cmd.substr(0, pos)));
        if (it != CommandRegistry::Get().end())
        {
            return it->second(cmd);
        }
        return std::nullopt;
    }
};
