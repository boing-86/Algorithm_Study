#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<pair<int, int>> q;
    
    for(int i = 0; i<prices.size(); i++){
        while(!q.empty() && q.back().first > prices[i]){
            answer[q.back().second] = i - q.back().second;
            q.pop_back();
        }
        
        q.push_back({prices[i], i});
    }
    
    for(int i = 0; i<prices.size(); i++){
        if(answer[i] == 0){
            answer[i] = prices.size() - i - 1;
        }
    }
    
    return answer;
}