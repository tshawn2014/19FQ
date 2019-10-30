// Compilation instructions: gcc -g -o lab_hw lab_hw.c
// Running the binary: ./lab_hw
// Analyzing the core with gdb: gdb -c core ./lab_hw
#include <stdio.h>
#include <stdlib.h>

// Returns a magical array!
#pragma GCC diagnostic ignored "-Wreturn-local-addr"
char* get_magic_array() {
  char A[] = {'H', 'e', 'l', 'l', 'o', '\0'};
  return A;
}

// Computes a magical value!
int compute_hash(char *array) {
  int hash_val = 0;
  int i = 0;
  while (array[i] != '\0') {
    hash_val += (int)array[i];
    i++;
  }
  return hash_val;
}

// MAAAAAAIN!
int main() {
  char *ADDR = get_magic_array();
  compute_hash(ADDR);
  return 0;
}
