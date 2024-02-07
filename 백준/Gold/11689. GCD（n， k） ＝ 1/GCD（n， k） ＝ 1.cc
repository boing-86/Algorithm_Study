#include <iostream>
#include <math.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n;
    cin>>n;
    
    long long result = n;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            result = result * (1 - 1.0 / i);
        }
    }

    if(n != 1){
        result *= (1 - 1.0/n);
    }

    cout<<result;

}