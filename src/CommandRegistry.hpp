#pragma once

#include "ICommand.hpp"
#include <functional>
#include <memory>
#include <optional>

using CommandFactory =
    std::function<std::unique_ptr<ICommand>(std::string_view)>;

class CommandRegistry
{
public:
    static auto Get() -> std::unordered_map<std::string, CommandFactory>&;
    static auto GetCommand(std::string_view cmd)
        -> std::optional<std::unique_ptr<ICommand>>;
    static auto IsBuiltin(std::string cmd) -> bool;
};
