#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> arr;
    int i = 0;

    for(auto iter : operations){
        if(iter[0] == 'I'){
            string tmp = iter;
            int pnum = stoi(tmp.substr(2, tmp.length()-2));
            arr.push_back(pnum);
        }

        else if(iter == "D 1" && !arr.empty()){
            arr.erase(max_element(arr.begin(), arr.end()));
        }

        else if(!arr.empty()){
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