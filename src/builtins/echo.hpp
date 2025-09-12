#pragma once

#include "../core/ICommand.hpp"
#include "../core/RegisterCommand.hpp"
#include <memory>

class EchoCommand : public ICommand
{
public:
    EchoCommand(std::string_view cmd);
    void ParseArgs() override;
    auto Execute() -> bool override;

private:
    std::string m_Command;

    static auto Create(std::string_view cmd) -> std::unique_ptr<ICommand>
    {
        return std::make_unique<EchoCommand>(cmd);
    }

    inline static RegisterCommand reg{"echo", &EchoCommand::Create};
};
