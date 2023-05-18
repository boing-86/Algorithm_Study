#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int value[101];
int weight[101];
int dp[101][100001] = {0, };

// Knapsack 알고리즘 함수
int knapsack(int n, int capacity) {

    // DP 테이블 갱신
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i] <= w) {
                dp[i][w] = max(dp[i-1][w], value[i] + dp[i-1][w-weight[i]]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {

    // 물건의 개수 n, 최대 가방 무게 capacity
    int n, capacity;

    cin>>n>>capacity;

    // 물건의 정보 입력
    for(int i = 1; i<=n; i++){
        cin>>weight[i]>>value[i];
    }



    int max_value = knapsack(n, capacity);

    cout << max_value << endl;

    return 0;
}
