#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
#include <sstream>
#include <string.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k, q, m;
    bool is_sleep[5003];
    int check[5003];

    cin>>n>>k>>q>>m;

    for(int i = 0; i <= n+2; i++){
        is_sleep[i] = false;
        check[i] = 1;
    }

    check[0] = check[1] = check[2] = 0;

    for(int i = 0; i<k; i++){
        int idx;
        cin>>idx;
        is_sleep[idx] = true;
    }

    for(int i = 0; i<q; i++){
        int num;
        cin>>num;
        if(is_sleep[num]){
            continue;
        }

        int a = num;
        while(a <= n+2){
            if(is_sleep[a]){
                a += num;
                continue;
            }

            check[a] = 0;
            a += num;
        }
    }

    for(int i = 4; i<=n+2; i++){
        check[i] += check[i-1];
    }

    // for(int i = 0; i<= n+2; i++){
    //     cout<<check[i]<<" ";

    //     if(i % 10 == 0){
    //         cout<<endl;
    //     }
    // }

    for(int i = 0; i<m; i++){
        int s, e;
        cin>>s>>e;
        
        int answer = check[e] - check[s-1];
        cout<<answer<<"\n";
    }


    return 0;
}