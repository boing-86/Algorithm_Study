#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

bool visited[200001];
int believe_time[200001]; //time;
vector<int> graph[200001];
vector<int> rumor;
queue<pair<int, int>> q; //node, time
int n, m;

void bfs(){

    while(!q.empty()){
        int node = q.front().first;
        int time = q.front().second;
        q.pop();

        if(believe_time[node] >= 0){
            believe_time[node] = min(believe_time[node], time);
        }
        else{
            believe_time[node] = time;
        }

        for(int i = 0; i<graph[node].size(); i++){
            int next = graph[node][i];

            if(believe_time[next] < 0){
                int rumor_count = 0;
                for(int j = 0; j<graph[next].size(); j++){
                    if(believe_time[graph[next][j]] >= 0){
                        rumor_count++;
                    }
                }

                if(rumor_count*2 >= graph[next].size()){
                    q.push({next, time+1});
                }
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;

    for(int i = 1; i<=n; i++){
        int tmp;
        cin>>tmp;
        while(tmp != 0){
            graph[i].push_back(tmp);
            cin>>tmp;
        }
    }

    memset(believe_time, -1, sizeof(int) * 200001);
    memset(visited, false, sizeof(bool) * 200001);

    cin>>m;
    for(int i = 0; i<m; i++){
        int tmp;
        cin>>tmp;
        rumor.push_back(tmp);
        believe_time[tmp] = 0;
        q.push({tmp, 0});
    }

    bfs();

    for(int i = 1; i<=n; i++){
        cout<<believe_time[i]<<" ";
    }

}