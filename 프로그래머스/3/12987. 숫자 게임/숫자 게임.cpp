#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ia = 0;
    for(int ib = 0; ib<B.size(); ib++){
        if(B[ib] > A[ia]){
            ia++;
        }
    }
    
    
    return ia;
}