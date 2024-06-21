#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int map[25][25];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
bool visited[25][25];
bool alphabet[30];
int r, c;
int answer = 1; 

struct point{
    int x;
    int y;
};

void dfs(int x, int y, int depth){    
    
    answer = max(depth, answer);
    
    if(depth == r*c){
        return ;
    }
    
    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx > 0 && nx<=r && ny > 0 && ny <= c && !visited[nx][ny]){
            if(!alphabet[map[nx][ny]]){
                visited[nx][ny] = true;
                alphabet[map[nx][ny]] = true;
                dfs(nx, ny, depth + 1);
                visited[nx][ny] = false;
                alphabet[map[nx][ny]] = false;
            }
        }
    }
    
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(map, 0, sizeof(int)*25*25);
    memset(visited, false, sizeof(bool) * 25 * 25);
    memset(alphabet, false, sizeof(bool) * 30);

    cin>>r>>c;

    for(int i = 1; i<=r; i++){
        string tmp;
        cin>>tmp;
        for(int j = 0; j<c; j++){
            map[i][j+1] = tmp[j] - 'A' + 1;
        }
    }
    visited[1][1] = true;
    alphabet[map[1][1]] = true;

    dfs(1, 1, 1);
    cout<<answer;
}
