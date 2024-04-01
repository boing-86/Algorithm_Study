#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    vector <int> v;
    v.push_back(arr[0]);
    
    for(int i = 1; i<arr.size(); i++){
        if(v.back() == arr[i]){
            continue;
        }
        
        v.push_back(arr[i]);
    }
    
    return v;
}