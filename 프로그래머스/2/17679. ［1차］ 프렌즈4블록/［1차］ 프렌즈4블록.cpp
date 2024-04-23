#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    pair<char, int> map[31][31];
    set <int> result;
    
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            map[i][j] = {board[i][j], i*board[i].size() + j};
            cout<<map[i][j].second<<" ";
        }
        cout<<endl;
    }
    
    while(true) {
        bool flag = false;
        for(int i = 0; i < m-1; i++){
            for(int j = 0; j<n-1; j++){
                vector <char> v = {map[i][j].first, map[i+1][j].first, map[i][j+1].first, map[i+1][j+1].first};

                if(equal(v.begin()+1, v.end(), v.begin()) && find(v.begin(), v.end(), ' ') == v.end()){
                    flag = true;
                    result.insert(map[i][j].second);
                    result.insert(map[i+1][j].second);
                    result.insert(map[i][j+1].second);
                    result.insert(map[i+1][j+1].second);

                }
            }
        }
        if(!flag){
            break;
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(result.find(map[i][j].second) != result.end()){
                    map[i][j] = {' ', -1};
                }
                
            }
        }
        
        for(int i = m-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int floor = i;
                while(map[floor+1][j].first == ' ' && map[floor][j].first != ' '){
                    map[floor+1][j] = {map[floor][j].first, map[floor][j].second};
                    map[floor][j] = {' ', -1};
                    floor++;
                    
                    if(floor >= m){
                        break;
                    }
                }
                
            }
        }
        
        // for(int i = 0; i<board.size(); i++){
        //     for(int j = 0; j<board[i].size(); j++){
        //         cout<<map[i][j].first<<" ";
        //     }
        // cout<<endl;
        // }
        // cout<<"---------\n";
        
    }

    answer = result.size();
    return answer;
}