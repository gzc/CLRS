#include <stdio.h>


/*
 * I regard it as a KNAPSACK problem
 */



int max(int a,int b)
{
	if(a<b)
		return b;
	return a;
}

/*
 * give you 2,3,4,5
 * can you find sum 9
 */

int main()
{
	int a[5] = {0,2,3,4,5};     //ignore a[0],actually we have 2,3,4,5 
	int V[5][10];
	int sum = 9;
	int i,j;
	for(i = 0;i <= 4;i++)
		V[i][0]=0;
	for(j = 0;j <= sum;j++)
		V[0][j]=0;
	for(i = 1;i <= 4;i++)
	{
		for(j = 1;j <= sum;j++)
		{
			V[i][j] = V[i-1][j];
			if(a[i] <= j)
				V[i][j] = max(V[i][j],V[i-1][j-a[i]]+a[i]);
		}
	}

	for(i = 0;i <= 4;i++)
	{
		for(j = 0;j <= sum;j++)
			if(sum == V[i][j])
				printf("We find it!!!\n");
	}

	return 0;
}
