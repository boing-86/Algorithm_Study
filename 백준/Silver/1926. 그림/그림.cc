#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 1. 아이디어 : 2중포문을 돌면서 값이 1인 것 && 방문x -> bfs
// 그림개수 +1, 최대넓이
// 2. 시간 복잡도 : O(v+e)
// 3. 자료구조 : 지도 int[][], visited[][], queue

int map[501][501] = {{0,}, };
bool visited[501][501] = {{false,}, };
queue<pair<int, int>> q;
int n, m;
vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int bfs(int x, int y){
  int area = 1;
  q.push({x, y});
  while(!q.empty()){
    int nx = q.front().first;
    int ny = q.front().second;
    q.pop();

    for(int i = 0; i<4; i++){
      int next_x = nx + directions[i].first;
      int next_y = ny + directions[i].second;
      if(next_x <= n && next_x > 0 && next_y <= m && next_y > 0)
      if(!visited[next_x][next_y] && map[next_x][next_y]){
        area++;
        visited[next_x][next_y] = true;
        q.push({next_x, next_y});
      }
    }
  }
  return area;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin>>n>>m;

  for(int i = 1; i<= n; i++){
    for (int j = 1; j <= m; j++){
      cin>>map[i][j];
    }
  }

  int count = 0;
  int max_paint_size = 0;
  
  for(int i = 1; i<= n; i++){
    for (int j = 1; j <= m; j++){
      if(!visited[i][j] && map[i][j] == 1){
        visited[i][j] = true;
        count++;
        max_paint_size = max(max_paint_size, bfs(i, j));
      }
    }
  }

  cout<<count<<"\n"<<max_paint_size;

}