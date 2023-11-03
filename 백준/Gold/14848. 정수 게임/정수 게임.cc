#include <iostream>
#include <vector>

using namespace std;

long long n;
int k;
vector <long long> arr;
long long sum;

long long gcd(long long a, long long b){
    // Euclidean algorithm
    long long r = a % b;

    return r == 0 ? b : gcd(b, r);
}

int main(){
    
    cin>>n>>k;

    for(int j = 0; j<k; j++) {
        long long i;
        cin>>i;
        arr.push_back(i);
    }

    for(int i = 1; i < (1<<k); i++){
        long long lcm = 1;
        long long count = -1;

        for(int j = 0; j<k; j++){
            if ( (1<<j) & i){
                count *= -1;
                lcm = lcm * arr[j] / gcd(lcm, arr[j]);
            }
        }
        sum += count * (n / lcm);
    }

    cout<< n - sum;

}