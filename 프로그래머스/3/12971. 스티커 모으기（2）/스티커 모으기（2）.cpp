#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    if(sticker.size() == 1){
        return sticker[0];
    }
    
    vector<int> dp_1(sticker.size(), 0);
    vector<int> dp_2(sticker.size(), 0);
    
    // sticker[0] 을 떼는 경우
    dp_1[0] = sticker[0];
    dp_1[1] = dp_1[0];
    for(int i = 2; i<sticker.size()-1; i++){
        dp_1[i] = max(sticker[i] + dp_1[i-2], dp_1[i-1]);
    }
    
    // sticker[0] 을 안떼고, sticker[1] 을 떼는 경우
    dp_2[0] = 0;
    dp_2[1] = sticker[1];
    dp_2[2] = max(dp_2[1], sticker[2]);
    for(int i = 3; i<sticker.size(); i++){
        dp_2[i] = max(sticker[i] + dp_2[i-2], dp_2[i-1]);
    }
    
    answer = max(dp_1[sticker.size() - 2], dp_2[sticker.size()-1]);
    

    return answer;
}