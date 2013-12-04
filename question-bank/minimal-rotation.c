#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * s is the text
 * indexs is the array which store our optional position
 * and num implies the number of indexes remained
 */
int foobar(char *s,int length,int *indexs,int num,int level)
{
	if(num == 1 || level == (length-1))
		return indexs[0];
	char min_ch = s[(indexs[0]+level)%length];
	int i;
	//find the minium char at the offset level
	for(i = 1;i < num;i++)
	{
		if(min_ch > s[(indexs[i]+level)%length])
			min_ch = s[(indexs[i]+level)%length];
	}
	//refresh our indexs
	int good_positions = 0; 
	for(i = 0;i < num;i++)
	{
		if(s[(indexs[i]+level)%length] == min_ch)
		{
			indexs[good_positions] = indexs[i];
		   good_positions++;
		}
	}	
	return foobar(s,length,indexs,good_positions,level+1);
}

int main()
{
	char *s = "bbabbaaccdef";
	int length = strlen(s);
	int *array = (int*)malloc(length*sizeof(int));
	int i;
	for(i = 0;i < length;i++)
		array[i]=i;
	int position = foobar(s,length,array,length,0);
	printf("The position is:%d\n",position);
	free(array);
	return 0;
}

