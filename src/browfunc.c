#include"browfunc.h"
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<dirent.h>

void fReadDirStream(char req)
{


  DIR* pDir;
  struct dirent *curDir;

  pDir = opendir(".");
  curDir = readdir(pDir);
  printf("dirname : %s \n",curDir->d_name);
  closedir(pDir);
  printf("accept %c  \n", req);

}
