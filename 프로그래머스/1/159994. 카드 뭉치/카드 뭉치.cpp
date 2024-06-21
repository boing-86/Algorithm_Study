#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int i = 0;
    int j = 0;
    
    for(int k = 0; k<goal.size(); k++){
        if(i < cards1.size() && goal[k].compare(cards1[i]) == 0){
            i++;
        }
        else if(j < cards2.size() && goal[k].compare(cards2[j]) == 0){
            j++;
        }
        else{
            return "No";
        }
    }
    return "Yes";
}