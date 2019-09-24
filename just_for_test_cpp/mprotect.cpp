//linux系统函数mprotect的demo

#include <unistd.h>
#include <sys/mman.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>

int main()
{
  int pagesize = sysconf(_SC_PAGE_SIZE);

  char * a =  reinterpret_cast<char*>(memalign(pagesize, pagesize*2)) ;
  
  std::cout << mprotect(a,pagesize,PROT_READ );
  
  a[4] = 1; // segment fault
  return 0;
}
