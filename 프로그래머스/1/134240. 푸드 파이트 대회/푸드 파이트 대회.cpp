#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    deque <int> q;
    deque <int> st;
    
    for(int i = 1; i<food.size(); i++){
        int iter = food[i] / 2;
        
        for(int j = 0; j < iter; j++){
            q.push_back(i);
            st.push_front(i);
        }
    }
    
    q.push_back(0);
    
    for(int a : q){
        answer.push_back(a + '0');
    }
    
    for(int a : st){
        answer.push_back(a + '0');
    }
    
    return answer;
}