#ifndef PROCESSES_H
#define PROCESSES_H

#include <memory>
#include <sys/types.h>
#include <vector>
#include <functional>
#include <pthread.h>

namespace Process
{
    int createChildProgram(std::vector<pid_t>& child_pids, char* program, char* args[]);
    int createChildFunction(std::vector<pid_t>& child_pids, std::function<void()> execute);
    void killProcesses(std::vector<pid_t>& children_processes);
};

#endif
