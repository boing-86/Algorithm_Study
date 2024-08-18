#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <memory.h>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;

    int map[1025][1025] = {0,};

    cin>>n>>m;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            cin>>map[i][j];
            map[i][j] += map[i-1][j] + map[i][j-1] - map[i-1][j-1];
        }
    }

    while(m--){
        int x1, y1, x2, y2;

        cin>>x1>>y1>>x2>>y2;

        cout<<map[x2][y2] - map[x1-1][y2] - map[x2][y1 - 1] + map[x1 - 1][y1 - 1]<<"\n";

    }
}