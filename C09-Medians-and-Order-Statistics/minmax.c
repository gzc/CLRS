/*************************************************************************
	> File Name: minmax.c
	> Author: Louis1992
	> Mail: zhenchaogan@gmail.com
	> Blog: http://gzc.github.io
	> Created Time: Sat May 23 23:04:35 2015
 ************************************************************************/
#include<stdio.h>

#define maxf(a,b) ((a) >= (b) ? (a) : (b))
#define minf(a,b) ((a) <= (b) ? (a) : (b))

void minmax(int *arr, int n, int *maximum, int *minium)
{
    int i = 0;
    if(n % 2 == 1)
    {
        *maximum = arr[0];
        *minium = arr[0];
        i = 1;
    } else {
        if(arr[1] >= arr[0])
        {
            *maximum = arr[1];
            *minium = arr[0];
        } else {
            *maximum = arr[0];
            *minium = arr[1];
        }
        i = 2;
    }

    for(;i < n;i += 2)
    {
        if(arr[i] >= arr[i+1])
        {
            *maximum = maxf(*maximum, arr[i]);
            *minium = minf(*minium, arr[i+1]);
        } else {
            *maximum = maxf(*maximum, arr[i+1]);
            *minium = minf(*minium, arr[i]);
        }
    }
}

int main()
{
    int arr[5] = {3,5,-1,0,2};
    int maximum = 0,minium = 0;
    minmax(arr, 5, &maximum, &minium);
    printf("max=%d min=%d/n", maximum, minium);
}
