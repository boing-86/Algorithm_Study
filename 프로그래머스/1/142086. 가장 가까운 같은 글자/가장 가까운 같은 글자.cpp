#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    map <char,int> m;
    vector<int> answer;
    
    for(int i = 1; i<=s.size(); i++){
        
        if(m[s[i-1]] != 0){
            answer.push_back(i-m[s[i-1]]);
            m[s[i-1]] = i;
        }
        
        else{
            int tmp = i;
            m.insert({s[i-1], tmp});
            answer.push_back(-1);
        }
        
        for(auto j = m.begin(); j != m.end(); j++){
            cout<<j->first<<" "<<j->second<<endl;
        }
        cout<<"-----------\n";
    }
    
    return answer;
}