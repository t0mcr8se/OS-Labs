#include<sys/types.h>
#include<stdio.h>

int main(){
  int n = 5;
  // change n = 100 for a nice forkbomb))
  for(int i=0 ; i<n ; i++){
    fork();
    sleep(5);
  }
}
