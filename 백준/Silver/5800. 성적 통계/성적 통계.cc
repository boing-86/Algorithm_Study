#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int k, n;

int main(){
    cin>>k;

    for(int j = 1; j<=k; j++){
        vector <int> v;
        cin>>n;

        for(int i = 0; i<n; i++){
            int a;
            cin>>a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());
        int score_max = v[n-1];
        int min = v[0];
        int gap = 0;
        
        for(int i = 0; i<n-1; i++){
            gap = max(gap, v[i+1]-v[i]);
        }

        cout<<"Class "<<j<<endl;
        cout<<"Max "<<score_max<<", Min "<<min<<", Largest gap "<<gap<<endl;

    }
}