#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<int> dp;

void bi_search(int num){
    int left = 0;
    int right = dp.size()-1;
    int target = 1000010;
    
    while(left <= right){
        int center = (left + right)/2;
        int next = dp[center];
        if(next >= num){
            if(target > center){
                target = center;
            }
            right = center - 1;
        }
        else{
            left = center + 1;
        }
    }
    dp[target] = num;
}

int main(){

    cin>>n;
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    
    dp.push_back(arr[0]);

    for(int i = 1; i<n; i++){
        if(dp.back() < arr[i]){
            dp.push_back(arr[i]);
        }
        else{
            bi_search(arr[i]);
        }
    }

    cout<<dp.size()<<endl;
}