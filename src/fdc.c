#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include"browfunc.h"
#define EXIT(s) {fprintf(stderr,"%s",s);exit(0);}


int main(int argc, char* argv[])
{
	char buff[BUFSIZ];
	FILE *fp;
	int spislength = 0;
	char* resr;
	if((fp = popen("ls */ -d", "r")) == NULL) EXIT("Error with pipes openning"); 


// calculate memory for directories array of names
	while(!feof(fp))
	{
//	printf("done o \n");
	resr=fgets(buff, BUFSIZ, fp);
		if(resr!=NULL)spislength++;
	//	puts(buff);
	}
	char abuff[spislength][40];
//	rewind(fp);
	
    pclose(fp);
	if((fp = popen("ls */ -d", "r")) == NULL) EXIT("Error with pipes openning"); 
	for(int i=0;i<spislength;i++)
	{
		resr=fgets(abuff[i], 40, fp);
	//	puts(abuff[i]);
	}
   abuff[4][0]= '\n';
   abuff[4][1]= '\0';
//
	abuff[3][3]>>2;	
	for(int i=0;i<spislength;++i)
	{
		printf("abuff[%d]=%s",i,abuff[i] );
	}
  fReadDirStream('a');
//get directories names
//

//     call function do_ls (with argument or without)
//


// build array
// generate script
// pass control to script
    pclose(fp);
	printf(" spislength : %d \n", spislength);
	printf("all done \n");
	return 0;
}
