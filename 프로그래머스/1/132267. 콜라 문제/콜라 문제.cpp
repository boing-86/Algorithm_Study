#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    int q = 0;
    int r = 0;
    
    while(n >= a){
        q = n / a;
        r = n % a + q * b;
        
        //cout<<q<<" "<<r<<endl;
        
        answer += q*b;
        
        n = r;
    }
    
    return answer;
}