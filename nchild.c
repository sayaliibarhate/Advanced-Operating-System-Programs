/*Write a C program to creaye n processes. When all n child process terminates, display total cummulative time children spent in user and kernal mode*/
#include <stdio.h>
#include<sys/times.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
	int i,status;
	pid_t pid;
	time_t currentTime;
	struct tms cpuTime;
	if((pid=fork())==-1) //Start child process
	{
		perror("\nFork error");
		exit(EXIT_FAILURE);
	}
	else if(pid==0) //Child process
	{
		time(&currentTime);
		printf("\nChind process started at %s",ctime(&currentTime));
		for(i=0 ; i<5 ; i++)
		{
			printf("\nCounting = %dn",i); //count from 5 seconds
			sleep(1);
		}
		time(&currentTime);
		printf("\nChild process ended at %s",ctime(&currentTime));
		exit(EXIT_SUCCESS);
	}
	else 
	{
		//Parent process
		time(&currentTime);
		printf("\nParent process started at %s",ctime(&currentTime));
		if(wait(&status)==-1) //wait for child process
			perror("\nWait error");
		if(WIFEXITED(status))
			printf("\nChild process ended normally");
		else
			printf("\nChild process ended abnormally");
		if(times(&cpuTime)<0) //get process time
			perror("\nTimes error");
		else
		{
			//SC_CLK_TCK : System configuration time : seconds clock tick
			printf("\nParent process user time = %fn",((double)cpuTime.tms_utime));
			printf("\nParent process system time = %fn",((double)cpuTime.tms_stime));
			printf("\nChild process user time = %fn",((double)cpuTime.tms_utime));
			printf("\nChild process system time = %fn",((double)cpuTime.tms_stime));
		}
		time(&currentTime);
		printf("\nParent process ended at %s",ctime(&currentTime));
		exit(EXIT_SUCCESS);
	}
}
