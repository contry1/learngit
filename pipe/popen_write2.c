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
	int ret,nwrite;
	memset(buf,'\0',sizeof(buf));

	sprintf(buf,"once uname\n");
	fp = popen("wc -c","w");
	if (fp==NULL)
	{
		/* code */
		perror("popen");
	}
	nwrite = fwrite(buf,sizeof(char),strlen(buf),fp);
	
	ret = pclose(fp);
	if (ret!=0)
	{
		perror("fclose");
		/* code */
	}
	return 0;
}