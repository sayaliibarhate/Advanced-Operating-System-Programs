/*Write a C program to find file properties such as inode number, number of hard link, File 
permissions, File size, File access and modification time and so on of a given file using 
fstat() system call. */
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
	if(argc != 2)
		return 1;
	int file=0;
	if((file=open(argv[1],O_RDONLY)) < -1)
		return 1;
	struct stat filestat;
	if(fstat(file,&filestat) < 0)
		return 1;
	printf("Info for %s\n",argv[1]);
	printf("----------------------------------\n");
	printf("I-node number : \t\t%d \n", filestat.st_ino);
	printf("File size : \t\t%d bytes \n",filestat.st_size);
	printf("No. of hard links : \t%d\n",filestat.st_nlink);
	printf("File permission : \t");
	printf((S_ISDIR(filestat.st_mode)) ? "d" : "-");
	printf((filestat.st_mode & S_IRUSR) ? "r" : "-");
	printf((filestat.st_mode & S_IWUSR) ? "w" : "-");
	printf((filestat.st_mode & S_IXUSR) ? "x" : "-");
	printf((filestat.st_mode & S_IRGRP) ? "r" : "-");
	printf((filestat.st_mode & S_IWGRP) ? "w" : "-");
	printf((filestat.st_mode & S_IXGRP) ? "x" : "-");
	printf((filestat.st_mode & S_IROTH) ? "r" : "-");
	printf((filestat.st_mode & S_IWOTH) ? "w" : "-");
	printf((filestat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n");
	close(file);
	return 0;
}

