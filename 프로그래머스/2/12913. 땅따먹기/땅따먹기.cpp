#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> land)
{
    int answer = 0;
    int dp[100001][5] = {0, };
    
    
    for(int i = 1; i<=4; i++){
        dp[1][i] = land[0][i-1];
    }
    
    for(int i = 2; i<=land.size(); i++){
        dp[i][1] = land[i-1][0] + max(dp[i-1][2], max(dp[i-1][3], dp[i-1][4]));
        dp[i][2] = land[i-1][1] + max(dp[i-1][1], max(dp[i-1][3], dp[i-1][4]));
        dp[i][3] = land[i-1][2] + max(dp[i-1][1], max(dp[i-1][2], dp[i-1][4]));
        dp[i][4] = land[i-1][3] + max(dp[i-1][1], max(dp[i-1][2], dp[i-1][3]));
    }
    
    int n = land.size();
    int max_score = max(max(dp[n][1], dp[n][2]), max(dp[n][3], dp[n][4]));
    
    
    
    return max_score;
}