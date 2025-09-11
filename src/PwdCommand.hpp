#pragma once

#include "ICommand.hpp"
#include "RegisterCommand.hpp"

#include <memory>

class PwdCommand : public ICommand
{
public:
    PwdCommand(std::string_view cmd);
    void ParseArgs() override;
    auto Execute() -> bool override;

private:
    std::string m_Command;

    static auto Create(std::string_view cmd) -> std::unique_ptr<ICommand>
    {
        return std::make_unique<PwdCommand>(cmd);
    }

    inline static RegisterCommand reg{"pwd", &PwdCommand::Create};
};
