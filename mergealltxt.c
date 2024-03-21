/*Write a C program to read all txt files (that is files that ends with .txt) in the current 
directory and merge them all to one txt file and returns a file descriptor for the new file*/
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main(void)
{
	FILE *input,*output;
	char ch;
	char *txt=".txt";
	struct dirent *de;	
	DIR *dr = opendir(".");
	if(dr==NULL)
	{
		printf("Can't open directory!");
		return 0;
	}
	while((de=readdir(dr))!=NULL)
	{
		char *filename=de->d_name;
		char *ext=strrchr(filename,'.');
		if(!(!ext || ext==filename))
		{
			if(strcmp(ext,txt)==0)
			{
				output=fopen("output.txt","a+");
				input=fopen(filename,"r");
				while(1)
				{
					ch=fgetc(input);
					if(ch==EOF)break;
					putc(ch,output);
				}
				fclose(input);
				fclose(output);
			}
		}
	}
	closedir(dr);
	printf("Successfully copied the contents of all .txt file into output.txt\n");
	return 0;
}
