#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;

bool isPrime(long long n){

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;

        if(n >= 0 && n <= 2){
            cout<<2<<"\n";
        }

        else if(n == 3){
            cout<<3<<"\n";
        }

        else if(n == 4 || n == 5){
            cout<<5<<"\n";
        }

        else if(n == 6 || n == 7){
            cout<<7<<"\n";
        }

        else{
            while(!isPrime(n)){
                n++;
            }
            cout<<n<<"\n";
        }
    }

}