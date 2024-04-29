#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long p_int = stoll(p);
    
    for(int i = 0; i<t.size() - p.size() + 1; i++){
        string tmp = t.substr(i, p.size());
        // cout<<tmp<<" "<<p_int<<"\n";
        if(stoll(tmp) <= p_int){
            answer++;
        }
    }
    
    
    return answer;
}