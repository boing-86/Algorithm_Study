#include <iostream>
#include <vector>
using namespace std;

int INF = 987654321;
int n, m;
long long dist[501];
vector <pair<int, int>> map[501];
bool cycle = false;

int bf(int s){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int k = 0; k<map[j].size(); k++){
            int to = map[j][k].first;
            int cost = map[j][k].second;

            if(dist[j] != INF && dist[to] > dist[j] + cost){
                dist[to] = dist[j] + cost;
                if(i == n){
                    cycle = true;
                }

            }
            }
        }
    }
    return 0;
}

int main(){

    cin>>n>>m;

    for(int i = 0; i<=n; i++){
        dist[i] = INF;
    }

    for(int i = 0; i<m; i++){
        int start, dest, cost;
        cin>>start>>dest>>cost;
        map[start].push_back({dest, cost});
    }
    
    dist[1] = 0;

    bf(1);

    if(cycle){
        cout<<"-1"<<"\n";
        return 0;
    }

    for(int i = 2; i<=n; i++){
        if(dist[i] == INF){
            cout<<"-1\n";
        }
        else{
            cout<<dist[i]<<"\n";
        }
    }
}