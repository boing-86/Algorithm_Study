#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <deque>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> a;
    map<int, int> b;
    
    for(int i = 0; i<topping.size(); i++){
        b[topping[i]]++;
    }
    
    for(int i = 0; i<topping.size(); i++){
        a[topping[i]]++;
        b[topping[i]]--;
        
        if(b[topping[i]] == 0){
            b.erase(topping[i]);
        }
        
        if(a.size() == b.size()){
            answer++;
        }
    }
    
    return answer;
}