#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
using namespace std;

struct Log{
    int id;
    int score;
    int count;
    int time;
};

bool compare(Log& a, Log& b){
    if(a.score == b.score){
        if(a.count == b.count){
            return a.time < b.time;
        }

        return a.count < b.count;
    }

    return a.score > b.score;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    int n, k, idt, m;

    cin>>t;

    while(t--){
        cin>>n>>k>>idt>>m;

        map<int, int> s_count; //id, count
        map<int, int> score; //id, score
        map<int, int> s_time; //id, time;
        int scores[10001][101] = {0, };

        vector<Log> v;

        for(int i = 0; i<m; i++){
            int id, j, s;
            cin>>id>>j>>s;

            auto iter = s_count.find(id);

            if(iter == s_count.end()){
                // cout<<"new!"<<endl;
                s_count.insert({id, 1});
                score.insert({id, s});
                scores[id][j] = s;
                s_time.insert({id, i+1});
            }

            else{
                s_count[id]++;
                s_time[id] = i+1;

                if(scores[id][j] < s){
                    score[id] -= scores[id][j];
                    scores[id][j] = s;
                    score[id] += s;
                }
            }
            
        }

        for(int i = 1; i <= n; i++){
            Log tmp;
            tmp.id = i;
            tmp.score = score[i];
            tmp.count = s_count[i];
            tmp.time = s_time[i];
            v.push_back(tmp);
        }

        // for(auto a : v){
        //     cout<<a.id<<" "<<a.score<<" "<<a.count<<" "<<a.time<<endl;
        // }

        sort(v.begin(), v.end(), compare);

        int answer = 0;
        for(int i = 0; i<v.size(); i++){
            if(v[i].id == idt){
                answer = i+1;
                break;
            }
        }

        cout<<answer<<"\n";
    }

}