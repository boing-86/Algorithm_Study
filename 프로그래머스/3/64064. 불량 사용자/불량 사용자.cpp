#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;
set <set<string>> combinations;
set <string> current_set;
vector <bool> visited(8, false);

bool is_match(const string& b, const string& u){
    if(b.size() != u.size()){
        return false;
    }

    for(int i = 0; i < b.size(); i++){
        if(b[i] == '*'){
            continue;
        }
        
        else if(b[i] != u[i]){
            return false;
        }
    }
    
    return true;
}

void find_combinations(int depth, vector<string>& user_id, vector<string>& banned_id){
    
    if(depth == banned_id.size()){
        combinations.insert(current_set);
        return ;
    }
    
    for(int i = 0; i<user_id.size(); i++){
        if(!visited[i] && is_match(banned_id[depth], user_id[i])){
            visited[i] = true;
            current_set.insert(user_id[i]);
            find_combinations(depth + 1, user_id, banned_id);
            visited[i] = false;
            current_set.erase(user_id[i]);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    find_combinations(0, user_id, banned_id);
    answer = combinations.size();
    
    return answer;
}