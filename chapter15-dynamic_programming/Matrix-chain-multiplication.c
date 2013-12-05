#include <stdlib.h>
#include <stdio.h>

/*
 * according to introduction to algorithm,
 * we alloc array(n+1)but make use of the last n 
 * just for convinence
 */
void MATRIX_CHAIN_ORDER(int *p,int n,int **m,int **s)
{
	int i;
	int row = n+1;
	//initialize our array
	for(i=1;i<=n;i++)
		*((int*)m+row*i+i) = 0;

	int l;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=(n-l+1);i++)
		{
			int j = i+l-1;
			*((int*)m+row*i+j) = -1;
			int k;
			for(k=i;k<=(j-1);k++)
			{
				int tmp1 = *((int*)m+row*i+k);
				int tmp2 = *((int*)m+row*(k+1)+j);
				int q = tmp1+tmp2+p[i-1]*p[k]*p[j];

				int old = *((int*)m+row*i+j);
				if(q<old || old == -1)
				{
					*((int*)m+row*i+j) = q;
					*((int*)s+row*i+j) = k;
				}
			}
		}
	}

}

void PRINT_OPTIMAL_PARRNS(int **s,int i,int j,int row)
{
	if(i==j)
		printf("A%d",i);
	else{
		printf("(");
		PRINT_OPTIMAL_PARRNS(s,i,*((int*)s+row*i+j),row);
		PRINT_OPTIMAL_PARRNS(s,*((int*)s+row*i+j)+1,j,row);
		printf(")");
	}
}

int main()
{
	int n = 6;
	int p[7];
	p[0]=30;
	p[1]=35;
	p[2]=15;
	p[3]=5;
	p[4]=10;
	p[5]=20;
	p[6]=25;

	int m[n+1][n+1];
	int s[n+1][n+1];

	MATRIX_CHAIN_ORDER(p,n,(int**)m,(int**)s);
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			printf("%d  ",m[i][j]);
		}
		printf("\n");
	}

	PRINT_OPTIMAL_PARRNS((int**)s,1,6,7);

	return 0;
}
