#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map <string, int> m;
    
    for(int i = 0; i<name.size(); i++){
        m.insert({name[i], yearning[i]});
    }
    
    for(auto v : photo){
        int score = 0;
        for(auto n : v){
            score += m[n];
        }
        answer.push_back(score);
    }
    
    
    
    return answer;
}