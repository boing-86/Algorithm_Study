#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(auto skill_tree : skill_trees){
        deque<char> dq(skill.begin(), skill.end());
        bool is_possible = true;
        
        for(int i = 0; i<skill_tree.size(); i++){
            
            if(dq.empty()){
                is_possible = true;
                break;
            }
            
            if(dq.front() == skill_tree[i]){
                dq.pop_front();
            }
            
            else if(find(dq.begin(), dq.end(), skill_tree[i]) != dq.end()){
                is_possible = false;
                break;
            }
        }
        if(is_possible){
            answer++;
        }
    }
        
    return answer;
}