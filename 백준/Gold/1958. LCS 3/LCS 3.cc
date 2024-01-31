#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
int dp[101][101][101];



int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string s, t, r;
  cin>>s>>t>>r;

  for(int i = 1; i <= s.size(); i++){
    for(int j = 1; j <= t.size(); j++){
      for(int k = 1; k <= r.size(); k++){
        if((s[i-1] == t[j-1]) && (t[j-1] == r[k-1])){
          dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
        }
        else{
          dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
        }
      }
    }
  }

  cout<<dp[s.size()][t.size()][r.size()];
}