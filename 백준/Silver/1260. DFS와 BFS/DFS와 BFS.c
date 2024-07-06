#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1001
#define TRUE 1
#define FALSE 0

int visited[MAX_VERTICES];

typedef struct GraphType {
    int n; // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

typedef struct QueueType {
    int queue[MAX_VERTICES];
    int front, rear;
} QueueType;

// 큐 초기화
void queue_init(QueueType* q) {
    q->front = q->rear = 0;
}

// 큐 공백 상태 검사
int is_empty(QueueType* q) {
    return (q->front == q->rear);
}

// 큐 포화 상태 검사
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_VERTICES == q->front);
}

// 큐 삽입
void enqueue(QueueType* q, int item) {
    if (is_full(q)) {
        fprintf(stderr, "큐 포화 상태\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_VERTICES;
    q->queue[q->rear] = item;
}

// 큐 삭제
int dequeue(QueueType* q) {
    if (is_empty(q)) {
        fprintf(stderr, "큐 공백 상태\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_VERTICES;
    return q->queue[q->front];
}

// 그래프 초기화
void init(GraphType* g, int n) {
    int r, c;
    g->n = n;
    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end) {
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g) {
  int i, j;
  for (i = 0; i < g->n; i++) {
    for (j = 0; j < g->n; j++) {
      printf("%2d ", g->adj_mat[i][j]);
    }
    printf("\n");
  }
}

void dfs_mat (GraphType* g, int v) {
  int w;
  visited[v] = TRUE;
  printf("%d ", v);
  for (w = 1; w <= g->n; w++) {
    if (g->adj_mat[v][w] && !visited[w])
      dfs_mat(g, w);
  }
}

// 인접 행렬로 표현된 그래프에 대한 너비 우선 탐색
void bfs_mat(GraphType* g, int v) {
    int w;
  QueueType q;
  queue_init(&q); // 큐 초기화
  visited[v] = TRUE; // 정점 v 방문 표시
  printf("%d ", v);
  enqueue(&q, v); // 시작 정점을 큐에 저장
  
  while (!is_empty(&q)) {
    v = dequeue(&q); // 큐에 정점 추출
    for (w = 1; w <= g->n; w++) { // 인접 정점 탐색
      if (g->adj_mat[v][w] && !visited[w]) {
        visited[w] = TRUE; // 방문 표시
        printf("%d ", w);
        enqueue(&q, w); // 방문한 정점을 큐에 저장
      }
    }
  }
}

int main() {
  int N, M, V;
  scanf("%d %d %d", &N, &M, &V);
  
  GraphType* g = (GraphType*)malloc(sizeof(GraphType));;
  init(g, N);

  for (int i = 0; i < M; i++) {
    int temp_a, temp_b;
    scanf("%d %d", &temp_a, &temp_b);
    insert_edge(g, temp_a, temp_b);
  }

  for (int i = 0; i < MAX_VERTICES; i++) {
      visited[i] = FALSE;
  }
  dfs_mat(g, V);
  printf("\n");

  for (int i = 0; i < MAX_VERTICES; i++) {
      visited[i] = FALSE;
  }
  
  bfs_mat(g, V);

  free(g);

  return 0;
}