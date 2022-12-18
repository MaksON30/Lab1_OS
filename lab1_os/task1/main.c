#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"

int main()
{
    if(fork() == 0)
    {
        if (fork()==0)
        {
            if (fork()==0)
            {
                if (fork()==0)
                {
                    if (fork()==0)
                    {
                        fork();
                    }
                }
            }
        }
    }
    
    sleep(20000);
    return 0;
}