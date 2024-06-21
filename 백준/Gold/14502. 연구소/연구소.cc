#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;

int map[10][10];
int visited[10][10];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int n, m;
int answer = 0;

struct point{
    int x;
    int y;
};


void count_bfs(){
    queue<point> q;
    int test_map[10][10];

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            test_map[i][j] = map[i][j];
            if(map[i][j] == 2){
                q.push({i, j});
            }
        }
    }

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx > 0 && nx <= n && ny > 0 && ny <=m){
                if(test_map[nx][ny] == 0){
                    test_map[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
    }

    int count = 0;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(test_map[i][j] == 0){
                count++;
            }
        }
    }

    answer = max(answer, count);

}

void dfs(int count){
    if(count == 3){
        count_bfs();
        return ;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                dfs(count + 1);
                map[i][j] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(map, 0, sizeof(int)*100);
    memset(visited, false, sizeof(bool) * 100);

    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            cin>>map[i][j];
        }
    }

    dfs(0);
    cout<<answer;


}