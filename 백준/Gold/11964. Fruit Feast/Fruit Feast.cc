#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#define INF 987654321
using namespace std;

int t, a, b;
int result = -INF;
bool w;
bool v[500001];


void dp(int temp, bool water){
    if(v[temp]){
        return ;
    }
    v[temp] = true;

    result = max(result, temp);
    int sum = temp + a;

    if(sum <= t){
        if(!water){
            dp(sum/2, true);
        }
        dp(sum, water);
    }

    sum = temp + b;

    if(sum <= t){
        if(!water){
            dp(sum/2, true);
        }

        dp(sum, water);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>t>>a>>b;

    dp(0, false);

    cout<<result;
}