#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include"browfunc.h"
#include<string.h>
#include<sys/stat.h>
#define EXIT(s) {fprintf(stderr,"%s",s);exit(0);}
#define WBUFF 40


int main(int argc, char* argv[])
{
	char buff[BUFSIZ];
	char cbuff[WBUFF];
	FILE *fp;
	char *args[] = {"source","brs",NULL};	
	long slen;
	int spislength = 0;
	char* resr;
	if((fp = popen("ls */ -d", "r")) == NULL) EXIT("Error with pipes openning"); 


// calculate memory for directories array of names
	while(!feof(fp))
	{
//	printf("done o \n");
	resr=fgets(cbuff,WBUFF, fp);
		if(resr!=NULL)spislength++;
	//	puts(buff);
	}
	char abuff[spislength][WBUFF];
//	rewind(fp);
	
    pclose(fp);
	if((fp = popen("ls */ -d", "r")) == NULL) EXIT("Error with pipes openning"); 
	for(int i=0;i<spislength;i++)
	{
		resr=fgets(abuff[i],WBUFF, fp);
		slen  = strlen(abuff[i]);
		abuff[i][slen-1] = ' ';
	}
   abuff[4][0]= '\n';
   abuff[4][1]= '\0';
//
   fGenMenu(abuff,spislength);

    pclose(fp);
	chmod("brs",S_IRWXU);
	
	printf("all done \n");
	if(!execvp(args[0],args)){
	printf("args[0]=%s \n",args[0]);
	system("dbv");
	}
	return 0;
}
