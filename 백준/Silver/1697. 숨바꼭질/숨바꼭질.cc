#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, k;
bool visited[100001];

void bfs(int x){
  queue <pair<int, int>> q;

  q.push({x, 0});

  while(!q.empty()){
    int next = q.front().first;
    int distance = q.front().second;

    q.pop();

    if(next == k){
      cout<<distance;
      break;
    }

    if(next+1 >= 0 && next+1 < 100001){
      if(!visited[next+1]){
        visited[next+1] = true;
        q.push({next+1, distance+1});
      }
    }
    
    if(next-1 >= 0 && next-1 < 100001){
      if(!visited[next-1]){
        visited[next-1] = true;
        q.push({next-1, distance+1});
      }
    }

    if(next*2 >= 0 && next*2 < 100001){
      if(!visited[next*2]){
        visited[next*2] = true;
        q.push({next*2, distance+1});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>k;

  visited[n] = true;

  bfs(n);

  return 0;
}