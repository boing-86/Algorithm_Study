#include <iostream>
using namespace std;

const int mod = 10007;
int n;
int nCk[53][53] = {0, };

void get_triangle(){

    for(int n = 0; n<=52; n++){
        nCk[n][0] = 1;
        nCk[n][n] = 1;

        for(int k = 1; k<=n; k++){
            int num = nCk[n-1][k-1] + nCk[n-1][k];
            nCk[n][k] = num % mod;
        }
    }
}

int main(){
    cin>>n;

    get_triangle();

    int result = 0;

    for(int i = 4; i <= n; i+=4){
        if( (i/4) % 2 == 1){
            result += nCk[13][i/4] * nCk[52-i][n-i];
        }
        else{
            result -= nCk[13][i/4] * nCk[52-i][n-i];
        }
        result %= mod;
    }

    if(result < 0){
        result += mod;
    }

    cout<<result;
}