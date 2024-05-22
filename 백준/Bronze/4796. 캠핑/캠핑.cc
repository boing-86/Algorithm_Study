#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int l, p, v;
    int c = 0;

    while(1){

        cin>>l>>p>>v;

        if(l == 0 && p == 0 && v == 0){
            break;
        }

        int answer = 0;
        int q = v / p;
        int r = v % p;

        answer += l * q;

        if(r < l){
            answer += r;
        }

        else{
            answer += l;
        }

        cout<<"Case "<<++c<<": "<<answer<<"\n";

    }

    return 0;
}