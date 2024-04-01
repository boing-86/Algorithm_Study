#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool sim(string a, string b){
    int count = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i] != b[i]){
            count++;
        }
    }
    if(count == 1){
        return true;
    }
    else{
        return false;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    auto tmp = find(words.begin(), words.end(), target);
    
    if(tmp == words.end()){
        return 0;
    }
    
    queue<pair<string, int>> q;
    bool visited[50] = {false, };
    q.push({begin, 0});
    
    while(!q.empty()){
        
        string a = q.front().first;
        int count = q.front().second;
        q.pop();

        for(int i = 0; i < words.size(); i++){
            if(!visited[i] && sim(a, words[i])){
                if(words[i] == target){
                    return count + 1;
                }
                visited[i] = true;
                q.push({words[i], count + 1});
            }
        }
        
        
    }
    
    return answer;
}