#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = 0;
    vector<int> x;
    vector<int> y;
    
    for(auto a : sizes){
        x.push_back(max(a[0], a[1]));
        y.push_back(min(a[0], a[1]));
    }
    
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    
    
    
    return x[0] * y[0];
}