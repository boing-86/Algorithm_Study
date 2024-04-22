#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    map<string, int> map;
    
    for(int i = 0; i<s.size(); i++){
        string tmp = "";
        if(isdigit(s[i])){
            while(isdigit(s[i])){
                tmp.push_back(s[i++]);
            }
        }

        if(map.find(tmp) != map.end()){
            map[tmp]++;
        } else{
            map.insert({tmp, 1});
        }
    }
    
    vector<pair<string, int>> v(map.begin(), map.end());
    sort(v.begin(), v.end(), cmp);
    
    for(int i = 1; i<v.size(); i++){
        answer.push_back(stoi(v[i].first));
    }
    
    
    return answer;
}