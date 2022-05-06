/*
 *Jared Migneco
 *Project 6 OSS class
 *
 *05/05/2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/sem.h>


//code from textbook for periodicasterisk
static void myhandler(int s)
{
        char aster = '*';
        int errsave;
        errsave = errno;
        write(STDERR_FILENO, &aster, 1);
        errno = errsave;
}
static int setupinterrupt(void)
{ /* set up myhandler for SIGPROF */
        struct sigaction act;
        act.sa_handler = myhandler;
        act.sa_flags = 0;
        return (sigemptyset(&act.sa_mask) || sigaction(SIGPROF, &act, NULL));
}
static int setupitimer(void)
{ /* set ITIMER_PROF for 1-second intervals */
        struct itimerval value;
        value.it_interval.tv_sec = 1;
        value.it_interval.tv_usec = 0;
        value.it_value = value.it_interval;
        return (setitimer(ITIMER_PROF, &value, NULL));
}




int main (int argc, char *argv[])
{

        pid_t childpid = 0;
        //integers for project. i and j for loops
        int i, j;

        //checks if no arguments are passed
        if (argc <= 1)
        {
                fprintf(stderr, "Usage: %s processes\n", argv[0]);
                return 1;
        }


        //sets default to 100 for seconds if not integer greater than 100
        if (b !> 0)
        {
                fprintf(stderr, "passed second value must be an integer, will be set to 100 by default\n");
                b = 100;
        }


        //creating shared memory address
        int shmid = shmget (0x080698, sizeof(int), 0666 | IPC_CREAT);
        int* shm = (int*)shmat(shmid, NULL, 0);


        *shm = 0;
        printf("OSS: Shared Memory set to 0\n");

        //creation of data structures


        for (int i
        int processID = fork();
        //I think the joke is funny for an error message and refuse to take it out
        //error message if OSS does not fork
        //I still think it's funny
        //I'm still not taking it out
        //I will die on this hill
        if(processID < 0)
        {
                perror("ERROR: you might have spooned instead of forking\n");
                exit(EXIT_FAILURE);
        }
        //worker is executed so long as master successfully forked
        else if(processID == 0)
        {
                execl("./user_proc.c", c, NULL);
        }

        //code taken from periodic asterisk for timer setup
        if (setupinterrupt() == -1)
        {
                perror("Failed to set up handler for SIGPROF");
                return 1;
        }
        if (setupitimer() == -1)
        {
                perror("Failed to set up the ITIMER_PROF interval timer");
                return 1;
        }

        //loop set up for timer
        for (j = 0, j <= b; j++)
        {
                //checks shared memory in loop, terminates if needed
                if (*shm == 0)
                {
                        sleep(1);
                }
                else if (*shm == -1)
                {
                        kill(processID, SIGKILL);
                        printf("OSS: ERROR unable to find file\n");
                        exit(EXIT_FAILURE);
                }
                else
                {
                        break;
                }
        }

        //prints the current j salue that the master loop ended at
        printf("OSS: result took %d seconds\n", j);

        //resetting shared memory
        *shm = 0;
        printf("OSS: shared memory has been reset\n");
        wait(NULL);

        //killing and signalling exit with a success message
        shmctl(shmid, IPC_RMID, NULL);
        printf("OSS has fallen\n");

        return(EXIT_SUCCESS);
}
