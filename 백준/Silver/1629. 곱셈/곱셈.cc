#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
using namespace std;


long long recursive(long long a, long long b, long long c){

    if(b == 1){
        return a % c;
    }

    else{
        long long r = recursive(a, b/2, c);

        if(b % 2 == 0){
            return r*r%c;
        }

        else{
            return r*r%c*a%c;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long a, b, c;
    cin>>a>>b>>c;

    cout<<recursive(a, b, c);

}