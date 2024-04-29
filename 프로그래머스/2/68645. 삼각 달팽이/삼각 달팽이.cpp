#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;
int map[1001][1001];
vector<int> solution(int n) {
    vector<int> answer;
    
    int num = 1;
    int row = -1;
    int col = 0;
    
    for(int i = n; i>0; i-=3){
        for(int j = 0; j<i; j++){
            map[++row][col] = num++;
        }
        
        for(int j = 0; j<i-1; j++){
            map[row][++col] = num++;
        }
        
        for(int j = 0; j<i-2; j++){
            map[--row][--col] = num++;
        }
    }
    
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n; j++){
            if(map[i][j] != 0){
                answer.push_back(map[i][j]);
            }
        }
    }
    
    return answer;
}