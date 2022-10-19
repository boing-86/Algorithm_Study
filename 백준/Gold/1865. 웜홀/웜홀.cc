#include <iostream>
#include <vector>
using namespace std;

int INF = 987654321;
int n, m, w;
int dist[501];


void bf(const vector <pair<int, int>>* map){
    //dist[1] = 0;
    bool updated = false;
    for(int iter = 0; iter<n; iter++){
        //cout<<"-----------"<<iter<<" iter----------"<<endl;
        updated = false;
        for(int i = 1; i<=n; i++){
            for(int j = 0; j < map[i].size(); j++){
                //cout<<map[i][j].first<<" "<<map[i][j].second<<endl;
                int to = map[i][j].first;
                int cost = map[i][j].second;
                if(dist[to] > dist[i] + cost){
                    dist[to] = dist[i] + cost;
                    //cout<<i<<" "<<to<<" "<<dist[i] + cost<<endl;
                    updated = true;
                }
            }
        }
        if(!updated){
                cout<<"NO"<<endl;
                break;
        }
    }

    if(updated){
        cout<<"YES"<<endl;
    }
    // for(int i = 1; i<=n; i++){
    //     for(int j = 0; j<map[i].size(); j++){
    //         int to = map[i][j].first;
    //         int cost = map[i][j].second;
    //         if(dist[to] > dist[i] + cost){ //dist[i] != INF && 
    //             cout<<"YES"<<endl;
    //             return ;
    //         }
    //     }
    // }
    // cout<<"NO"<<endl;
    // return ;

}

int main(){

    int tc;
    cin>>tc;

    while(tc--){
        cin>>n>>m>>w;

        for(int i = 0; i<=n; i++){
            dist[i] = INF;
        }
        vector <pair<int, int>> map[501];

        int start, dest, cost;
        for(int i = 0; i<m; i++){
            cin>>start>>dest>>cost;
            map[start].push_back({dest, cost});
            map[dest].push_back({start, cost});
        }

        for(int i = 0; i<w; i++){
            cin>>start>>dest>>cost;
            map[start].push_back({dest, -cost});
        }

        bf(map);
    }
}