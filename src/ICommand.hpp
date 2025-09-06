#pragma once

class ICommand
{
public:
    virtual void ParseArgs() = 0;
    virtual auto Execute() -> bool = 0;
    virtual ~ICommand() = default;
};
