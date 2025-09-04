#pragma once

#include <iostream>
#include <vector>

class ICommand
{
public:
    virtual void ParseArgs(const std::vector<std::string>& args) = 0;
    virtual auto operator()() -> bool = 0;
    virtual ~ICommand() = default;
};

class ExitCommand : public ICommand
{
public:
    ExitCommand(std::string_view cmd);
    void ParseArgs(const std::vector<std::string>& args) override;
    auto operator()() -> bool override;

private:
    std::string m_Command;
};

class EchoCommand : public ICommand
{
public:
    EchoCommand(std::string_view cmd);
    void ParseArgs(const std::vector<std::string>& args) override;
    auto operator()() -> bool override;

private:
    std::string m_Command;
};

auto Parse(std::string_view) -> bool;
auto DelegateCommand(std::string_view) -> bool;
