#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue <int> trucks;
    queue <pair<int, int>> bridge; //무게, 빠져나갈 시간
    
    for(auto a : truck_weights){
        trucks.push(a);
    }
    
    int t = 1; int i = 0;
    int now_weight = 0;
    while(!(trucks.empty() && bridge.empty())){
        while(!bridge.empty() && bridge.front().second == t){
            now_weight -= bridge.front().first;
            bridge.pop();
        }
        
        if(!trucks.empty() && now_weight + trucks.front() <= weight && bridge.size() < bridge_length){
            now_weight += trucks.front();
            bridge.push({trucks.front(), t + bridge_length});
            i++; trucks.pop();
        }
        t++;
    }
    answer = t-1;
    
    return answer;
}