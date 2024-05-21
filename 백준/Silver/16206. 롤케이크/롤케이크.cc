#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){

    int n, m;
    vector<int> v1;
    vector<int> v2;
    int result = 0;
    cin >> n >> m;

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;

        if(tmp < 10){
            continue;
        }

        else if(tmp == 10){
            result++;
        }

        else if(tmp % 10 == 0){
            v1.push_back(tmp);
        }

        else{
            v2.push_back(tmp);
        }
    }

    sort(v1.begin(), v1.end()); 
	sort(v2.begin(), v2.end()); 

    queue<int> q;

    for(auto a : v1){
        q.push(a);
    }

    for(auto a : v2){
        q.push(a);
    }

    while(!q.empty() && m > 0){
        int tmp = q.front();
        q.pop();
        
        int count = tmp / 10;
        if(tmp % 10 == 0){
            if(count-1 <= m){
                result += count;
                m -= --count;
            }
            else{
                result += m;
                break;
            }
        }

        else{
            if(count <= m){
                result += count;
                m -= count;
            }
            else{
                result += m;
                break;
            }
        }
    }

    cout<<result<<"\n";

    return 0;
}