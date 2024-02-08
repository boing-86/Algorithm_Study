#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> x[100001];
    vector<int> y[100001];

    for(int i = 0; i<n; i++){
        int a, b;
        cin>>a>>b;
        x[a].push_back(b);
        y[b].push_back(a);
    }

    long long result = 0;

    for(int i = 0; i<100001; i++){
        if(x[i].size() != 0){
            for(auto a : x[i]){
                if(y[a].size() != 0){
                    result += (x[i].size()-1) * (y[a].size()-1);
                }
            }
        }
    }

    cout<<result;
    
}