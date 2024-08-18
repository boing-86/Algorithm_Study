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

    int n;
    long long k;
    long long v[100001] = {0, };
    cin>>n;

    for(int i = 1; i<=n; i++){
        cin>>v[i];
        v[i] += v[i-1];
    }

    cin>>k;
    long long count = 0;
    int j = 1;

    for(int i = 1; i<=n; i++){
        while(j <= n && v[j] - v[i-1] <= k){
            j++;
        }

        count += (n - j + 1);
    }

    cout<<count;

}