#include "types.h"
#include "stat.h"
#include "user.h"
int
main(int argc , char *argv[]){
  int i = 0;
  char input[70];
  char num[20];
  char lim[20];
  char id[20];
  char *arv[50];
  uint n = 0;
  int stack;
  char path[50];
  printf(1,"pmanager start!\n");
  while(1){
	n = 0;
    gets(input,70);							
    if(input[0]=='l' && input[1] == 'i' && input[2] == 's'&& input[3] =='t'){
		list();	   			//syscall that list up RUNNING, RUNNALBE, SLEEPING process and it definded in proc.c 
    }  
 
    else if(input[0]=='k' && input[1] == 'i' && input[2] == 'l'&& input[3] =='l'){
		strcpy(num,input+5);		//input[4] is spacebar(blank) so copy from input + 5(input[5])
		if(kill(atoi(num))==0){
	  		printf(1,"success kill\n");
		}
		else printf(1,"failed kill\n");
    }
    
	else if(input[0]=='e' && input[1] == 'x' && input[2] == 'e'&& input[3] =='c' && input[4] =='u' && input[5]== 't'&& input[6]=='e'){
		for(i = 0; input[8+i] != 32 ;i++){
			path[i] = input[8+i];              //copy from input[8].  
			n++;								// n is length of the path.
		}
		path[i] = '\0';							
		for(i = 0; input[9+n+i]; i++){
			num[i] = input[9+n+i];				//copy form input[9+n]. atoi(num) is stack size
		}
		stack = atoi(num);
		strcpy(*arv, path);
		if(fork()==0){
			if(fork()==0){							//like 'back' in sh.c. call fork() and implement exec2
				if(exec2(path, arv, stack)== -1){	//exec2 is syscall in exec.c
					printf(1,"failed execute!\n");	
				}
			}
			exit();	
		}								//child is exited by parent do wait()
	}

    
    else if(input[0]=='m' && input[1] == 'e' && input[2] == 'm'&& input[3] =='l' && input[4] =='i' && input[5]== 'm'){
	for(i = 0; input[7+i] != 32; i++){
		id[i] = input[7+i];						//copy from input[7]. id is pid
		n++;									//n is length id. 
	}
	for(i = 0; input[8+n+i]; i++){
	  lim[i] = input[8+n+i];					//copy from input[8+n]. lim is memory limit.
	}
	if(setmemorylimit(atoi(id), atoi(lim))==0 ){	//setmemorylimit is syscall in proc.c.
	  printf(1,"success memlim!\n");
	}
	else printf(1,"failed memlim!\n");
	}

    else if(input[0]=='e' && input[1] == 'x' && input[2] == 'i'&& input[3] =='t'){
		printf(1, "pmanger exit\n");
		break;											//break while. so meet exit() line 74.
    }
    else{												//if input is wrong command.
		printf(1,"wrong command\n");
	}
  }
  exit();
}
