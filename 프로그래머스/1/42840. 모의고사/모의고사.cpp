#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> answer;
    vector<pair<int, int>> v = {{1, 0}, {2, 0}, {3, 0}};
    
    int way2[] = {2, 1, 2, 3, 2, 4, 2, 5}; //8
    int way3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; //10
    
    
    for(int i = 0; i<answers.size(); i++){
        
        int a = (i%5)+1;
        int b = way2[(i%8)];
        int c = way3[(i%10)];
        
        if(answers[i] == a){
            v[0].second++;
        }
        if(answers[i] == b){
            v[1].second++;
        }
        if(answers[i] == c){
            v[2].second++;
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    if(v[0].second == v[1].second){
        answer.push_back(v[0].first);
        answer.push_back(v[1].first);
        
        if(v[1].second == v[2].second){
            answer.push_back(v[2].first);
        }
    }
    
    else{
        answer.push_back(v[0].first);
    }
    
    return answer;
}