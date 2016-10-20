#include<stdio.h>

int main()
{
    int a[]={4,1,65,21,87,104,33,5};
    int k=sizeof(a)/sizeof(a[0]);
    int j;
	int tmp,t;
     for(int i=1;i<k;i++)//循环从第2个元素开始
    {
        j =i -1;
        while(a[j]>a[i]&&j>=0)
			j--;
        
        
        	tmp =a[i];
			for(t=i-1;t>j;t--)
			{
				a[t+1] =a[t];
			}
			a[t+1] =tmp;
        
        
        
		
    }
    for(int f=0;f<k;f++)
    {
        printf("%d\t",a[f]);
    }
    return 0;
}
