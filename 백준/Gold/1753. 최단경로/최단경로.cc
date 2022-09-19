#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 87654321;
vector<pair<int, int>> arr[30001];
priority_queue<pair<int, int>> pq;
int result[20001];

void dijkstra(int k){
    pq.push({0, k});

    while(!pq.empty()){
        int dist = -pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(result[current] < dist) continue;

        for(int i = 0; i<arr[current].size(); i++){
            int n_dist = arr[current][i].first + dist;
            int next = arr[current][i].second;
            
            if(n_dist < result[next]){
                result[next] = n_dist;
                pq.push({-n_dist, next});
            }
        }
    }
}

int main(){
    int v, e, k;

    cin>>v>>e>>k;

    for(int i = 0; i<=v; i++){
        result[i] = INF;
    }

    for(int i = 0; i<e; i++){
        int start, dest, cost;
        cin>>start>>dest>>cost;
        arr[start].push_back({cost, dest});
    }

    result[k] = 0;
    dijkstra(k);

    for(int i = 1; i<=v; i++){
        if(result[i] == INF){
            cout<<"INF\n";
        }
        else{
            cout<<result[i]<<"\n";
        }
    }
    
    return 0;
}