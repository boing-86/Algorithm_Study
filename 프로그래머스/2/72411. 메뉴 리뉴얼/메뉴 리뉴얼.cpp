#include <iostream>
#include <algorithm>
#include <set>
#include <regex>
#include <string>
#include <vector>

using namespace std;
vector <char> menu;
set <string> answer;
vector <string> order_list;
bool visited[11];


void recursive(string s, int course_size, int depth){
    if(depth > course_size){
        return ;
    }
    
    if(depth == course_size){
        int count = 0;
        regex e(s);
        smatch match;
        
        for(auto order : order_list){
            if(regex_search(order, match, e)){
                count++;
            }
            
        }
        
    }
    
    for(int i = 0; i < menu.size(); i++){
        if(visited[i] == false){
            visited[i] = true;
            s.push_back(menu[i]);
            s.push_back('*');
            recursive(s, course_size, depth+1);
            visited[i]=false;
        }
    }
}

set<string> solution(vector<string> orders, vector<int> course) {
    set <char> menues;
    
    sort(orders.begin(), orders.end());
    for(auto a : orders){
        sort(a.begin(), a.end());
        order_list.push_back(a);
        
        for(int i = 0; i<a.size(); i++){
            menues.insert(a[i]);
        }
            
    }
    
    for(auto i = menues.begin(); i != menues.end(); i++){
        menu.push_back(*i);
    }
    
    for(auto a : course){
        recursive("*", a, 0);
    }
    
    
    return answer;
}