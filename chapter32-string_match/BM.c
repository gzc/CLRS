int BMMatch(byte* pSrc, int nSrcSize, byte* pSubSrc, int nSubSrcSize)
{

    //1.坏字符数组
    int bcSkip[256];
    for( int i = 0; i < 256; i++)  
    {
        bcSkip[i] = nSubSrcSize;
    }
    for (int i = 0; i < nSubSrcSize - 1; i++)
    {
        bcSkip[pSubSrc[i]] = nSubSrcSize - i - 1;
    }

    //2.好后缀数组
    int* suffix = new int [nSubSrcSize];
    suffix[nSubSrcSize - 1] = nSubSrcSize;
    for (int i = nSubSrcSize - 2; i >= 0; i--)
    {
        
        int k = i;
        while( k >= 0 && pSubSrc[k] == pSubSrc[nSubSrcSize-1-i+k] )
        {
            k--;
        }
        suffix[i] = i - k; 
    }
    
    int* gsSkip = new int [nSubSrcSize];
    for (int i = 0; i < nSubSrcSize; i++) 
    {
        gsSkip[i] = nSubSrcSize;
    }  
    for (int i = nSubSrcSize - 1; i >= 0; i--) 
    {
        if (suffix[i] == i + 1)          
        {
            for (int j = 0; j < nSubSrcSize - 1 - i; ++j)             
            {
                if (gsSkip[j] == nSubSrcSize)                
                    gsSkip[j] = nSubSrcSize - 1 - i;  
            }
        }
    }
    for (int i = 0; i <= nSubSrcSize - 2; ++i)       
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
    delete[] gsSkip;
    return (nPos > nSrcSize - nSubSrcSize)? -1 : nPos;        
}