#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    int dp[5001];
    dp[0] = dp[1] = dp[2] = dp[4] = dp[7] = -1;
    dp[3] = dp[5] = 1;
    dp[6] = dp[8] = dp[10] = 2;

    dp[9] = dp[11] = 3;
    dp[12] = 4;

    cin>>n;
    if(n <= 12){
        cout<< dp[n];
        return 0;
    }

    for(int i = 13; i<=n; i++){
        dp[i] = min(dp[i-3] + 1, dp[i-5] + 1);
    }

    cout<<dp[n];
    return 0;
}