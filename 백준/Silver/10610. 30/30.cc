#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
#include <sstream>
using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string num;
    cin>>num;
    bool flag = false;
    int sum = 0;

    for(int i = 0; i<num.size(); i++){
        int tmp = num[i] - '0';
        v.push_back(tmp);
        //cout<<tmp<<" ";
        sum += tmp;

        if(tmp == 0){
            flag = true;
        }
    }

    if(!flag || (sum % 3 != 0)){
        cout<<-1;
        return 0;
    }

    sort(v.rbegin(), v.rend());
    for(auto a : v){
        cout<<a;
    }

    return 0;
}