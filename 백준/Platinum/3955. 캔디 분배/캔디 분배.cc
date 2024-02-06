#include <iostream>
#include <queue>
#include <string.h>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair<int, int> pii;

int t, k, c;

pii e_gcd(int x, int y){
    pii c_a(1, 0), c_b(0, 1);

    int a = x;
    int b = y;
    while(b){
        int q = a/b;
        int r = a%b;
        // cout<<a<<" "<<b<<" "<<q<<" "<<r<<" "<<endl;
        a = b;
        b = r;
        pii c_r (c_a.first - q * c_b.first, c_a.second - q * c_b.second);
        c_a = c_b;
        c_b = c_r;
    }

    int gcd = x * c_a.first + y * c_a.second;
    return c_a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>t;

    while(t--){
        cin>>k>>c;
        if(c == 1){
            if(k >= 1000000000){
                cout<<"IMPOSSIBLE\n";

            } else{
                cout<< k+1 <<"\n";
            }
            continue;
        }

        else if(k == 1){
            cout<< "1\n";
            continue;
        }

        pii c_a = e_gcd(k, c);
        int gcd = k * c_a.first + c * c_a.second;
        
        if(gcd != 1){
            cout<<"IMPOSSIBLE\n";
            continue;
        }

        int tmp = c_a.second;
        while(tmp < 0) tmp+=k;
        cout<<tmp<<"\n";
    }

}