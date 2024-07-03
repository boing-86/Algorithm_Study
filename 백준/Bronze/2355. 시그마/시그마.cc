#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long a, b;
    cin>>a>>b;

    if(a > b){
        swap(a, b);
    }

    cout<<((a + b) * (b - a + 1) / 2);
    
}