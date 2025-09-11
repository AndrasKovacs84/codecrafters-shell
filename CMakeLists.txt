cmake_minimum_required(VERSION 3.26)

project(shell-starter-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable experimental modules support on pre-3.30 CMake
if (CMAKE_VERSION VERSION_LESS 3.30)
    set(CMAKE_EXPERIMENTAL_CXX_MODULES ON)
endif()

add_executable(shell
    src/shell/main.cpp
    src/shell/shell.cpp
    src/shell/shell.hpp

    src/core/ICommand.hpp
    src/core/CommandRegistry.cpp
    src/core/CommandRegistry.hpp
    src/core/ExternalCommand.cpp
    src/core/ExternalCommand.hpp
    src/core/RegisterCommand.hpp

    src/builtins/EchoCommand.cpp
    src/builtins/EchoCommand.hpp
    src/builtins/ExitCommand.cpp
    src/builtins/ExitCommand.hpp
    src/builtins/PwdCommand.cpp
    src/builtins/PwdCommand.hpp
    src/builtins/TypeCommand.cpp
    src/builtins/TypeCommand.hpp
)
target_link_libraries(shell PRIVATE readline)
