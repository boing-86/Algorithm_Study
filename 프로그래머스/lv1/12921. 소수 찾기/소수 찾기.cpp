#include <string>
#include <vector>

using namespace std;

int solution(const int n) {
    int answer = 0;
       int num[1000000] = {0, };
    
    for(int i = 2; i<=n; i++){
        num[i] = i;
    }
    
    for(int i = 2; i<=n; i++){
        if(num[i] == 0){
            continue;
        }
        for(int j = 2*i; j<=n; j+=i){
            num[j] = 0;
        }
    }

    for(auto i : num){
        if(i != 0){
            answer++;
        }
    }
    
    return answer;
}