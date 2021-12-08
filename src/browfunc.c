#include"browfunc.h"
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
//#include<dirent.h>

void fGenMenu(char(*pabuf)[40], int nuc )
{
	struct _IO_FILE* res;
	FILE *fptr;
	char fststr[] = "#! /bin/bash \n";
	char * wdstr;
	
	wdstr = (char*)malloc(100*sizeof(char));
	getcwd(wdstr,100);
    printf("Working directory is %s.",wdstr);
	res  =(fptr = fopen("brs","w"));
	if(res==NULL)
	{
		printf("Error opening script file");
		exit(1);
	} else
	{
		fprintf(fptr,"%s",fststr);
		fprintf(fptr,"mway=( drop" );
		for(int i=0;i<nuc;i++)
		{
		if(pabuf[i][0]!=10)fprintf(fptr," %s", pabuf[i]);
		}
		fprintf(fptr," ../ ) \n");
   		fprintf(fptr,"select mw in ${mway[@]} \n");
		fprintf(fptr,"do \n");
		fprintf(fptr," case $mw in \n");
		fprintf(fptr,"drop) cd ../ \n"); 
		fprintf(fptr," cd %s/;; \n",wdstr); 

		for(int i = 0; i<nuc;i++)
		{
		   if(pabuf[i][0]!=10)	fprintf(fptr,"%s) alias mycd='cd %s';; \n",pabuf[i],pabuf[i]); 
		}
		fprintf(fptr,"../) alias mycd='cd ../';; \n"); 
		fprintf(fptr,"*) break;; \n");
		fprintf(fptr,"esac \n");
		fprintf(fptr,"break \n");
		fprintf(fptr,"done \n");
		fprintf(fptr,"mycd \n");
	}


    if(res!=NULL)fclose(fptr);

}
