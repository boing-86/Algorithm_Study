#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
#include <sstream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        vector<int> arr;
        int sum = 0;
        int answer = -987654321;
        int dp[1001] = {0, };

        cin>>n;

        for(int i = 1; i<=n; i++){
            int tmp;
            cin>>tmp;
            
            dp[i] = max(dp[i-1] + tmp, tmp);
            answer = max(answer, dp[i]);
        }

        cout<<answer<<"\n";
    }

    return 0;
}