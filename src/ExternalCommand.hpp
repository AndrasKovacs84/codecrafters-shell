#pragma once

#include "ICommand.hpp"
#include <filesystem>
#include <vector>

class ExternalCommand : public ICommand
{
public:
    ExternalCommand(std::string_view cmd, std::filesystem::path binPath);
    void ParseArgs() override;
    auto Execute() -> bool override;

private:
    static auto runCommand(const std::string& bin, const std::vector<std::string>& args) -> int;
    std::string m_Command;
    std::filesystem::path m_BinPath;
};
