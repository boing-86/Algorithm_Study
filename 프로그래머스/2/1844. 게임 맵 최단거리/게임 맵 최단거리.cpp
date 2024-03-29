#include <iostream>
#include <algorithm>
#include<vector>
#include <queue>
using namespace std;

bool visited[101][101];
int step[101][101];
int direct_x[] = {0, 1, 0, -1};
int direct_y[]= {-1, 0, 1, 0};
queue<pair<int, int>> q;


int bfs(vector<vector<int>> map){
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i<4; i++){
            int n_x = x + direct_x[i];
            int n_y = y + direct_y[i];
            
            if(n_x > 0 && n_x <= map.size() && n_y > 0 && n_y <= map[0].size()){
                
                if(visited[n_x][n_y] == false && map[n_x-1][n_y-1] == 1){
                    step[n_x][n_y] = step[x][y] + 1;
                    if(n_x == map.size() && n_y == map[0].size()){
                        return step[n_x][n_y]++;
                    }

                    visited[n_x][n_y] = true;
                    q.push({n_x, n_y});
                }
            }
        }
    }
    return -1;
    
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    q.push({1, 1});
    step[1][1] = 1;
    visited[1][1] = true;
    answer = bfs(maps);
    
    return answer;
}