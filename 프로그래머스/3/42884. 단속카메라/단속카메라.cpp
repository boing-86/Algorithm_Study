#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = routes.size();
    
    sort(routes.begin(), routes.end(), cmp);
    
    int j = 1;
    for(int i = 0; i<routes.size(); i++){
        if(routes[i][1] >= routes[j][0]){
            answer--;
            if(j == routes.size()-1){
                break;
            }
            j++; i--;
        }
        else{
            i = j-1;
            if(j == routes.size()-1){
                break;
            }
            j++;
        }
    }
    
    return answer;
}