#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string answer = "";
    vector <string> v;
    
    for(auto a : numbers){
        v.push_back(to_string(a));
    }
    
    sort(v.begin(), v.end(), cmp);
    
    if(v[0] == "0"){
        return "0";
    }
    
    for(auto a : v){
        answer += a;
    }
    
    return answer;
}