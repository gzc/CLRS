#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a,int b)
{
	if(a > b)
		return a;
	return b;
}

/*
 * from http://www.cnblogs.com/dsky/archive/2012/05/04/2483190.html
 */
int BM_match(char* pSrc, int nSrcSize, char* pSubSrc, int nSubSrcSize)
{

    //1.坏字符数组
    int bcSkip[256];
	int i;
    for( i = 0; i < 256; i++)  
    {
        bcSkip[i] = nSubSrcSize;
    }
    for (i = 0; i < nSubSrcSize - 1; i++)
    {
        bcSkip[pSubSrc[i]] = nSubSrcSize - i - 1;
    }

    //2.好后缀数组
    int* suffix =(int*)malloc(nSubSrcSize*sizeof(int));
    suffix[nSubSrcSize - 1] = nSubSrcSize;
    for ( i = nSubSrcSize - 2; i >= 0; i--)
    {
        
        int k = i;
        while( k >= 0 && pSubSrc[k] == pSubSrc[nSubSrcSize-1-i+k] )
        {
            k--;
        }
        suffix[i] = i - k; 
    }
    
    int* gsSkip = (int*)malloc(nSubSrcSize*sizeof(int));
    for (i = 0; i < nSubSrcSize; i++) 
    {
        gsSkip[i] = nSubSrcSize;
    }  
    for ( i = nSubSrcSize - 1; i >= 0; i--) 
    {
        if (suffix[i] == i + 1)          
        {
			int j;
            for (j = 0; j < nSubSrcSize - 1 - i; ++j)             
            {
                if (gsSkip[j] == nSubSrcSize)                
                    gsSkip[j] = nSubSrcSize - 1 - i;  
            }
        }
    }
    for ( i = 0; i <= nSubSrcSize - 2; ++i)       
    {
        gsSkip[nSubSrcSize - 1 - suffix[i]] = nSubSrcSize - 1 - i; 
    }

    int nPos = 0;
    while (nPos <= nSrcSize - nSubSrcSize) 
    {    
        int j = nSubSrcSize - 1;
        while(j >= 0 && pSubSrc[j] == pSrc[j + nPos])
        {
            j--;
        }
        if (j < 0)       
            break;  
        else      
        {
            nPos += max(gsSkip[j], bcSkip[pSrc[j + nPos]]-(nSubSrcSize - 1 - j) );
        }
    }
    free(gsSkip);
    return (nPos > nSrcSize - nSubSrcSize)? -1 : nPos;        
}


int main()
{
	char *s1 = "abcabcabcd";
	char *s2 = "abcd";
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	int offset = BM_match(s1,l1,s2,l2);
	printf("offset is %d\n",offset);
	return 0;
}
