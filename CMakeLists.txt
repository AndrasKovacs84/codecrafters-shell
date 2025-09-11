cmake_minimum_required(VERSION 3.26)

project(shell-starter-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable experimental modules support on pre-3.30 CMake
if (CMAKE_VERSION VERSION_LESS 3.30)
    set(CMAKE_EXPERIMENTAL_CXX_MODULES ON)
endif()

add_executable(shell
    src/CommandRegistry.cpp
    src/CommandRegistry.hpp
    src/EchoCommand.cpp
    src/EchoCommand.hpp
    src/ExitCommand.cpp
    src/ExitCommand.hpp
    src/ExternalCommand.cpp
    src/ExternalCommand.hpp
    src/ICommand.hpp
    src/main.cpp
    src/PwdCommand.cpp
    src/PwdCommand.hpp
    src/RegisterCommand.hpp
    src/shell.cpp
    src/shell.hpp
    src/TypeCommand.cpp
    src/TypeCommand.hpp
)
target_link_libraries(shell PRIVATE readline)
