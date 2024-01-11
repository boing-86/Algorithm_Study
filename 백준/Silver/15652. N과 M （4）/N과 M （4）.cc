#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[9] = {0, };
vector<int> result;

void recursion(int num, int depth){

  if (depth == m){
    for(auto a : result){
      cout<<a<< " ";
    }
    cout<<endl;
    return;
  }

  for(int i = num; i < n+1; i++){
    result.push_back(i);
    recursion(i, depth+1);
    result.pop_back();
  }  
}

int main() {
  cin>>n>>m;
  recursion(1, 0);
  
}