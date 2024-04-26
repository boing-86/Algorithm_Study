#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    queue<int> q1;
    queue<int> q2;
    long long q1_sum = 0;
    long long q2_sum = 0;
    long long target = 0;
    
    for(auto a : queue1){
        q1.push(a);
        q1_sum += a;
    }
    
    for(auto a : queue2){
        q2.push(a);
        q2_sum += a;
    }
    
    target = (q1_sum + q2_sum) / 2;
    
    if((q1_sum + q2_sum) % 2){
        return -1;
    }
    
    int t = 0;
    int max_t = 2 * (q1.size() + q2.size());
    
    while(max_t > t){
        if(q1.empty() || q2.empty()){
            return -1;
        }
        
        if(q1_sum == target){
            return t;
        }
        
        if(q1_sum < target){
            int tmp = q2.front();
            q2.pop();
            q1.push(tmp);
            q1_sum += tmp;
            q2_sum -= tmp;
        }
        
        else if(q1_sum > target){
            int tmp = q1.front();
            q1.pop();
            q2.push(tmp);
            q1_sum -= tmp;
            q2_sum += tmp;
        }
        
        t++;
    }
    
    return -1;
}