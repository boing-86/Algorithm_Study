#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
typedef pair<long long, long long> pll;

pll e_gcd(long long x, long long y){
    pll c_a(1, 0), c_b(0, 1);

    long long a = x;
    long long b = y;
    while(b){
        long long q = a/b;
        long long r = a%b;
        a = b;
        b = r;
        pll c_r (c_a.first - q * c_b.first, c_a.second - q * c_b.second);
        c_a = c_b;
        c_b = c_r;
    }
    return c_a;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, a;

    cin>>n>>a;

    long long inv = a % n;

    cout<< n-a<<" ";
    
    pll c_a = e_gcd(n, a);
    
    if((n * c_a.first + a * c_a.second) != 1){
        cout<<-1;
    }

    else{
        long long b = c_a.second;

        while(b <= 0){
            b += n;
        }

        cout<<b;
    }
}