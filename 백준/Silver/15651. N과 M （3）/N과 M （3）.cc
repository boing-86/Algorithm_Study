#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> result;

void recursion(int num, int depth){

  if (depth == m){
    for(auto a : result){
      cout<<a<< " ";
    }
    cout<<"\n";
    return;
  }

  for(int i = 1; i < n+1; i++){
    result.push_back(i);
    recursion(i, depth+1);
    result.pop_back();
  }  
}

int main() {
  cin>>n>>m;
  recursion(1, 0);
  
}