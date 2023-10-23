#include "processes.hpp"
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <cstdlib>

namespace
{
    #define FORK_ERROR_MESSAGE "Failed to fork process." 
    #define EXEC_ERROR_MESSAGE "Failed to execute "
    #define FORK_ERROR_CODE -1
    #define FORK_CHILD_CODE 0
    #define NOTHING 0
}

namespace
{
    void errorCheckFork(int pid)
    {
        if (pid == FORK_ERROR_CODE) {
            std::cerr << FORK_ERROR_MESSAGE << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    bool isChild(int pid)
    {
        errorCheckFork(pid);
        return pid == FORK_CHILD_CODE;
    }

    void handleExecFail(char* program)
    {
        std::cerr << EXEC_ERROR_MESSAGE << program << std::endl;
        exit(EXIT_FAILURE);
    }

    void executeProgram(char* program, char* args[])
    {
        execvp(program, args);
        handleExecFail(program);
    }
}

int Process::createChildProgram(std::vector<pid_t>& child_pids, char* program, char* args[])
{
    pid_t pid = fork();
    if (isChild(pid)) {
        executeProgram(program, args);
        return NOTHING;
    }
    else { // Parent Process
        child_pids.push_back(pid);
        return child_pids.size();
    }
}

int Process::createChildFunction(std::vector<pid_t>& child_pids, std::function<void()> execute)
{
    pid_t pid = fork();
    if (isChild(pid)) {
        execute();
        _exit(EXIT_SUCCESS);
    }
    else { // Parent Process
        child_pids.push_back(pid);
        return child_pids.size();
    }        
}

void Process::killProcesses(std::vector<pid_t>& children_processes)
{
    for (pid_t child_pid : children_processes) {
        printf("Process ID is %d\n", child_pid);
        fflush(stdout); 
        kill(child_pid, SIGTERM);
    }
    children_processes.clear();
}