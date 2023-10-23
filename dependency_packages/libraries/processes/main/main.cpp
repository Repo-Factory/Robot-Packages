#include "processes.hpp"
#include <vector>
#include <iostream>
#include <sys/wait.h>

namespace
{
    #define PROGRAM_PATH "ping"
}

// "ping", "ping", "google.com", 

int main(int argc, char * argv[])
{
    // std::vector<pid_t> child_pids;
    // const char* args[] = {"ping", "google.com", NULL};
    
    // for (int i = 0; i < 10; i++)
    // {
    //     Process::createChildProgram(child_pids, PROGRAM_PATH, args);
    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     Process::createChildFunction(child_pids, [](){
    //     int j = 0;
    //     while (j < 1000000)
    //     {
    //         std::cout << j << "     " << getpid() <<std::endl;
    //         j++;
    //     }});
    // }
    
    // sleep(2);
    // int status;

    // for (pid_t child_pid : child_pids) {
    //     printf("Process ID is %d\n", child_pid);
    //     fflush(stdout); 
    //     kill(child_pid, SIGTERM);
    // }
    exit(EXIT_SUCCESS);
}
