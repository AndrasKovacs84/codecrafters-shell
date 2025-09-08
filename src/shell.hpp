#pragma once

#include <optional>
#include <string>

class Shell
{
public:
    auto run() -> int;
    static auto GetEnv(std::string_view var) -> std::optional<std::string>;
    static auto SearchOnPath(std::string_view entry, std::string_view path)
        -> bool;

private:
    bool m_shouldContinue = true;
};
