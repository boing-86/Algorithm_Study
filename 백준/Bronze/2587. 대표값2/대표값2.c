#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}



void bubble_sort(int list[], int n) {
  int i, j, temp;
  for (i = n - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (list[j] > list[j + 1])
        swap(&list[j], &list[j + 1]);
    }
  }
}

int main(void) {

  int list[5];
  int sum = 0;

  for(int i = 0; i<5; i++){
    scanf("%d", &list[i]);
    sum += list[i];
  }

  printf("%d\n", sum/5);

  bubble_sort(list, 5);
  printf("%d", list[2]);
}