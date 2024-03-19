#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(mode_t mode)
{
	if(S_ISREG(mode))
		printf("Regular file\n");
	else if(S_ISDIR(mode))
		printf("Directory\n");
	else if(S_ISCHR(mode))
		printf("Character Device\n");
	else if(S_ISBLK(mode))
		printf("Block Device\n");
	else if(S_ISFIFO(mode))
		printf("FIFO or Pipe\n");
	else if(S_ISLNK(mode))
		printf("Symbollic Link\n");
	else if(S_ISSOCK(mode))
		printf("Socket\n");
	else
		printf("Unknown file type!\n");
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr,"Usage : %s <filename>\n",argv[0]);
		return 1;
	}
	struct stat fileStat;
	if(stat(argv[1],&fileStat)==-1)
	{
		perror("Error");
		return 1;
	}
	printf("File type of %s : ",argv[1]);
	print_file_type(fileStat.st_mode);
	return 0;
}
