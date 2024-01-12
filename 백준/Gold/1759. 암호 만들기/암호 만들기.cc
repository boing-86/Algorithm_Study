#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<char> alphabets;
bool visited[16] = {false, };
vector<char> result;

void recursion(int depth, int index){
  if(depth == l){
    bool is_vowels = false;
    int consonant_count = 0;
    for(int i = 0; i<c; i++){
      if(visited[i]){
        result.push_back(alphabets[i]);
        if(alphabets[i] == 'a' || alphabets[i] == 'e' || alphabets[i] == 'i' || alphabets[i] == 'o' || alphabets[i] == 'u'){
          is_vowels = true;
        }
        else{
          consonant_count++;
        }
      }
    }

    if(is_vowels && consonant_count >= 2){
      for(auto a : result){
        cout<<a;
      }
      cout<<"\n";
    }
    result.clear();
    return ;
  }

  for(int i = index ; i < c; i++){
    if(!visited[i]){
      visited[i] = true;
      recursion(depth+1, i+1);
      visited[i] = false;
    }
  }
}

int main(){
  cin>>l>>c;

  for(int i = 0; i<c; i++){
    char a;
    cin>>a;
    alphabets.push_back(a);
  }

  sort(alphabets.begin(), alphabets.end());

  recursion(0, 0);
}