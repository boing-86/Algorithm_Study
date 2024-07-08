#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct compare{
    bool operator() (const int a, const int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main(){
    
    int n;
    priority_queue <int, vector<int>, compare> pq;

    cin>>n;

    while(n--){
        int x;
        cin>>x;

        if(x == 0){
            if(pq.empty()){
                cout<<0<<"\n";
            }

            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }

        else{
            pq.push(x);
            
        }
    }
}