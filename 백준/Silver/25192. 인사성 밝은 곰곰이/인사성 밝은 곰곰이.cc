#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    map<string, int> map;
    int result = 0;

    while(n--){
        string tmp;
        cin>>tmp;

        if(tmp == "ENTER"){
            result += map.size();
            map.clear();
        }

        else{
            if(map.find(tmp) == map.end()){
                map.insert({tmp, 1});
            }

            else{
                map[tmp]++;
            }
        }
    }

    cout<<result + map.size();

}