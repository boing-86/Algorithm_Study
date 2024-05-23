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
    
    int m,n;
    vector<int> v;

    cin>>m>>n;

    for (int i = 0; i<n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int left = 1;
    int right = v[n-1];
    int mid = 0;
    int answer = 0;

    while(left <= right){
        mid = (left + right) / 2;
        int count = 0;

        for(int i = 0; i < n; i++){
            count += v[i] / mid;
        }

        // cout<<left<<", "<<right<<" ";
        // cout<< mid <<" - "<<count<<endl;

        if(count >= m){
            left = mid + 1;
            answer = mid;
        }

        else if (count < m) {
            right = mid - 1;
        }
    }

    cout<<answer<<"\n";

}