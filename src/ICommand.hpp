#pragma once

#include <iostream>
#include <vector>

class ICommand
{
public:
    virtual void ParseArgs(const std::vector<std::string>& args) = 0;
    virtual auto Execute() -> bool = 0;
    virtual ~ICommand() = default;
};
