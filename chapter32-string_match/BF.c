#include <stdio.h>
#include <string.h>

/*
 * if find,return first offset
 * else return -1
 */
int BF_match(char *text,char *pattern)
{
	size_t n = strlen(text);
	size_t m = strlen(pattern);
	int i;
	int end = n-m;

	for(i = 0; i <= end; i++)
	{
		int j;
		char *p_text = text + i;
		for(j = 0;j < m;j++)
		{
			if(*(p_text+j) == *(pattern+j))
				continue;
			else
				break;
		}
		if(j == m)
			return i;
	}
	return -1;
}

int main()
{
	char *s1 = "abcabcabcd";
	char *s2 = "abcd";
	int offset = BF_match(s1,s2);
	printf("offset is %d\n",offset);
	return 0;
}
