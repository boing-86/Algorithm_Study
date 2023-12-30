#include <stdio.h>

int main(void) {

  int i;
  int N;

  scanf("%d", &N);

  for (i = 1; i <= 9; i++) {
    printf("%d * %d = %d\n", N, i, i * N);
  }
  
  return 0;
}