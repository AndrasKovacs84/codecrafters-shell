#pragma once

#include "ICommand.hpp"
#include <filesystem>

class ExternalCommand : public ICommand
{
public:
    ExternalCommand(std::string_view cmd, std::filesystem::path binPath);
    void ParseArgs() override;
    auto Execute() -> bool override;

private:
    std::string m_Command;
    std::filesystem::path m_BinPath;
};
