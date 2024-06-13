#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> map;
vector<int> answer(2, 0);

void dfs(int x, int y, int s){
    int sum = 0;
    for(int i = x; i<x+s; i++){
        for(int j = y; j<y+s; j++){
            sum += map[i][j];
        }
    }
    
    if(sum == 0){
        answer[0]++;
        return ;
    }
    else if(sum == s*s){
        answer[1]++;
        return ;
    }
    
    dfs(x, y, s/2);
    dfs(x, y+s/2, s/2);
    dfs(x+s/2, y, s/2);
    dfs(x+s/2, y+s/2, s/2);
    
}

vector<int> solution(vector<vector<int>> arr) {
    map = arr;
    dfs(0, 0, arr.size());
    
    return answer;
}