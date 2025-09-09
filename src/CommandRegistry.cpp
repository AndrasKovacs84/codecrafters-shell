#include "CommandRegistry.hpp"
#include <string>
#include <unordered_map>

auto CommandRegistry::Get() -> std::unordered_map<std::string, CommandFactory>&
{
    static std::unordered_map<std::string, CommandFactory> registry;
    return registry;
}

auto CommandRegistry::GetCommand(std::string_view cmd)
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

auto CommandRegistry::IsBuiltin(std::string cmd) -> bool
{
    auto it = CommandRegistry::Get().find(cmd);
    return it != CommandRegistry::Get().end();
}
