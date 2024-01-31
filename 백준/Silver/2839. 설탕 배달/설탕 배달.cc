#include <iostream>
#include <string.h>

using namespace std;

const int INF = 987654321;
int cache[5001];

int dp(int a){
  if(a < 0){ return INF; }
  if(a == 0){ return 0; }
  if(cache[a] != -1){ return cache[a]; }
  
  cache[a] = min(dp(a-3)+1, dp(a-5)+1);
  return cache[a];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n;
  cin>>n;

  memset(cache, -1, 5001*sizeof(int));

  cache[3] = cache[5] = 1;
  int result = dp(n);

  if(result <= 5001){
    cout<<result;
  } else{
    cout<<-1;
  }
}