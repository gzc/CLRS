#include <stdio.h>
#include <stdlib.h>

int Fastway(int *a1,int *a2,int *t1,int *t2,int *e,int *x,int n,int *l1,int *l2,int *value)
{
	int *f1 = (int*)malloc(n*sizeof(int));
	int *f2 = (int*)malloc(n*sizeof(int));

	f1[0] = e[0]+a1[0];
	f2[0] = e[1]+a2[0];

	int i;
	for(i = 1;i < n;i++)
	{
		if(f1[i-1] < (f2[i-1]+t2[i-1]))
		{
			f1[i] = f1[i-1]+a1[i];
			l1[i-1] = 1;
		}else{
			f1[i] = f2[i-1]+t2[i-1]+a1[i];
			l1[i-1]=2;
		}

		if(f2[i-1] < (f1[i-1]+t1[i-1]))
		{
			f2[i] = f2[i-1]+a2[i];
			l2[i-1] = 2;
		}else{
			f2[i] = f1[i-1]+t1[i-1]+a2[i];
			l2[i-1] = 1;
		}
	}

	if((f1[n-1]+x[0]) < (f2[n-1]+x[1]))
	{
		*value = f1[n-1]+x[0];
		free(f1);
		free(f2);
		return 1;
	}else {
		*value = f2[n-1]+x[1];
		free(f1);
		free(f2);
		return 2;
	}
}

void PRINT_STATIONS(int *l1,int *l2,int way,int n)
{
	printf("line%d,station%d\n",way,n);
	int i;
	for(i=(n-2);i>=0;i--)
	{
		if(way == 1)
			way = l1[i];
		else 
			way = l2[i];

		printf("line%d,station%d\n",way,i+1);

	}
}

void reverse_PRINT_STATIONS(int *l1,int *l2,int way,int n)
{
	int new_way;
	if(way == 1)
		new_way = l1[n-2];
	else
		new_way = l2[n-2];
	if(n >= 2)
		reverse_PRINT_STATIONS(l1,l2,new_way,n-1);
	printf("line%d,station%d\n",way,n);
}

int main()
{
	int n = 6;
	int e[2];
	e[0]=2;
	e[1]=4;

	int x[2];
	x[0]=3;
	x[1]=2;

	int t1[5],t2[5];
	t1[0]=2;
	t1[1]=3;
	t1[2]=1;
	t1[3]=3;
	t1[4]=4;
	t2[0]=2;
	t2[1]=1;
	t2[2]=2;
	t2[3]=2;
	t2[4]=1;

	int a1[6],a2[6];
	a1[0]=7;
	a1[1]=9;
	a1[2]=3;
	a1[3]=4;
	a1[4]=8;
	a1[5]=4;
	a2[0]=8;
	a2[1]=5;
	a2[2]=6;
	a2[3]=4;
	a2[4]=5;
	a2[5]=7;

	int value;
	int *l1 = (int*)malloc((n-1)*sizeof(int));
	int *l2 = (int*)malloc((n-1)*sizeof(int));
	int way = Fastway(a1,a2,t1,t2,e,x,n,l1,l2,&value);
	printf("value = %d\n",value);
	reverse_PRINT_STATIONS(l1,l2,way,n);
	return 0;
}
