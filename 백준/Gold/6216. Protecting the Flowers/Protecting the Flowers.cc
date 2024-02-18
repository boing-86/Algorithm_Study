#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <pair<long long, long long>> cow;

bool compare(pair<long long, long long> a, pair<long long, long long>b){
    double x = ((double)a.first/(double)a.second) * 100;
    double y = ((double)b.first/(double)b.second) * 100;
    return x < y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n;
    long long di_sum = 0;
    for(int i = 0; i<n; i++){
        long long d, t;
        cin>>t>>d;
        cow.push_back({t, d});
        di_sum += d;
    }

    sort(cow.begin(), cow.end(), compare);
    
    long long sum = 0;
    for(int i = 0; i<cow.size(); i++){
        di_sum -= cow[i].second;
        sum += 2 * cow[i].first * di_sum;
    }

    cout<<sum;
   
}