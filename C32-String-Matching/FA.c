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
		int index = numchars*q+text[i]-'a';
		q = array[index]; 
		if(q == receive)
			return i+1-receive;
	}
	return -1;
}

int main()
{
	char *text = "aaababaabaababaab";
	char *pattern = "aabab";
	const int num_chars_alphabet = 2;
	int length = strlen(pattern);
	int *array = (int*)malloc(sizeof(int)*num_chars_alphabet*(length+1));
	
	compute_transition_function(pattern,array,num_chars_alphabet);
	
	
	//This prints a chart showing present state and next states given
	//the corresponding inputs.
	printf("This is our chart\nstate\t");
	for(char j = 'a'; j < 'a'+num_chars_alphabet; j++)
		printf("%c\t", j);
    printf("\n");
    
    int i;
	for(i = 0;i <= length; i++)
	{
	    printf("%d\t",i);
		int j;
		for(j = 0; j < num_chars_alphabet; j++)
			printf("%d\t",array[i*num_chars_alphabet+j]);
		printf("\n");
	}
	int offset = FA_match(text,array,num_chars_alphabet,length);
	printf("offset is %d\n",offset);
	free(array);
	return 0;
}
