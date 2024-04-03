#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> v;
    
    for(int i = 1; i<27; i++){
        string tmp;
        tmp.push_back((char)(64+i));
        v.insert({tmp, i});
    }
    
    int index = 27;
    string tmp = "";
    
    for(int i = 0; i<msg.size(); i++){
        tmp.push_back(msg[i]);
        
        if(v[tmp] == 0){
            v[tmp] = index;
            tmp.pop_back();
            answer.push_back(v[tmp]);
            index++; i--;
            tmp = "";
        }
    }
    answer.push_back(v[tmp]);
    
    
    
    return answer;
}