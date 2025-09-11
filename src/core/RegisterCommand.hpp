#pragma once

#include "CommandRegistry.hpp"
#include <iostream>

struct RegisterCommand
{
    RegisterCommand(const std::string& name, CommandFactory factory)
    {
        CommandRegistry::Get().emplace(name, std::move(factory));
    }
};
