#include <stdio.h>
#include <string.h>
#include <math.h>

//we find a prime 11!+1   a seven-digit prime
int factorial(int n)
{
	if(n == 1)
		return 1;
	else
		return n*factorial(n-1);
}


/*
 * d is the base
 * and q is the prime wo choose
 * if find,return first offset
 * else return -1
 */
int RK_match(char *text,char *pattern,int d,int q)
{
	size_t n = strlen(text);
	size_t m = strlen(pattern);
	size_t h = (size_t)pow(d,m-1);
	int p = 0;
	int t = 0;
	int k = 96; //'a' is 1; 'b' is 2 and so on

	int i;
	for(i = 0; i < m; i++)
	{
		p = (d*p+pattern[i]-k)%q;
		t = (d*t+text[i]-k)%q;
	}

	for(i = 0; i <= (n-m); i++)
	{
		/*
		 * we made it a Las Vegas algorithm
		 * to check if the string really same?
		 */
		if(p == t)
		{
			int j;
			char *p_text = text+i;
			
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

		//calculate the next num
		if(i < (n-m))
		{
			int s = (d*(t-(text[i]-k)*h))+text[i+m]-k;
			t = s%q;
		}	
	}

	return -1;
}

