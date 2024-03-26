/*Write a C program ehich receives file names as command line arguments and siaplay those filenames in ascending order according to their sizes.*/
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
struct filelist
{
	char fname[100];
	int fsize;
};
int main(int argc, char *argv[])
{
	DIR *dp;
	int i,j,k;
	struct dirent *ep;
	struct stat sb;
	char mon[100];
	struct filelist f1[100],temp;
	j=0;
	for(i=1 ; i<argc ; i++)
	{
		dp=opendir("./");
		if(dp!=NULL)
		{
			while(ep=readdir(dp))
			{
				if(strcmp(ep->d_name,argv[i])==0)
				{
					stat(ep->d_name,&sb);
					strcpy(f1[j].fname,ep->d_name);
					f1[j].fsize=sb.st_size;
					j++;
					break;
				}
			}
		}
		(void)closedir(dp);
	}
	for(i=0 ; i<j ; i++)
	{
		for(k=0 ; k<=j ; k++)
		{
			if(f1[i].fsize<f1[k].fsize)
			{
				temp=f1[k];
				f1[k]=f1[i];
				f1[i]=temp;
			}
		}
	}
	for(i=0 ; i<j ; i++)
	{
		printf("%s\t%d\n",f1[i].fname,f1[i].fsize);
	}
	return 0;
}
