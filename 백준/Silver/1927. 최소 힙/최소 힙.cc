#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100000

typedef struct {
int key;
}element;

typedef struct {
element heap[MAX_ELEMENT];
int heap_size;
}HeapType;

HeapType* create(){
  HeapType* h = (HeapType*)malloc(sizeof(HeapType));
  h->heap_size = 0;

  return h;
}

void insert_min_heap(HeapType *h, element item) {
  int i;
  i = ++(h->heap_size);
  while ((i != 1) && (item.key < h->heap[i/2].key)) {
    h->heap[i] = h->heap[i/2];
    i/= 2;
  }
  h->heap[i] = item;
}

int delete_min_heap(HeapType* h) {

    if (h->heap_size == 0) {
        return 0;  // 힙이 비어 있는 경우 0을 반환
    }

  int parent, child;
  element item, temp;

  item = h->heap[1];
  temp = h->heap[(h->heap_size)--];
  parent = 1;
  child = 2;
  while (child <= h->heap_size) {
    if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
      child++;
    if (temp.key <= h->heap[child].key) break;
    h->heap[parent] = h->heap[child];
    parent = child;
    child *= 2;
  }
  h->heap[parent] = temp;
  return item.key;
}


int main(void) {
    HeapType* h = create();
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++){
        int x;
        scanf("%d", &x);
        if(x == 0){
            printf("%d\n", delete_min_heap(h));
        }
        else{
            element e1 = {x};
            insert_min_heap(h, e1);
        }
    }

  return 0;
}