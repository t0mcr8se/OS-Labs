#include<stdio.h>

void swap(int *x, int *y){
  *x ^= *y;
  *y ^= *x;
  *x ^= *y;
}

int main(){
  int a,b;
  scanf("%d%d", &a, &b);

  swap(&a, &b);
  printf("a = %d, b = %d\n", a, b);

  return 0;
}
