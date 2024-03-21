/*Write a C program to create a file with hole in it. */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
char buf1[] = "Welcome";
char buf2[] = "Computer Science";
int main(void)
{
	int fd;
	if((fd = creat("filewithhole.txt",0777))<0)
		printf("File creating error");
	if(write(fd,buf1,7) != 7)
		printf("buf1 write error");
	lseek(fd,250,SEEK_CUR);
	if(write(fd,buf2,16) != 16)
		printf("buf2 write error");
	exit(0);
}
