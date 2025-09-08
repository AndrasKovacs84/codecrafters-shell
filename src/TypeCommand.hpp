#pragma once

#include "ICommand.hpp"
#include "RegisterCommand.hpp"
#include <memory>

class TypeCommand : public ICommand
{
public:
    TypeCommand(std::string_view cmd);
    void ParseArgs() override;
    auto Execute() -> bool override;

private:
    std::string m_Command;

#ifdef _WIN32
    static constexpr char sep = ';';
#else
    static constexpr char sep = ':';
#endif

    static auto Create(std::string_view cmd) -> std::unique_ptr<ICommand>
    {
        return std::make_unique<TypeCommand>(cmd);
    }

    inline static RegisterCommand reg{"type", &TypeCommand::Create};
};
