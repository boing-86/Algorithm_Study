#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[9] = {0, };
vector<int> result;

void recursion(int depth){

  if (depth == m){
    for(auto a : result){
      cout<<a<< " ";
    }
    cout<<"\n";
    return;
  }

  for(int i = 1; i < n+1; i++){
      if (visited[i] == false){
        visited[i] = true;
        result.push_back(i);
        recursion(depth + 1);
        visited[i] = false;
        result.pop_back();
      }
  }  
}

int main() {
  cin>>n>>m;
  recursion(0);
  
}