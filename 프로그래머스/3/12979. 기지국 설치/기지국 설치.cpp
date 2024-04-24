#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int range = w * 2 + 1;
    
    vector<int> start_idx;
    vector<int> fin_idx;
    start_idx.push_back(1);
    for(int i = 0; i<stations.size(); i++){
        start_idx.push_back(min(stations[i] + w + 1, n+1));
        fin_idx.push_back(max(0, stations[i] - w));
    }
    fin_idx.push_back(n+1);
    
    
    for(int i = 0; i<start_idx.size(); i++){
        
        int target = fin_idx[i] - start_idx[i];
        if(target <= 0){
            continue;
        }
        // cout<<start_idx[i]<<" "<<fin_idx[i]<<endl;
        answer = answer + target / range;
        if((target % range) != 0){
            answer++;
        }
    }

    return answer;
}