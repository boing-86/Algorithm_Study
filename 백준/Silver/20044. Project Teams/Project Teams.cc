#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0;
vector <int> w;

int main(){

    cin>>n;
    int a;

    for(int i = 0; i<2*n; i++){
        cin>>a;
        w.push_back(a);
    }
    sort(w.begin(), w.end());

    a = 123456789;

    for(int i = 0; i<n; i++){
        a = min(a, w[i] + w[2*n-i-1]);
    }

    cout<<a<<endl;

    return 0;
}
