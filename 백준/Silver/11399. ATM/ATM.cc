#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int current = 0;
int min_time = 0;
vector <int> p;

int main(){
    cin>>n;

    for(int i = 1; i<=n; i++){
        int a;
        cin>>a;
        p.push_back(a);
    }

    sort(p.begin(), p.end());

    for(int i = 0; i<n; i++){
        current = current + p[i];
        min_time = min_time + current;
    }

    cout<<min_time<<endl;
}