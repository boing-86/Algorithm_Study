#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i<arr1.size(); i++){
        bitset <16> m1(arr1[i]);
        bitset <16> m2(arr2[i]);
        string result = "";
        
        string tmp = (m1 | m2).to_string();
        
        for(int j = 16-n; j<16; j++){
            if(tmp[j] == '1'){
                result.push_back('#');
            }
            else{
                result.push_back(' ');
            }
        }
        
        answer.push_back(result);
    }
    
    
    return answer;
}