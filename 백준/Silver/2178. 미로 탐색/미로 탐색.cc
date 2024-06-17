#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <memory.h>
using namespace std;

bool visited[110][110] = {false, };
int map[110][110] = {0, };
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int answer = 987654321;
struct point{
    int x;
    int y;
};
queue<pair<point, int>> q; //point, count;

void bfs(){

    while(!q.empty()){
        int x = q.front().first.x;
        int y = q.front().first.y;
        int count = q.front().second;
        q.pop();

        if(x == n && y == m){
            answer = min(answer, count);
        }

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx > 0 && nx <= n && ny > 0 && ny <= m && !visited[nx][ny] && map[nx][ny]){
                visited[nx][ny] = true;
                q.push({{nx, ny}, count+1});
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        string tmp;
        cin>>tmp;

        for(int j = 1; j<=m; j++){
            map[i][j] = tmp[j-1] - '0';
        }
    }

    q.push({{1, 1}, 1});
    visited[1][1] = true;
    bfs();
    cout<<answer;

}