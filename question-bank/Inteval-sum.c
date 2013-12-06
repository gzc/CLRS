/*
 *
 * 只给一个数组 a(大小为 n),用户不断输入 i,j 以获取从 a[i]到 a[j]的区间和,要求在多次询 问时的平均时间复杂度达到 O(1)
 *
 */

#include <stdio.h>

void pre_process(int *a,int n)
{
	int i;
	for(i = 1;i < n;i++)
		a[i] = a[i-1]+a[i];
}

int query(int *a,int i,int j)
{
	if(i == 0)
		return a[j];
	return a[j]-a[i-1];
}

int main()
{
	int a[10] = {1,3,5,7,9,2,4,6,8,10};
	pre_process(a,10);
	int sum = query(a,2,4);
	printf("sum of a[2] to a[4] is:%d\n",sum);

	return 0;
}
