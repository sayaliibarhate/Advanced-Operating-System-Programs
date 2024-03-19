#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
int main(void)
{
	struct dirent **namelist;
	int n;
	int i=0;
	n = scandir(".",&namelist,0,alphasort);
	if(n<0)
		perror("Scandir error");
	else
	{
		while(i<n)
		{
			printf("%s\n",namelist[i]->d_name);
			free(namelist[i]);
			i++;
		}
		free(namelist);
	}
}
