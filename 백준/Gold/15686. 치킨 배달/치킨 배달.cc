#include <iostream>
#include <vector>
using namespace std;

int n, m;
int chicken_count = 0;
int min_chicken_distance = 1987654321;
bool visited[14] = {false, };
vector<pair<int, int>> chicken_address;
vector<pair<int, int>> house_address;

void get_min_distance(){
  int chicken_distance = 0;

  for(auto a : house_address){
    int house_to_chicken_min = 1987654321;
    for(int i = 0; i < chicken_count; i++){
      if(visited[i]){
        int tmp_distance = abs(a.first-chicken_address[i].first) + abs(a.second - chicken_address[i].second);
        house_to_chicken_min = min(house_to_chicken_min, tmp_distance);
      }
    }
    chicken_distance += house_to_chicken_min;
  }
  min_chicken_distance = min(min_chicken_distance, chicken_distance);
}

void recursion(int depth, int index){
  if(depth == m){
    get_min_distance();
    return;
  }

  for(int i = index; i<chicken_count; i++){
    if(!visited[i]){
      visited[i] = true;
      recursion(depth+1, i+1);
      visited[i] = false;
    }
  }
  
}

int main(){
  cin>>n>>m;
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n; j++){
      int a;
      cin>>a;
      if(a == 1){
        house_address.push_back(make_pair(i, j));
      }

      if(a == 2){
        chicken_address.push_back(make_pair(i, j));
      }
    }
  }

  chicken_count = chicken_address.size();
  recursion(0, 0);
  cout<<min_chicken_distance;
}