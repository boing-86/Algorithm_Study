#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int count = 0;
    vector <char> s;
    
    for(auto a : number){
        s.push_back(a);
    }
    
    int front = 0;
    int rear = 1;
    
    while(count < k){
        if(s[front] < s[rear]){
            s.erase(s.begin() + front);
            count++; 
            rear = front;
            front--;
            
            while(front >= 0){
                if(s[front] < s[rear]){
                    s.erase(s.begin() + front);
                    front--; rear--;
                }
                
                else{
                    break;
                }
            }
            if(front == -1){
                front = 0;
                rear = 1;
            } else{
                front = rear;
                rear = front + 1;
            }
        }
        
        else if(s[front] > s[rear]){
            front++; rear++;
        }
        
        for(auto a : s){
            cout<<a;
        }
        cout<<endl;
    }
    
    return answer;
}