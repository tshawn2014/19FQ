#include <stdio.h>
#include <stdlib.h>

int require_number(int a, int b, int c){
	return 200045*a*b*c;
}
void print_function(int random_index) {
  int *arr = (int *)malloc(5*sizeof(int));
  arr[0] = 1;
  arr[1] = 4;
  printf("%d", arr[random_index]);
}
int some_random_computation() {
  int a, b, c;
  printf("Enter 3 numbers:");
  scanf("%d %d %d", &a, &b, &c);

  int gen = require_number(a, b, c);

  print_function(gen);
}
int main() {
  some_random_computation();
}
