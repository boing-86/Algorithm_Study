#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <memory.h>
using namespace std;

int arr[1025][1025];

int recursive(int x, int y, int n){

    if(n==1){
        return arr[x][y];
    }

    else{
        vector<int> v(4, 0);

        v[0] = recursive(x, y, n/2);
        v[1] = recursive(x + n/2, y, n/2);
        v[2] = recursive(x, y + n/2, n/2);
        v[3] = recursive(x + n/2, y + n/2, n/2);

        sort(v.begin(), v.end());
        return v[1];
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0; i<=n; i++){
        memset(arr[i], 0, sizeof(int) * n);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    cout<<recursive(0, 0, n);

}