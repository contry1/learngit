// popen2.c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
int main(int argc, char const *argv[])
{
	FILE *fp =NULL;
	char buf[max];
	int ret,nread;
	memset(buf,'\0',sizeof(buf));
	fp = popen("uname -a","r");
	if (fp==NULL)
	{
		/* code */
		perror("popen");
	}
	nread = fread(buf,sizeof(char),max-1,fp);
	if (nread>0)
	{
		printf("out put:%s\n",buf );
		/* code */
	}
	ret = pclose(fp);
	if (ret!=0)
	{
		perror("fclose");
		/* code */
	}
	return 0;
}