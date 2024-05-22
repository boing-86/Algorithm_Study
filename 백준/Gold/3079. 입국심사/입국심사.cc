#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    unsigned long long n, m;
    vector <unsigned long long> v;

    cin>>n>>m;

    for(long long i = 0; i<n; i++){
        long long tmp;
        cin>>tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    unsigned long long high = m * v[n-1];
    unsigned long long low = 1;
    unsigned long long mid;
    unsigned long long answer = 0;

    while(high >= low){
        mid = (high + low) / 2;
        // cout<<high<<" "<<mid<<" "<<low<<" - ";

        unsigned long long sum = 0;

        for(long long i = 0; i<n; i++){
            sum += (mid / v[i]);
        }
        //cout<<sum<<endl;

        if(sum >= m){
            high = mid - 1;
            if(answer > mid || answer == 0){
                answer = mid;
            }
        }
        else{
            low = mid + 1;
        }
    }
    cout<<answer;
}