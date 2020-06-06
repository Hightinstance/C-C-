/*************************************************************************
	> File Name: stat.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2020年05月30日 星期六 18时23分59秒
 ************************************************************************/

#include<stdio.h>
#include"../public.h"

int main(void)
{
   int fd;
   /* 获取文件的大小  */
   int ret =0;
   struct stat buffer;
   fd = open("./test.txt",O_RDWR,0755);
   if(fd<0)
   {
     perror("open file error");
   }	   

   ret = lseek( fd ,0 , SEEK_END  );
   printf("lseek = %d\n",ret );

   memset(&buffer,0x00,sizeof(buffer));
   ret = stat("./test.txt",&buffer );
   printf(" stat_size = %d\n",buffer.st_size);	   
   close(fd);
}
