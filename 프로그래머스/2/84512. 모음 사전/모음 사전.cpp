#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

char arr[5] = {'A', 'E', 'I', 'O', 'U'};
vector <string> dict;
int target_length = 0;
int answer = 0;

void recursive(int depth, string tmp){
    dict.push_back(tmp);
    
    if(depth == 5){
        return ;
    }
    
    for(int i = 0; i < 5; i++){
        recursive(depth + 1, tmp + arr[i]);
    }
}

int solution(string word) {
    target_length = word.size();
    recursive(0, "");
    
    auto a = find(dict.begin(), dict.end(), word);
    answer = a - dict.begin();
    
    return answer;
}