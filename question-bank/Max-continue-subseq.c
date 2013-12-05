/*
 * maximum contiguous subsequence. 
 * A contiguous subsequence of a list S is a subsequence made up of consecutive elements of S.
 * For instance, if S is 5, 15, −30, 10, −5, 40, 10,
 * then 15, −30, 10 is a contiguous subsequence but 5, 15, 40 is not.
 * Give a linear-time algorithm for the following task:
 * Input: A list of numbers, a1, a2, . . . , an.
 * Output: The contiguous subsequence of maximum sum (a subsequence of length zero has sum zero).
 * For the preceding example, the answer would be 10, −5, 40, 10, with a sum of 55.
 *
 */













/*
 * Solution:
 * we construct a f(n)
 * f(n) = f(n-1)+a(n)    if  f(n-1) >= 0
 *	    = an			 if  f(n-1) < 0
 *	    = a0             if  n = 0
 *
 *	    for example
 *
 *	    a(n)      5 15 -30 10 -5 40 10
 *	    f(n)	  5 20 -10 10 5  45 55
 *	    and we find the max in f(n) is 55,and we can easily compute the sequence
 *	    All operations can be done in O(n)
 *
 */

#include <stdlib.h>
#include <stdio.h>


int* pre_process(int *a,int n)
{
	int *f = (int*)malloc(n*sizeof(int));
	int i;
	for(i = 0;i < n;i++)
	{
		if(i == 0)
			f[i] = a[i];
		else if(f[i-1] >= 0)
			f[i] = f[i-1]+a[i];
		else
			f[i] = a[i];
	}
	return f;
}

int FIND_MAX(int *a,int n)
{
	int *f = pre_process(a,n);
	int i;
	int max = f[0];
	for(i = 1;i < n;i++)
		if(f[i] > max)
			max = f[i];
	free(f);
	return max;
}

int main()
{
	int n = 7;
	int a[] = {5,15,-30,10,-5,40,10};
	int max = FIND_MAX(a,n);
	printf("max =%d\n",max);

	return 0;
}
