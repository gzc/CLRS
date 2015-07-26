#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

int f(char *s1,char *s2)
{
	if(strlen(s1) != strlen(s2))
		return false;
	int n = strlen(s1);
 
	char *tmp = (char*)malloc(2*n*sizeof(char));
	strcpy(tmp,s1);
	strcpy(tmp+n,s1);
	printf("tmp = %s\n",tmp);
	if((strstr(tmp,s2)) != NULL)
	{
		free(tmp);
		return true;
	}
	free(tmp);
	return false;
}

int main()
{
	char *s1 = "abc";
	char *s2 = "cab";

	if(f(s1,s2))
		printf("YES!");
	else
		printf("NO!");

	return 0;
}
