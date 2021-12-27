#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int testcase = commands.size();
    int k = 0;
    while(k<testcase){
        vector<int> arr;
        
        for(int i = commands[k][0]-1; i<commands[k][1]; i++){
            arr.push_back(array[i]);
        }
        
        sort(arr.begin(), arr.end());
        int page = commands[k][2]-1;
        answer.push_back(arr[page]);
        k++;
    }
    return answer;
}
