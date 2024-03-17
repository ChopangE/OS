#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  char s[3];
  s[0] = '-';
  s[1] = 's';
  if(argc != 4){
    printf(2, "Usage: ln old new\n");
    exit();
  }
  if(!strcmp(s, argv[1])){
    if(symlink(argv[2],argv[3]) < 0)
      printf(2, "link %s %s: failed\n", argv[2], argv[3]);
  }
  else{
    if(link(argv[2], argv[3]) < 0)
      printf(2, "link %s %s: failed\n", argv[2], argv[3]);
  }
  
  exit();
}
