#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool cmp(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b){
    if(a.first == b.first){
        if(a.second.second == b.second.second){
            return a.second.first < b.second.first;
        }
        
        return a.second.second > b.second.second;
    }
    
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map <string, int> genre_map;
    
    for(int i = 0; i<genres.size(); i++){
        if(genre_map.find(genres[i]) == genre_map.end()){
            genre_map.insert({genres[i], plays[i]});
        }
        else{
            genre_map[genres[i]] += plays[i];
        }
    }
    
    vector<pair<int, pair<int, int>>> playlist;
    
    for(int i = 0; i < plays.size(); i++){
        playlist.push_back({genre_map[genres[i]], {i, plays[i]}});
    }
    
    sort(playlist.begin(), playlist.end(), cmp);
    
    // for(auto a : playlist){
    //     cout<<a.first<<" : "<<a.second.first<<" "<<a.second.second<<endl;
    // }
    
    answer.push_back(playlist[0].second.first);
    int count = 1;
    
    for(int i = 1; i<playlist.size(); i++){
        
        if(playlist[i-1].first != playlist[i].first){
            count = 1;
            //cout<<playlist[i].first<<" : "<<playlist[i].second.first<<" ";
            answer.push_back(playlist[i].second.first);
        }
        
        else{
            if(++count <= 2){
                answer.push_back(playlist[i].second.first);
                //cout<<playlist[i].second.first<<endl;
            }
        }
    }
    
    return answer;
}