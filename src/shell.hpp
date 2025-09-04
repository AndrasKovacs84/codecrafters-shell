#pragma once

class Shell
{
public:
    auto run() -> int;

private:
    bool m_shouldContinue = true;
};
