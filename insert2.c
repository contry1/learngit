 #include<stdio.h>

int main()
{
    int a[]={98,76,109,34,67,190,80,12,14,89,1};
    int k=sizeof(a)/sizeof(a[0]);
    int j;
	int tmp,t;
     for(int i=1;i<k;i++)//循环从第2个元素开始
    {
        for(j=i-1;j>=0;j--)
		{
			if(a[j]<a[i])
				break;
		}
		if(j!=i-1)
		{
			tmp =a[i];
			for(t=i-1;t>j;t--)
			{
				a[t+1]=a[t];
			}
			a[t+1] =tmp;
		}
    }
    for(int f=0;f<k;f++)
    {
        printf("%d\t",a[f]);
    }
	getchar();
    return 0;
}
