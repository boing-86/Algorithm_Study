#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

bool visited[1001] = {false, };
vector <int> graph[1001];
queue <int> q;
int n, m, v;

void dfs(int x){
    visited[x] = true;
    cout<<x<<" ";
    for(int i = 0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if(!visited[y]){
            dfs(y);
        }
    }
}

void bfs(int x){
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        int y = q.front();
        cout<<y<<" ";
        q.pop();

        for(int i = 0; i<graph[y].size(); i++){
            int next = graph[y][i];

            if(!visited[next]){
                q.push(next);
                visited[next] = true;
            }
        }
    }

}

int main(){
    cin>>n>>m>>v;
    int from, to;

    for(int i = 0; i<m; i++){
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    for(int i = 1; i<=n;i++){
        sort(graph[i].begin(), graph[i].end());
    }



    dfs(v);
    cout<<"\n";
    
    memset(visited, false, sizeof(visited));
    bfs(v);

    return 0;
}