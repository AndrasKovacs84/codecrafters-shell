#pragma once

#include "ICommand.hpp"
#include <functional>
#include <memory>

using CommandFactory =
    std::function<std::unique_ptr<ICommand>(std::string_view)>;

struct CommandRegistry
{
    static auto Get() -> std::unordered_map<std::string, CommandFactory>&
    {
        static std::unordered_map<std::string, CommandFactory> registry;
        return registry;
    }
};
