/*************************************************************************
	> File Name: lsR.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年05月31日 星期日 09时23分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
int read_dir( const char* name)
{
    DIR* dir;
	struct dirent* ent;
	dir = opendir(name);
	char wPath[255];
    mesmet(wPath,0x00,sizeof(wPath));
	if( dir == NULL)
	{
	   perror("open dir is error"); 
	}
	while(( ent=(readdir( dir ))!= NULL )
	{
	    if( strcmp( ent->d_name,"."  ) == 0|| strcmp( ent->d_name,".."))
		{
		   continue;
		}
        if( strlen(name)+strlen(ent->d_name) > sizeof(wPath))
		{
		   perror("path is to long");
		   return;
		}else{
		 /*继续判断文件,组装目录 */
		  sprintf(wPath,"%s/%s",name,ent->d_name);
		  isFile( wPath );
		}
	    
	}
	closedir(dir);  
}

void isFile( const char* name )
{
   struct stat file;
   int ret = 0;
   memset(&file,0x00,sizeof(file));
   ret = stat(name,&file);
   if( ret == -1 )
   {
      perror("stat error" );
	  return;
   }
   /* 输出文件,打开进入目录  */
   if( S_ISDIR(file.st_mode))
   {
      /*是目录 */
      readdir(name);  
   }   
   printf("%s\t%ld\n",name,file.st_size);
   return;
}

int main( int argc , char* argv[])
{
    if( argc == 1  )
	{
	  isFile(".");
	}else{
	  isFile(argv[1]);
	}
    return 0;
}
