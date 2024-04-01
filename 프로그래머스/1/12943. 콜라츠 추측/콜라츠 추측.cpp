#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int input) {
    int answer = 0;
    long long num = input;
    
    if(num == 1){
        return 0;
    }
    
    while(num != 1 && answer < 500){
        cout<<num<<" ";
        if(num % 2 == 0){
            num /= 2;
        }
        
        else{
            num = num * 3 + 1;
        }
        
        answer++;
    }
    
    if (answer >= 500){
        answer = -1;
    }
    return answer;
}