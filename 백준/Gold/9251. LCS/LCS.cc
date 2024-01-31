#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
int dp[1001][1001];

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string s, t;
  cin>>s>>t;

  for(int i = 1; i <= s.size(); i++){
    for(int j = 1; j <= t.size(); j++){
      if(s[i-1] == t[j-1]){
        dp[i][j] = dp[i-1][j-1] + 1; 
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  cout<<dp[s.size()][t.size()];
}