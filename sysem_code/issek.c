#include "../public.h"

int main(void)
{
   int fd;
   char b;
   char* buffer;
   int n=0;
   buffer = "sfjdjfs123";
   
   fd = open("./test.txt",O_RDWR|O_CREAT,0755);
   if( fd < 0 )
   {
      perror("open test.txt is error");
	  return 0;
   }
  
  write( fd , buffer ,strlen(buffer));/* 文件的读写操作都是在同一个位置 */
  /* 需要在此处lseeck让文件位置到文件开头 */
  lseek( fd,0,SEEK_SET );
  while((n = read( fd,&b,1 )) )
  {
    /* n表示读入的数据  */
	if( n<0  )
	{ 
	  printf(" read error ");
	  exit(1);
	}
	write( STDOUT_FILENO ,&b , n ); 

  }

  close(fd);
  return ;

}




