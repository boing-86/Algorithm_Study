#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
#include <sstream>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin>>n>>k;
    int arr[1000001] = {0, };
    int max_index = 0;
    for(int i = 0; i<n; i++){
        int g, x;
        cin>>g>>x;
        arr[x] = g;

        if(max_index < x){
            max_index = x;
        }
    }

    k = 2 * k + 1;
    int sum = 0;
    int answer = 0;

    for(int i = 0; i <= max_index; i++){

        if(i >= k){
            sum -= arr[i-k];
        }

        sum += arr[i];
        answer = max(answer, sum);

        // cout<<i<<" - "<<sum<<endl;
    }

    cout<<answer;

    return 0;
}