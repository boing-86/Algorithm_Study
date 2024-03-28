#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool isPrime(long long m){
    if(m <= 1){
        return false;
    }
    
    for(int i = 2; i<=sqrt(m); i++){
        if(m % i == 0){
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string number = "";
    
    while(n >= k){
        char tmp = (n%k) + '0';
        number.insert(number.begin(), tmp);
        n = n/k;
    }
    
    number.insert(number.begin(), n+'0');
    istringstream ss(number);
    string buffer;
    
    while(getline(ss, buffer, '0')){
        if(buffer.empty()){
            continue;
        }
        
        else{
            if(isPrime(stol(buffer))){
            answer++;
        }   
        }
    }
    
    
    return answer;
}