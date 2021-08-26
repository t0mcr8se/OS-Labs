#include<stdio.h>
#include<string.h>

int main(){

  char s[256];
  fgets(s, 256, stdin);

  for(int i=strlen(s) ; i>=0 ; i--)
    printf("%c", s[i]);
  printf("\n");
  
  return 0;
}
