#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<int, vector<string>> a, pair<int, vector<string>> b){
    if(a.second[0] == b.second[0]){
        int ai = stoi(a.second[1]);
        int bi = stoi(b.second[1]);
        
        if(ai == bi){
            return a.first < b.first;
        }
        
        return ai < bi;
    }
    
    return a.second[0] < b.second[0];
}


vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    vector<pair<int, vector<string>>> file_list;
    
    int index = 0;
    
    for (auto file : files){
        bool flag = false;
        vector<string> tmp(3);
        transform(file.begin(), file.end(), file.begin(), ::tolower);
        
        for(auto a : file){
            // if(a == ' '){
            //     continue;
            // }
            if(!flag){
                if(a >= 48 && a<=57){ //숫자 들어오면
                    flag = true;
                    tmp[1].push_back(a);
                }
                
                else{
                    tmp[0].push_back(a);
                }
            }
            
            else if(flag){
                if(a >= 48 && a<=57 && tmp[1].size() < 5){
                    if(tmp[2].size() > 0){
                        tmp[2].push_back(a);
                    }
                    else{
                        tmp[1].push_back(a);
                    }
                }
                
                else {
                    tmp[2].push_back(a);
                }
            }
        }
        file_list.push_back({index, tmp});
        index++;
    }
    
    sort(file_list.begin(), file_list.end(), cmp);
    
    for(int i = 0; i< file_list.size(); i++){
        answer.push_back(files[file_list[i].first]);
        // cout<<file_list[i].second[0]<<" "<<file_list[i].second[1]<<" "<<file_list[i].second[2]<<endl;
    }
    
    return answer;
}