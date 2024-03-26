/*Write a C rpogram which creates a child process and parent process catches a signal SIGHUP, SIGINT and SIGQUIT. The parent process send SIGHUP or SIGINT signal after every 3 seconds, at the end of 15 seconds parent send SIGQUIT singal to child and child terminates by displaying message - My Papa has killed me!!!*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
void child_signal_handler(int signum)
{
	switch(signum)
	{
		case SIGHUP:
			printf("Child : I have received SIGHUP\n");
			break;
		case SIGINT:
			printf("Child : I have received SIGINT\n");
			break;
		case SIGQUIT:
			printf("My Papa has killed me!!!\n");
			break;
		default:
			printf("Child : Received unexpected signal\n");
	}
}
int main()
{
	pid_t pid;
	int i;
	pid=fork();
	if(pid<0)
	{
		perror("fork");
		exit(1);
	}
	if(pid==0) //Child process
	{
		signal(SIGHUP,child_signal_handler);
		signal(SIGINT,child_signal_handler);
		signal(SIGQUIT,child_signal_handler);
		while(1)
		{
			//Child process keeps running until terminated by SIGHQUIT
			sleep(1); //Just to prevent bust waiting
		}
	}
	else
	{
		//Parent process
		//Send SIGHUP or SIGINT every 3 seconds for 15 seconds
		for(i=1 ; i<=5 ; i++)
		{
			sleep(3);
			if(i%2 == 0)
			{
				printf("Parent : Sending SIGHUP signal\n");
				kill(pid,SIGHUP);
			}
			else
			{
				printf("Parent : Sending SIGINT signal\n");
				kill(pid,SIGINT);
			}
		}
		//send SIGQUIT to terminate child after 15 seconds
		sleep(3);
		printf("Parent : Sending SIGQUIT signal to terminate child\n");
		kill(pid,SIGQUIT);
	}
	return 0;
}
