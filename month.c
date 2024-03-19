#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{
	char in[100],st[100],*ch,*ch1,c,buff[512];
	DIR *dp;
	int i;
	struct dirent *ep;
	struct stat sb;
	char mon[100];
	dp = opendir("./");
	if(dp!=NULL)
	{
		while(ep=readdir(dp))
		{
			if(stat(ep->d_name,&sb)==-1)
			{
				perror("stat");
				exit(EXIT_SUCCESS);
			}
			strcpy(mon,ctime(&sb.st_ctime));
			ch=strtok(mon," ");
			ch=strtok(NULL,",");
			ch1=strtok(ch," ");
			if((strcmp(ch1,argv[1]))==0)
			{
				printf("%s\t\t%s",ep->d_name,ctime(&sb.st_ctime));
			}
		}
		(void)closedir(dp);
	}
	return 0;
}
