#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long a, b;
    cin>>a>>b;

    long long g = gcd(a, b);
    if(g == 1){
        cout<<a * b;
    }

    else{
        long long result = 1;
        result *= (a / g);
        result *= (b / g);
        result *= g;
        cout<<result;
    }

    return 0;
}