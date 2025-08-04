#pragma once

#include <iostream>
#include <vector>

namespace command
{

bool Parse(std::string_view);
bool DelegateCommand(std::string_view);
bool Echo(std::string_view);

} //command
