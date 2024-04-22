#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q(works.begin(), works.end());
    
    while(n--){
        int tmp = q.top()-1;
        q.pop();
        if(tmp < 0){
            return 0;
        }
        q.push(tmp);
    }
    
    while (!q.empty()){
        int tmp = q.top();
        q.pop();
        answer += tmp * tmp;
    }
    return answer;
}