#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

bool cmp(string a, string b){
    istringstream ssa(a);
    istringstream ssb(b);
    
    vector<string> v_a;
    vector<string> v_b;
    string num1;
    while(ssa >> num1){
        v_a.push_back(num1);
    }
    while(ssb >> num1){
        v_b.push_back(num1);
    }
    
    if(v_a[1] == v_b[1]){
        return v_a[0] < v_b[0];
    }
    
    return v_a[1] < v_b[1];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> map;
    
    sort(records.begin(), records.end(), cmp);
    
    for(int i = 0; i<records.size();){
        int out_time = 0;
        int in_time = 0;
        istringstream ssa(records[i]);
        vector<string> v_a;
        string num1;
        
        if(i == records.size()-1){
            while(ssa >> num1){
                v_a.push_back(num1);
            }
            
            if(v_a[2] == "IN"){
                string a_h = v_a[0].substr(0, 2);
                string a_m = v_a[0].substr(3, 2);
                in_time = stoi(a_h) * 60 + stoi(a_m);
                out_time = 23 * 60 + 59;
                i++;
            }
        }
        
        else{
            vector<string> v_b;
            istringstream ssb(records[i+1]);
            while(ssa >> num1){
                v_a.push_back(num1);
            }
            while(ssb >> num1){
                v_b.push_back(num1);
            }

            if(v_a[2] != v_b[2]){ //출차O
                string a_h = v_a[0].substr(0, 2);
                string b_h = v_b[0].substr(0, 2);
                string a_m = v_a[0].substr(3, 2);
                string b_m = v_b[0].substr(3, 2);

                in_time = stoi(a_h) * 60 + stoi(a_m);
                out_time = stoi(b_h) * 60 + stoi(b_m);
                i = i+2;
            }

            else{
                string a_h = v_a[0].substr(0, 2);
                string a_m = v_a[0].substr(3, 2);
                in_time = stoi(a_h) * 60 + stoi(a_m);
                out_time = 23 * 60 + 59;
                i++;
            }   
        }
        
        int gap = out_time - in_time;
        
        if(map.find(v_a[1]) != map.end()){
            map[v_a[1]] += gap;
        }
        else{
            map.insert({v_a[1], gap});
        }
        
        
    }
    
    for(auto a : map){
        int fee = fees[1];
        
        if(a.second >= fees[0]){
            fee = fee + ceil((float)(a.second - fees[0]) / (float)fees[2]) * fees[3];
        }
        answer.push_back(fee);
    }
    

    
    return answer;
}