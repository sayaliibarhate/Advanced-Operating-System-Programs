#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigfun(int sig)
{
	printf("You have pressed Ctrl-C, please press again to exit");
	(void) signal(SIGINT,SIG_DFL);
}

int main()
{
	(void) signal(SIGINT,sigfun);
	while(1)
	{
		printf("Hello World!");
		sleep(1);
	}
	return 0;
}
