#pragma once

#include <iostream>

auto Parse(std::string_view) -> bool;
auto DelegateCommand(std::string_view) -> bool;
