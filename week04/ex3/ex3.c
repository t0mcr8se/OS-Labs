#include<stdio.h>

int main(){
  char cmd[256];
  while(1){
    printf("$ ");
    scanf("%s", cmd);
    system(cmd);
  }
}
