#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size() == 1){
        answer.push_back(-1);
        return answer;
    }
    
    vector<int> v = arr;
    sort(v.begin(), v.end());
    arr.erase(find(arr.begin(), arr.end(), v[0]));
    
    return arr;
}