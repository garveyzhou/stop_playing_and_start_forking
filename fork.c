#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){
  srand(time(NULL));
  printf("Time to start forking!\n");
  int f = fork();
  int naptime = rand()%16 + 5;
  int naptime2 = rand()%16 + 5;
  if(!f){
	printf("I am child 1. My PID is %d \n",getpid());
       	sleep(naptime);	
	printf("I slept for %d \n",naptime);
	return naptime;	
  }
  else{
    int a = fork();
    if(!a){
	    printf("I am child 2. My PID is %d \n",getpid());
	    sleep(naptime2);
	    printf("I slept for %d \n",naptime2);
  	    return naptime2;
    }
    else{
	    int status;
	    printf("My child with PID %d slept for %d \n",wait(&status),WEXITSTATUS(status));
	    return 0;
    }
  }
  return 0;
}


