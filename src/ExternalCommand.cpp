#include "ExternalCommand.hpp"
#include <ranges>
#include <utility>

#ifdef _WIN32
#    include <process.h>
#else
#    include <sys/wait.h>
#    include <unistd.h>
#endif

namespace shell
{

constexpr int EXIT_EXEC_FAILURE = 127;

}

ExternalCommand::ExternalCommand(std::string_view cmd, std::filesystem::path binPath)
    : m_Command(cmd)
    , m_BinPath(std::move(binPath))
{}

void ExternalCommand::ParseArgs()
{}

auto ExternalCommand::Execute() -> bool
{
    std::vector<std::string> result;
    for (auto&& token : m_Command | std::views::split(' '))
    {
        result.emplace_back(token.begin(), token.end());
    }
    // TODO return actual code...
    return !static_cast<bool>(
        runCommand(m_BinPath, result[0], std::vector<std::string>{result.begin() + 1, result.end()}));
}

auto ExternalCommand::runCommand(const std::filesystem::path& resolvedPath,
                                 const std::string& bin,
                                 const std::vector<std::string>& args) -> int
{
    std::vector<char*> argv;
    argv.reserve(args.size() + 2);
    argv.push_back(const_cast<char*>(bin.c_str()));
    for (const auto& arg : args)
    {
        argv.push_back(const_cast<char*>(arg.c_str()));
    }
    argv.push_back(nullptr);

#ifdef _WIN32
    return _spawnvp(_P_WAIT, bin.c_str(), argv.data());

#else
    pid_t pid = fork();
    if (pid == 0)
    {
        execv(resolvedPath.c_str(), argv.data());
        _exit(shell::EXIT_EXEC_FAILURE);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            return WEXITSTATUS(status);
        }
        return -1;
    }
    else
    {
        return -1;
    }
#endif
}
