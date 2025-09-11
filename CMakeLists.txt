cmake_minimum_required(VERSION 3.26)

project(shell-starter-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable experimental modules support on pre-3.30 CMake
if (CMAKE_VERSION VERSION_LESS 3.30)
    set(CMAKE_EXPERIMENTAL_CXX_MODULES ON)
endif()

file(GLOB_RECURSE CORE_SRC   src/core/*.cpp src/core/*.hpp)
file(GLOB_RECURSE BUILTIN_SRC src/builtins/*.cpp src/builtins/*.hpp)
file(GLOB_RECURSE SHELL_SRC   src/shell/*.cpp src/shell/*.hpp)

add_executable(shell
    ${CORE_SRC}
    ${BUILTIN_SRC}
    ${SHELL_SRC}
)
target_link_libraries(shell PRIVATE readline)
