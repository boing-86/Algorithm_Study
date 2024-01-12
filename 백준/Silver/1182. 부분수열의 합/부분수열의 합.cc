#include <iostream>
#include <vector>
using namespace std;

int n, s;
int sequence[21];
int count = 0;
int sum = 0;
bool visited[21] = {false, };
//백트래킹, 중복없음

void recursion(int depth, int index){

  if(sum == s && depth > 0){
    count++;
  }

  if(depth == n){
    return ;
  }

  for(int i = index; i<=n; i++){
    if(!visited[i]){
      visited[i] = true;
      sum += sequence[i];
      recursion(depth+1, i+1);
      visited[i] = false;
      sum -= sequence[i];
    }
  }
}

int main(){
  cin>>n>>s;

  for(int i = 1; i<=n; i++){
    cin>>sequence[i];
  }

  recursion(0, 1);
  cout<<count;
}