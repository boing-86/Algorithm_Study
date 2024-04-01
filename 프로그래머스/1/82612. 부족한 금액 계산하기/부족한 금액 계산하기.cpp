#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    
    long long value = 0;
    for(int i = 1; i<=count; i++){
        value += i*price;
    }
    
    answer = money - value;
    if(answer < 0){
        answer *= -1;
    }
    else{
        answer = 0;
    }

    return answer;
}