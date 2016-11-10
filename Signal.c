#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>


static void sighandler(int signo){
  if(signo == SIGINT){
    umask(0);
    int fd = open("closeinfo", O_CREAT | O_WRONLY | O_APPEND, 0644);
    write(fd, "program exited due to SIGINT", 29);
    close(fd);
    
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
