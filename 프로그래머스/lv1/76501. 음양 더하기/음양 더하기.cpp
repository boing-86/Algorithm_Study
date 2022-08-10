#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    for(int i = 0; i<absolutes.size(); i++){
        int sign = 1;
        if(!signs[i]){
            sign = -1;
        }
        answer += sign * absolutes[i];
    }
    
    return answer;
}