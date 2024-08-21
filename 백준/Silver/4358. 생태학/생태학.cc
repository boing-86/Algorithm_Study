#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<string, float> map;
    string tmp;
    float count = 0;

    while(getline(cin, tmp)){
        count++;

        if(tmp.empty()){
            break;
        }

        if(map.find(tmp) == map.end()){
            map.insert({tmp, 1});
        }

        else{
            map[tmp]++;
        }

    }
    cout<<fixed;
    cout.precision(4);

    for(auto iter = map.begin(); iter != map.end(); iter++){
        float ratio = (iter->second/count)*100;
        cout<<iter->first<<" "<<ratio<<"\n";
    }

}