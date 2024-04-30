#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    // z = 122;
    // Z = 90;
    
    for(int i = 0; i<s.size(); i++){
        char c;
        int tmp;
        
        if(s[i] == ' '){
            c = ' ';
        }
        
        else if('a' <= s[i] && s[i] <= 'z'){
            tmp = s[i] - 'a';
            tmp = (tmp+n-1) % 25 + 'a';
            c = (char)tmp;
        }
        
        else if ('A' <= s[i] && s[i] <= 'Z'){
            tmp = s[i] - 'A';
            tmp = (tmp+n-1) % 25 + 'A';
            c = (char)tmp;
        }
        
        answer.push_back(c);
    }
    
    return answer;
}