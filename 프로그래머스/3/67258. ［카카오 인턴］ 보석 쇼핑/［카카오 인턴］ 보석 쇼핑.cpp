#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int front = 0, rear = 0;
    int min_f = 0, min_r = 0;
    map <string, int> gem_map;
    
    for(int i = 0; i<gems.size(); i++){
        gem_map[gems[i]]++;
        
        if(gem_map[gems[i]] == 1){
            front = i;
            min_f = front;
            min_r = rear;
        }
        
        else{
            front = i;
            int j = rear;
            for(; j<i; j++){
                if(gem_map[gems[j]] > 1){
                    gem_map[gems[j]]--;
                }
                
                else{
                    rear = j;
                    if((front - rear) < (min_f - min_r)){
                        min_f = front;
                        min_r = rear;
                    }
                    break;
                }
            }
        }
        
        // cout<<min_r<<gems[min_r]<<" - "<<min_f<<gems[min_f]<<endl; 
    }
    
    // cout<<min_r<<" "<<min_f<<endl;
    answer.push_back(min_r+1);
    answer.push_back(min_f+1);
    
    return answer;
}