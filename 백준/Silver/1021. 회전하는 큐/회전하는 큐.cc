#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector <int> dq;

    for(int i = 1; i<=n; i++){
        dq.push_back(i);
    }

    int answer = 0;

    while(m--){
        int num;
        cin>>num;
        
        if(num == *dq.begin()){
            dq.erase(dq.begin());
            continue;
        }

        int rear = 0;
        while(num != *dq.begin()){
            dq.push_back(*dq.begin());
            dq.erase(dq.begin());
            rear++;
        }

        answer += min(rear, (int)fabs(dq.size() - rear));
        dq.erase(dq.begin());
    }

    cout<<answer;

    return 0;
}