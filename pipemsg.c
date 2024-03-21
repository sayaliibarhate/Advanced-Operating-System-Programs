/*Write a C program to create an unnamed pipe. The child process will write following 
three messages to pipe and parent process display it. 
Message1 = “Hello World” 
Message2 = “Hello SPPU” 
Message3 = “Linux is Funny” */
#include <stdio.h>
#include <unistd.h>

int main()
{
	int pipefds[2];
	int returnstatus;
	char writemessage[3][20] = {"Hello World","Hello SPPU","Linus is Funny"};
	char readmessage[20];
	returnstatus = pipe(pipefds);
	if(returnstatus == -1)
	{
		printf("Unable to create pipe\n");
		return 1;
	}
	int child = fork();
	if(child==0)
	{
		printf("Child is writing to pipe - Message 1 is %s\n",writemessage[0]);
		write(pipefds[1],writemessage[0],sizeof(writemessage[0]));

		printf("Child is writing to pipe - Message 2 is %s\n",writemessage[1]);
		write(pipefds[1],writemessage[1],sizeof(writemessage[1]));

		printf("Child is writing to pipe - Message 3 is %s\n",writemessage[2]);
		write(pipefds[1],writemessage[2],sizeof(writemessage[2]));
	}
	else
	{
		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("Parent process is reading from pipe - Message 1 is %s\n",readmessage);
		
		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("Parent process is reading from pipe - Message 2 is %s\n",readmessage);

		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("Parent process is reading from pipe - Message 2 is %s\n",readmessage);
	}
}
