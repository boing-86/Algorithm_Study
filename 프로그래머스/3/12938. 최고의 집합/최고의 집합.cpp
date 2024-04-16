#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int q = s / n;
    int m = n - s % n;
    
    if(q == 0){
        answer.push_back(-1);
        return answer;
    }
    
    for(int i = 0; i<m; i++){
        answer.push_back(q);
    }
    
    for(int i = 0; i< s % n; i++){
        answer.push_back(q+1);
    }

    return answer;
}