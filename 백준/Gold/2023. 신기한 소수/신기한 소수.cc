#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#include <memory.h>
#include <cmath>
using namespace std;
int n;

bool isPrime(int num){
    if(num == 0 || num == 1){
        return false;
    }

    for(int i = 2; i <= num/2; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int num, int size){
    if(size == n){
        if(isPrime(num)){
            cout<<num<<"\n";
            return ;
        }
    }

    for(int i = 1; i<=9; i++){
        if(isPrime(num*10 + i)){
            dfs(num*10+i, size+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);
}