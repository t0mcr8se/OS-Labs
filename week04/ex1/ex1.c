#include<stdio.h>
#include<sys/types.h>
int main(){
  pid_t pid = fork();
  if(pid)
    printf("Hello from parent [%d - %d]\n", pid, getpid());
  else
    printf("Hello from child [%d - %d]\n", pid, getpid());
}
