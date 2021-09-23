#include<stdio.h>

void swap(int *a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void bubble_sort(int a[], int n) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - i - 1; j++)
      if (a[j] > a[j + 1]) 
        swap(a + j, a + j + 1);
}

void print_arr(int a[], int n){
  for(int i=0 ; i<n ; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main(){
  const int N = 7;
  int a[7] = {
    2,6,5,4,9,1,10
  };

  printf("Before sort:\n");
  print_arr(a, N);

  bubble_sort(a, N);

  printf("Result: \n");  
  print_arr(a, N);
}
