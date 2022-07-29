#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> arr;
    int i = 0;

    for(i = 0; i<operations.size(); i++){
        if(operations[i][0] == 'I'){
            string tmp = operations[i];
            tmp.erase(tmp.begin());
            tmp.erase(tmp.begin());
            int pnum = stoi(tmp);
            arr.push_back(pnum);
        }

        else if(operations[i] == "D 1"){
            if(arr.empty()){
                continue;
            }
            arr.erase(max_element(arr.begin(), arr.end()));
        }

        else if(operations[i] == "D -1"){
            if(arr.empty()){
                continue;
            }
            arr.erase(min_element(arr.begin(), arr.end()));
        }
    }

    if(arr.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(*max_element(arr.begin(), arr.end()));
        answer.push_back(*min_element(arr.begin(), arr.end()));
    }
    
    return answer;
}