/*
 * 2 4 1 16 7 5 11 9
 * after pre process we generate 
 * 1 1 5 5  5 9 9  9
 */

#include <stdio.h>
#include <stdlib.h>

int *pre_process(int *a,int n)
{
	int *b = (int*)malloc(n*sizeof(int));
	int i;
	int min = a[n-1];
	for(i = n-1;i>=0;i--)
	{
		b[i] = min;
		if(a[i] < min)
			min = a[i];
	}
	return b;
}

int f(int *a,int *b,int n)
{
	int i;
	int max = a[0]-b[0];
	for(i = 0;i < n-1;i++)
		if((a[i]-b[i])>max)
			max = a[i]-b[i];
	return max;

}

int main()
{
	int array[8] = {2,4,1,16,7,5,11,9};
	int *b = pre_process(array,8);
	int max = f(array,b,8);
	printf("max =%d\n  ",max);

	return 0;
}
