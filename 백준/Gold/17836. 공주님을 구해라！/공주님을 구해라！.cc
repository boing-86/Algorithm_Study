#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <memory.h>
#include <cmath>
#define MAX 987654321
using namespace std;
int n, m, t;
int answer = MAX;
int map[110][110] = {0, };
bool visited[110][110] = {false, };
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

struct point{
    int x;
    int y;
    int distance;
};

queue <point> q;

void bfs(){
    visited[1][1] = true;
    q.push({1, 1, 0});

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dist = q.front().distance;
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx == n && ny == m){
                answer = min(answer, dist + 1);
                return ;
            }

            if(nx > 0 && ny > 0 && nx <= n && ny <= m && !visited[nx][ny]){
                if(map[nx][ny] == 1){
                    continue;
                }

                else if(map[nx][ny] == 2){
                    int tmp = dist + 1 + abs(n-nx) + abs(m-ny);
                    answer = min(answer, tmp);
                }

                visited[nx][ny] = true;
                q.push({nx, ny, dist + 1});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m>>t;
    memset(visited, false, sizeof(bool));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin>>map[i][j];
        }
    }
    bfs();
    
    if(answer == MAX || answer > t){
        cout<<"Fail";
    } else{
        cout<<answer;
    }
}