#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> belt;
    int iter = order.size();
    int index = 0;
    
    for(int i = 1; i<=iter; i++){
        belt.push(i);
        
        while(!belt.empty() && belt.top() == order[index]){
            answer++;
            belt.pop();
            index++;
        }
    }
    
    return answer;
}