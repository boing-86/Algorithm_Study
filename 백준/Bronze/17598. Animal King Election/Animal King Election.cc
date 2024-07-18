#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    
    map<string,int> v;

    v.insert({"Lion", 0});
    v.insert({"Tiger", 0});

    for(int i = 0; i<9; i++){
        string tmp;
        cin>>tmp;

        v[tmp]++;
    }

    if(v["Lion"] > v["Tiger"]){
        cout<<"Lion";
    } else{
        cout<<"Tiger";
    }

}