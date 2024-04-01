#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size() != 4 && s.size() != 6){
        return false;
    }
    
    for(auto a : s){
        if(a < 48 || a > 57){
            answer = false;
        }
    }
    return answer;
}