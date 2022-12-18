#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"

int main(int argc, char* argv[])
{
    int pid = fork();
    int status = 0;

    if (pid == 0)
    {
        char* argv_copy[argc];

        for (int i = 1; i < argc; i++)
        {
            argv_copy[i - 1] = argv[i];
        }
            
        argv_copy[argc - 1] = NULL;

        execvp(argv[1], argv_copy);
    }
    else
    {
        waitpid(pid, &status, 0);

        if (status != 0)
            printf("Failed, exit code = %d\n", status);
        else
            printf("Succes!\n");
    }

    return 0;
}