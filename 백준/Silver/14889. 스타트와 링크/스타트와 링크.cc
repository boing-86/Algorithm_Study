#include <iostream>
#include <vector>
using namespace std;

int n;
int arr_s[21][21];
bool visited[21] = {false, };
int min_gap = 1987654321;

void recursion(int x, int depth){
  if(depth == n/2){
    int perform_a = 0;
    int perform_b = 0;

    for(int i = 1; i<=n; i++){
      for(int j = 1; j<=n; j++){
        if(visited[i] && visited[j]){
          perform_a += arr_s[i][j];
        }

        else if (!visited[i] && !visited[j]){
          perform_b += arr_s[i][j];
        }
      }
    }
    min_gap = min(min_gap, abs(perform_a - perform_b));
    return;
  }

  for(int i = x; i <= n; i++){
    if(!visited[i]){
      visited[i] = true;
      recursion(i + 1, depth + 1);
      visited[i] = false;
    }
  }
}


int main(){
  cin>>n;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin>>arr_s[i][j];
    }
  }
  recursion(1, 0);

  cout<<min_gap;
  
}