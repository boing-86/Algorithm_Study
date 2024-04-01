#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    auto iter = find(seoul.begin(), seoul.end(), "Kim");
    int index = iter - seoul.begin();
    answer = answer + to_string(index) + "에 있다";
    
    return answer;
}