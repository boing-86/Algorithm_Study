#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <memory.h>
using namespace std;

int dp[1000001];


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m, n;
    cin>>m>>n;

    memset(dp, -1, 1000001 * sizeof(int));
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    
    for(int i = 2; i<=sqrt(n); i++){
        if(dp[i] == 0){
            continue;
        }

        for(int j = i*i; j <= n; j+=i){
            dp[j] = 0;
        }
    }

    for(int i = m; i<=n; i++){
        if(dp[i] != 0){
            cout<<i<<"\n";
        }
    }


}