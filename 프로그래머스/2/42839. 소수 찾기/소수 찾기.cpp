#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

set <int> nums;
string number;
bool visited[10];

void recursive(string s){
    if(s.size() == number.size()){
        return ;
    }
    
    for(int i = 0; i<number.size(); i++){
        if(visited[i] == true){
            continue;
        }
        
        visited[i] = true;
        s.push_back(number[i]);
        long long tmp = stoll(s);
        nums.insert(tmp);
        recursive(s);
        
        s.pop_back();
        visited[i] = false;
    }
}

int count_primes(){
    int count = 0;
    
    for(auto n : nums){
        if(n < 2){
            continue;
        }
        
        bool flag = true;
        for(int i = 2; i<=sqrt(n); i++){
            if(n % i == 0){
                flag = false;
                break;
            }
        }

        if(flag){
            // cout<<n<<" ";
            count++;
        }
    }
    return count;
}

int solution(string numbers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int answer = 0;
    number = numbers;
    recursive("");
    
    answer = count_primes();
    
    return answer;
}