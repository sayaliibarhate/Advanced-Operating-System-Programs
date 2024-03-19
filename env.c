#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *currentPath = getenv("PATH");
	if(currentPath != NULL)
	{
		printf("Current path : %s\n",currentPath);
	}
	else
	{
		printf("Path environment variable not set!\n");
	}
	char newPath[] = "/new/path : /another/path";
	if(setenv("PATH",newPath,1)==0)
	{
		printf("Path reset successfully!\n");
		char *updatedPath = getenv("PATH");
		if(updatedPath != NULL)
		{
			printf("Updated Path : %s\n",updatedPath);
		}
		else
		{
			printf("PATH environment variable not set!\n");
		}
	}
	else
	{
		printf("Failed to reset PATH\n");
	}

	char *currentHome = getenv("HOME");
        if(currentHome != NULL)
        {
                printf("Current home : %s\n",currentHome);
        }
        else
        {
                printf("Home environment variable not set!\n");
        }
        char newHome[] = "/new/home : /another/home";
        if(setenv("HOME",newHome,1)==0)
        {
                printf("Home reset successfully!\n");
                char *updatedHome = getenv("HOME");
                if(updatedHome != NULL)
                {
                        printf("Updated Home : %s\n",updatedHome);
                }
                else
                {
                        printf("HOME environment variable not set!\n");
                }
        }
        else
        {
                printf("Failed to reset HOME\n");
        }

	char *currentRoot = getenv("ROOT");
        if(currentRoot != NULL)
        {
                printf("Current root : %s\n",currentRoot);
        }
        else
        {
                printf("Root environment variable not set!\n");
        }
        char newRoot[] = "/new/root : /another/root";
        if(setenv("ROOT",newRoot,1)==0)
        {
                printf("ROOT reset successfully!\n");
                char *updatedRoot = getenv("ROOT");
                if(updatedRoot != NULL)
                {
                        printf("Updated Root : %s\n",updatedRoot);
                }
                else
                {
                        printf("ROOT environment variable not set!\n");
                }
        }
        else
        {
                printf("Failed to reset ROOT\n");
        }
}

