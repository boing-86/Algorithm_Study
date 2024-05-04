#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.rbegin(), citations.rend());
    // 6 5 3 1 0
    for(int i = 0; i<citations.size(); i++){
        if(citations[i] <= i+1){
            answer = max(citations[i], i);
            return answer;
        }
    }
    answer = citations.size();
    
    return answer;
}