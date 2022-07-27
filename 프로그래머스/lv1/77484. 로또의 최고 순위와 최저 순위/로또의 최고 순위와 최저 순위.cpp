#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int i = 0, j=0;
    int zcount=0, count = 0;

    while(i<lottos.size() && j<win_nums.size()){
        if(lottos[i] == 0){
            zcount++;
            i++;
        }
        else{
            if(lottos[i] == win_nums[j]){
                count++;
                i++;
                j++;
            }
            else if(lottos[i]>win_nums[j]){
                j++;
            }
            else{
                i++;
            }
        }
    }
    
    if(zcount+count < 2){
        answer.push_back(6);
    }
    else{
        answer.push_back(7-zcount-count);
    }
    
    if(count < 2){
        answer.push_back(6);
    }
    else{
        answer.push_back(7-count);
    }
    
    return answer;
}