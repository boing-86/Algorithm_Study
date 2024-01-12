#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[12] = {0,};
int operators[4] = {0, };

int min_result = 1987654321;
int max_result = -1987654321;
// 아이디어 : 백트래킹
// 자료구조
// 어떻게 계산할 것인가?

void recursion(int result, int depth){

  if(depth == n){
    max_result = max(max_result, result);
    min_result = min(min_result, result);
    return;
  }

  for(int i = 0; i<4; i++){
    if(operators[i] > 0){
      operators[i]--;
      if(i == 0){
        recursion(result + arr[depth], depth+1);
      }
      else if(i == 1){
        recursion(result - arr[depth], depth+1);
      }
      else if(i == 2){
        recursion(result * arr[depth], depth+1);
      }
      else{
        recursion(result / arr[depth], depth+1);
      }
      operators[i]++;
    }
  }
}

int main(){
  cin>>n;
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }

  for(int i = 0; i<4; i++){
    cin>>operators[i];
  }

  recursion(arr[0], 1);
  cout<<max_result<<"\n"<<min_result;
  
}