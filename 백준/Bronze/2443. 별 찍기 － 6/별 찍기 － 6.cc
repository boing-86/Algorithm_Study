#include <iostream>

int main() {
  int n;
  std::cin >> n;

  for(int i = n; i > 0; i--){
    for(int j = n-i; j > 0; j--){
      std::cout<<" ";
    }
    
    for(int k = 2*i-1; k > 0; k--){
      std::cout<<"*";
    }
    std::cout<<std::endl;
  }
  
}