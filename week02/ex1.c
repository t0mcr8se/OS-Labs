#include<limits.h>
#include<float.h>
#include<stdio.h>

int main(){
  int _int = INT_MAX;
  float _float = FLT_MAX;
  double _double = DBL_MAX;

  printf("Integer = %d\n", _int);
  printf("Float = %f\n", _float);
  printf("Double =  %lf\n", _double);

  printf("Sizeof integer = %ld\n", sizeof(_int));
  printf("Sizeof float = %ld\n", sizeof(_float));
  printf("Sizeof double = %ld\n", sizeof(_double));

  return 0;
}
