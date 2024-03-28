#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

string get_number(int n, int num){
    string a = "";
    if(num < n){
        if(num >= 10){
            a.insert(a.begin(), char(num + 55));
        }
        else{
            a.insert(a.begin(), num+'0');
        }
    }
    
    else{
        while(num >= n){
            int tmp = num % n;
            
            if(tmp >= 10){
                a.insert(a.begin(), char(tmp+55));
            }
            else{
                a.insert(a.begin(), tmp + '0');
            }
            
            num = num / n;
        }
        
        if(num >= 10){
                a.insert(a.begin(), char(num+55));
        }
        else{
            a.insert(a.begin(), num+'0');
        }
    }
    return a;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    p-=1;
    int tern = 0;
    
    while(t > answer.size()){
        string a = get_number(n, num);
        
        for(int i = 0; i<a.size(); i++){
            if(t == answer.size()){
                return answer;
            }
            if(tern == p + m*answer.size()){
                answer.push_back(a[i]);
            }
            tern++;
        }
        num++;
        cout<<endl;
    }
    
    
    return answer;
}