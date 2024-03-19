#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int fd[2];
	char buf[30];
	if(pipe(fd) == -1)
	{
		perror("Error creating a pipe\n");
		exit(1);
	}
	if(!fork())
	{
		printf("CHILD : Writing to pipe\n");
		write(fd[1],"Hello mother (or father ?)",26);
		printf("CHILD : Exiting\n");
		exit(0);
	}
	else
	{
		printf("PARENT : Reading from pipe\n");
		read(fd[0],buf,26);		
		printf("PARENT : Read \"%s\" ",buf);
		wait(NULL);
		printf("PARENT : Exiting\n");
	}
	return (0);
}
