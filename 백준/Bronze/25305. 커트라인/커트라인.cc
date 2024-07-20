#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort (int list[], int n) {
  for (int j = 0; j < n; j++) {
    for (int i = j + 1; i < n; i++) {
      if (list[j] < list[i]) {
        int temp = list[j];
        list[j] = list[i];
        list[i] = temp;
      }
    }
  }
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  int list[n];
  for (int x = 0; x < n; x++){
    scanf("%d", &list[x]);
  }
  
  sort(list, n);
  // printf("\n");
  // for (int x = 0; x < n; x++){
  //   printf("%d ", list[x]);
  // }

  printf("%d", list[k - 1]);
}