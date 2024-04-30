#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N = 0;

bool cmp(string a, string b){
    
    if(a[N] == b[N]){
        return a < b;
    }
    
    return a[N] < b[N];    
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    N = n;
    
    sort(strings.begin(), strings.end(), cmp);
    
    for(auto a : strings){
        answer.push_back(a);
    }
    
    return answer;
}