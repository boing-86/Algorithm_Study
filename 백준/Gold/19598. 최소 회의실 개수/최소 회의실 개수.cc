#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> v;
priority_queue <int, vector<int>, greater<int>> pq;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>n;
    for(int i = 0; i<n; i++){
        int s, f;
        cin>>s>>f;
        v.push_back({s, f});
    }

    sort(v.begin(), v.end());
    pq.push(v[0].second);
    int result = 1;

    for(int i = 1; i<v.size(); i++){
        while(!pq.empty()){
            if(pq.top() <= v[i].first){
                pq.pop();
            }
            else{
                break;
            }
        }
        pq.push(v[i].second);
        result = max(result, (int)pq.size());
    }

    cout<<result;

}