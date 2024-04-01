#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(char a, char b){
    return a > b;
}

long long solution(long long n) {
    long long answer = 0;
    string a = to_string(n);
    
    sort(a.begin(), a.end(), cmp);
    answer = stoll(a);
    
    
    return answer;
}