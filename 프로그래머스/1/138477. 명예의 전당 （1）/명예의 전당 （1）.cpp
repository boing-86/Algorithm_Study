#include <iostream>
#include <queue>
#include <string>
#include <vector>


using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue <int, vector<int>, greater<int>> pq;
    
    for(auto s : score){
        pq.push(s);
        
        if(pq.size() > k){
            pq.pop();
        }
        
        answer.push_back(pq.top());
    }
    
    return answer;
}