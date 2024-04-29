#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int t = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ' '){
            t = 0;
            answer.push_back(s[i]);
            continue;
        }
        
        if(t % 2 == 0){
            answer.push_back(toupper(s[i]));
            t++;
        }
        
        else{
            answer.push_back(tolower(s[i]));
            t++;
        }
    }
    
    return answer;
}