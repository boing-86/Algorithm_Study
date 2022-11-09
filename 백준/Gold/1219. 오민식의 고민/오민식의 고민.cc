#include <iostream>
#include <vector>
#include <queue>
#define INF 9876543210
using namespace std;

int n, start, finish, m;
vector <pair<int, int>> map[51];
int income[51] = {0, };
vector <long long> dist(50, INF);
bool visited[51] = {false,};
queue<int> check_map;

void bf(){
    dist[start] = -income[start];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            for(int k = 0; k<map[j].size(); k++){
                int to = map[j][k].first;
                long long  cost = map[j][k].second + dist[j]- income[to];

                if(dist[j] != INF && dist[to] > cost){
                    dist[to] = cost;
                    if(i == n-1){
                        visited[j] = true;
                        check_map.push(j);
                    }
                }
            }
        }
    }
}

bool bfs(){
    while(!check_map.empty()){
        int node = check_map.front();
        check_map.pop();

        for(auto a : map[node]){
            int next = a.first;
            if(visited[next]){
                continue;
            }
            visited[next] = true;
            check_map.push(next);
        }
    }
    if(visited[finish]){
        return true;
    }
    return false;
    
}

int main(){

    cin>>n>>start>>finish>>m;

    for(int i = 0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        map[a].push_back({b,c});
    }

    for(int i = 0; i<n; i++){
        cin>>income[i];
    }

    bf();

    if(dist[finish] == INF){
        cout<<"gg"<<endl;
    }
    else{
        if(bfs()){
            cout<<"Gee"<<endl;
        }
        else{
            cout<<-dist[finish]<<endl;
        }
    }

}