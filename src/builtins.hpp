#pragma once

#include <functional>
#include <iostream>
#include <memory>
#include <vector>

class ICommand
{
public:
    virtual void ParseArgs(const std::vector<std::string>& args) = 0;
    virtual auto Execute() -> bool = 0;
    virtual ~ICommand() = default;
};

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

struct RegisterCommand
{
    RegisterCommand(const std::string& name, CommandFactory factory)
    {
        CommandRegistry::Get().emplace(name, std::move(factory));
    }
};

class ExitCommand : public ICommand
{
public:
    ExitCommand(std::string_view cmd);
    void ParseArgs(const std::vector<std::string>& args) override;
    auto Execute() -> bool override;

private:
    std::string m_Command;
    inline static RegisterCommand reg{
        "exit",
        [](std::string_view cmd)
        { return std::make_unique<ExitCommand>(cmd); }};
};

class EchoCommand : public ICommand
{
public:
    EchoCommand(std::string_view cmd);
    void ParseArgs(const std::vector<std::string>& args) override;
    auto Execute() -> bool override;

private:
    std::string m_Command;
};

auto Parse(std::string_view) -> bool;
auto DelegateCommand(std::string_view) -> bool;
