#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    int a = 0; int b = 0;
    
    while(pq.size() > 1 && pq.top() < K){
        answer++;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        
        pq.push(a + b * 2);
    }
    
    if(pq.top() < K){
        return -1;
    }
    
    return answer;
}