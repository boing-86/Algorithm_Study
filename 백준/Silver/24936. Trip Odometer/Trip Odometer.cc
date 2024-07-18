#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main(){
    
    int n;
    vector<int> v;
    stack<int> answer;
    int sum = 0;

    cin>>n;
    int answer_number = n;
    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
        sum+=tmp;
    }

    sort(v.begin(), v.end());

    answer.push(sum-v[0]);

    for(int i = 1; i<n; i++){
        if(v[i] == v[i-1]){
            answer_number--;
            continue;
        }

        answer.push(sum - v[i]);
    }

    cout<<answer_number<<"\n";
    while(!answer.empty()){
        cout<<answer.top()<<" ";
        answer.pop();
    }
}