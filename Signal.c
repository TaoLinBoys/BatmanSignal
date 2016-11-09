#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>


static void sighandler(int signo){
  if(signo == SIGINT){
    printf("program exited due to SIGINT\n");
    exit(0);
  }
  if(signo == SIGUSR1) printf("Parent PID: %d, " , getppid());
}

void main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
}
