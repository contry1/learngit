#include<stdio.h>

int main()
{
    int a[]={98,76,109,34,67,190,80,12,14,89,1};
    int k=sizeof(a)/sizeof(a[0]);
    int j;
	int tmp,t;
     for(int i=1;i<k;i++)//循环从第2个元素开始
    {
        j =i -1;
        while(a[j]>a[i]&&j>=0)
        {
        
        	tmp =a[i];
        	a[i] =a[j];
        	a[j] =tmp;
        	j--;
        	i--;
        
        
        
        }
		
    }
    for(int f=0;f<k;f++)
    {
        printf("%d\t",a[f]);
    }
    return 0;
}