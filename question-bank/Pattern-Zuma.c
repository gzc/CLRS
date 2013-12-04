#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * calculate our next array
 */
int* compute_prefix_function(char *pattern)
{
	int m = strlen(pattern);
	int *next = (int*)malloc(m*sizeof(int));
	next[0]=0;
	int k = 0;
	int q;

	for(q = 1;q < m;q++)
	{
		while(k > 0 && (pattern[k] != pattern[q]) )
			k = next[k-1];
		if (pattern[k] == pattern[q])
			k++;
		next[q] = k;
	}
	return next;
}

int KMP_match(char *text,char *pattern)
{
	int n = strlen(text);
	int m = strlen(pattern);
	int *next = compute_prefix_function(pattern);
	int q = 0;
	int i;

	for(i = 0;i < n;i++)
	{
		while(q > 0 && (pattern[q] != text[i]) )
			q = next[q-1];
		if (pattern[q] == text[i])
			q++;
		if(q == m)
			return i+1-m;
	}
	free(next);
	return -1;
}


int main()
{
	char *s1 = "abtetetedtedddc";
	char *s2 = "ted";
	int n = strlen(s1);
	int m = strlen(s2);
	char *s = (char*)malloc(n*sizeof(char));
	strcpy(s,s1);
	int offset = 0;
	while(1){
		offset = KMP_match(s,s2);
		if(offset < 0)
			break;
		int copy_num = n-offset-m;
		printf("offset = %d\n",offset);
		printf("copy_num = %d\n",copy_num);
		strncpy(s+offset,s+offset+m,copy_num);
		s[n-m] = '\0';
		printf("s = %s\n",s);
	}	
	printf("final str is :%s\n",s);
	free(s);
	return 0;
}
