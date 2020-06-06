/*************************************************************************
	> File Name: dir.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年05月30日 星期六 23时49分10秒
 ************************************************************************/

#include"../public.h"
#include<dirent.h>
int main( int argc , char* argv[] )
{
    DIR* dir;  
    struct dirent* dirent;
	dir = opendir(argv[1]); 
    if( dir == NULL)
	{
	  perror(" open dir error");
	  exit(1);
	}

   /* 遍历输出文件 */
   while( (dirent = readdir(dir)))
   {
      printf(" %s ",dirent->d_name);
   }

   closedir( dir );
   return 0;
}










