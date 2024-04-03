#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
bool visited_v[11][11];
bool visited_h[11][11];
int dir_x[] = {0, 0, 1, -1}; // U D R L
int dir_y[] = {1, -1, 0, 0};

int solution(string dirs) {
    int answer = 0;
    
    int x = 5; int y = 5;
    for(auto a : dirs){
        switch(a){
            case 'U' :
                if(y >= 10){
                    continue;
                }
                y++;
                if(!visited_v[x][y]){
                    visited_v[x][y] = true;
                    answer++;
                }
                break;
                
            case 'D' :
                if(y <= 0){
                    continue;
                }
                if(!visited_v[x][y]){
                    visited_v[x][y] = true;
                    answer++;
                }
                y--;
                break;
            case 'R' :
                if(x >= 10){
                    continue;
                }
                x++;
                if(!visited_h[x][y]){
                    visited_h[x][y] = true;
                    answer++;
                }
                break;
            case 'L' :
                if(x <= 0){
                    continue;
                }
                if(!visited_h[x][y]){
                    visited_h[x][y] = true;
                    answer++;
                }
                x--;
                break;
        }
    }
    return answer;
}