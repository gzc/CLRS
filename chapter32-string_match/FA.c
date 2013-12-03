#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0

int min(int a,int b)
{
	if(a > b)
		return b;
	return a;
}

//check whether Pk is suffix of Pq
int suffix(char *pattern,int k,int q,char ch)
{
	int i;
	if(pattern[k-1] != ch)
		return false;
	for(i = 0;i < k-1;i++)
		if(pattern[i] != pattern[q-k+i+1])
			return false;
	return true;
}

/*
 * construct our FA
 */
void compute_transition_function(char *pattern,int *array,int numchars)
{
	int m = strlen(pattern);
	int q;
	
	for(q = 0; q <= m; q++)
	{
		int chars;
		for(chars = 0; chars < numchars; chars++)
		{
			int k = min(m,q+1);
			while(k)
			{
				char ch = 'a'+chars;
				if(suffix(pattern,k,q,ch))
					break;
				k--;
			}
			array[q*numchars+chars] = k;
		}
	}
}

int FA_match(char *text,int *array,int numchars,int receive)
{
	int n = strlen(text);
	int q = 0;
	int i;
	for(i = 0;i < n;i++)
	{
		int index = numchars*q+text[i]-97;    
		q = array[index]; 
		if(q == receive)
			return i+1-receive;
	}
	return -1;
}

int main()
{
	char *text = "abababacaba";
	char *pattern = "ababaca";
	int length = strlen(pattern);
	int *array = (int*)malloc(3*(length+1));
	
	compute_transition_function(pattern,array,3);
	
	int i;
	printf("This is our chart\n");
	for(i = 0;i <= length; i++)
	{
		int j;
		for(j = 0; j < 3; j++)
			printf("%d  ",array[i*3+j]);
		printf("\n");
	}
	int offset = FA_match(text,array,3,length);
	printf("offset is %d\n",offset);
	free(array);
	return 0;
}
