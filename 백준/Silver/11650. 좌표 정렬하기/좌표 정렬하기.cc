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

    int n;
    vector<pair<int, int>> v;
    cin>>n;

    for(int i = 0; i<n; i++){
        int _x, _y;
        cin>>_x>>_y;
        v.push_back({_x, _y});
    }

    sort(v.begin(), v.end());
    
    for(auto a : v){
        cout<<a.first<<" "<<a.second<<"\n";
    }
    
    return 0;
}