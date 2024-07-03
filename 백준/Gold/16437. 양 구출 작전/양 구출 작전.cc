#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<long long> map[123457];
int sheep[123457];
int n, answer;


long long dfs(int num){

    if(map[num].size() == 0){
        if(sheep[num] < 0){
            return 0;
        }

        return sheep[num];
    }

    long long sum = 0;
    sum += sheep[num];

    for(int i = 0; i<map[num].size(); i++){
        int next = map[num][i];
        sum += dfs(next);
    }

    if(sum < 0){
        return 0;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    for(int i = 2; i<=n; i++){
        char t;
        int a, p;
        cin>>t>>a>>p;

        if(t == 'W'){
            a *= -1;
        }

        map[p].push_back(i);
        sheep[i] = a;
    }

    sheep[1] = 0;
    answer = 0;
    cout<<dfs(1);

}