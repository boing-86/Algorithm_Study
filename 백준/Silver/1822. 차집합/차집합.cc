#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int na, nb;

    cin>>na>>nb;

    map<int, int> map;

    for(int i = 0; i<na; i++){
        int tmp;
        cin>>tmp;
        map.insert({tmp, 1});
    }

    for(int i = 0; i<nb; i++){
        int tmp;
        cin>>tmp;
        if(map.find(tmp) != map.end()){
            map.erase(tmp);
        }
    }

    cout<<map.size()<<"\n";
    for(auto iter = map.begin(); iter != map.end(); iter++){
        cout<<iter->first<<" ";
    }

}