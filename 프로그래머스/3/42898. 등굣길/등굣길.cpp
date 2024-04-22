#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
long long map[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            map[j][i] = -1;
        }
    }
    
    for(auto a : puddles){
        map[a[0]][a[1]] = 0;
    }
    map[1][1] = 1;
    int tmp = map[1][2];
    if(tmp == -1){
        tmp = 1;
    }
    
    for(int i = 2; i <= n; i++){
        if(map[1][i] == -1){
             map[1][i] = map[1][i-1];
        }
    }
    
    tmp = map[2][1];
    if(tmp == -1){
        tmp = 1;
    }
    for(int i = 2; i<=m; i++){
        if(map[i][1] == -1){
            map[i][1] = map[i-1][1];
        }
    }

    
    if(map[2][1] == 0 && map[1][2] == 0){
        return 0;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            if(map[j][i] == -1){
                map[j][i] = (map[j][i-1] + map[j-1][i]) % 1000000007;
            }
        }
    }

    return map[m][n]% 1000000007;
}