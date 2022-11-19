#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> a;
    int max = 0;
    int dp[1001] = {0, };

    cin>>n;
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        a.push_back(num);
    }

    for(int i = 0; i<n; i++){
        int min = 0;
        for(int j = 0; j<i; j++){
            if(a[i] > a[j]){
                if(min < dp[j]){
                    min = dp[j];
                }
            }
        }
        dp[i] = min + 1;
        if(max < dp[i]){
            max = dp[i];
        }
    }
    cout<<max;
}