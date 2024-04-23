#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    long long arr[60001];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    
    for(int i = 4; i <= n; i++){
        arr[i] = (arr[i-1] + arr[i-2]) % 1000000007;
    }
    return arr[n];
}