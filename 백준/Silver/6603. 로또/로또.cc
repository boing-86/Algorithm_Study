#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int depth_threshold = 6;
int k;
int arr[14];
bool visited[14] = {false, };

void recursion(int depth, int index){

  if(depth == 6){
    for(int i = 0; i<k; i++){
      if(visited[i] == true){
        cout<<arr[i]<<" ";
      }
    }
    cout<<"\n";
    
    return;
  }

  for(int i = index; i<k; i++){
    if(!visited[i]){
      visited[i] = true;
      recursion(depth+1, i+1);
      visited[i] = false;
    }
  }
  
}

int main(){

  cin >> k;
  
  while(k !=0){
    for(int i = 0; i<k; i++){
      cin>>arr[i];
    }
    recursion(0, 0);
    cout<<"\n";
    cin>>k;
  }
}