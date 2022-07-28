#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int i = 0;
    int j = 0;

    for(i = 0; i<arr1.size(); i++){
        vector<int> rows;
        for(j = 0; j<arr1[0].size(); j++){
            rows.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(rows);
    }
    
    return answer;
}