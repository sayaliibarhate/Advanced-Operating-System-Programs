/*Program that prints exit status of a terminated child process*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	int status;
	pid=fork();
	if(pid<0)
	{
		//Error occurred
		fprintf(stderr,"Fork failed\n");
		return 1;
	}
	else if(pid==0)
	{
		//Child process
		printf("Child process running\n");
		//Simulating some work before exit
		sleep(2);
		//Simulating different exit status
		int exit_status = rand()%100;
		printf("Child process exiting with status: %d\n",exit_status);
		exit(exit_status);
	}
	else
	{
		//parent process
		printf("Parent process waiting for child to terminnate\n");
		waitpid(pid,&status,0);
		if(WIFEXITED(status))
		{
			printf("Child process exited with status : %d\n",WEXITSTATUS(status));
		}
		else
		{
			printf("Child process exited abnormally\n");
		}
	}
}
