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

    static auto Create(std::string_view cmd) -> std::unique_ptr<ICommand>
    {
        return std::make_unique<ExitCommand>(cmd);
    }

    inline static RegisterCommand reg{"exit", &ExitCommand::Create};
};

class EchoCommand : public ICommand
{
public:
    EchoCommand(std::string_view cmd);
    void ParseArgs(const std::vector<std::string>& args) override;
    auto Execute() -> bool override;

private:
    std::string m_Command;

    static auto Create(std::string_view cmd) -> std::unique_ptr<ICommand>
    {
        return std::make_unique<EchoCommand>(cmd);
    }

    inline static RegisterCommand reg{"echo", &EchoCommand::Create};
};

auto Parse(std::string_view) -> bool;
auto DelegateCommand(std::string_view) -> bool;
