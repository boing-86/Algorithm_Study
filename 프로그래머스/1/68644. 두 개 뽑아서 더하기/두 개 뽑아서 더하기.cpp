#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set <int> result;
    
    sort(numbers.begin(), numbers.end());
    
    for(int i = 0; i<numbers.size()-1; i++){
        for(int j = i+1; j<numbers.size(); j++){
            result.insert(numbers[i]+numbers[j]);
        }
    }
    cout<<endl;
    for(auto i = result.begin(); i != result.end(); i++){
        answer.push_back(*i);
    }
    
    return answer;
}