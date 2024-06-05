#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
using namespace std;

bool is_braket(char c){
    return (c == '(' || c == ')' || c == '[' || c == ']' );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true){
        string str;
        getline(cin, str);
        deque<char> dq;
        bool flag = true;
       
        if(str == "."){
            break;
        }

        if(str.empty()){
            continue;
        }

        //cout<<str<<endl;
        for(int i = 0; i<str.size(); i++){
            char s = str[i];
            if(s == '(' || s == '['){
                dq.push_back(s);
            }

            if((s == ')' || s == ']')){
                if(dq.empty()){
                    flag = false;
                    break;
                }

                else{
                    if(s == ')' && dq.back() == '('){
                        dq.pop_back();
                    }

                    else if(s == ']' && dq.back() == '['){
                        dq.pop_back();
                    }

                    else{
                        dq.push_back(s);
                        flag = false;
                    }
                }
            }

            // for(auto iter = dq.begin(); iter != dq.end(); iter++){
            //     cout<<*iter<<" ";
            // }
            // cout<<endl;

        }

        if(dq.empty() && flag){
            cout<<"yes\n";   
        }    
        else{
            cout<<"no\n";
        }
    }


    return 0;
}