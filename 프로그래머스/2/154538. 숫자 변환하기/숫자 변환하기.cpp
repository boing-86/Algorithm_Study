#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <memory.h>
#include <deque>
#include <set>
using namespace std;

int solution(int x, int y, int n) {

	int answer = 0;
	bool visited[1000001];
    
    if(x == y){
        return 0;
    }

	memset(visited, false, sizeof(false) * 1000001);
	deque <int> dq;
	dq.push_back(x);

	while (!dq.empty()) {
		answer++;
        
        set <int> s;
        for(auto iter = dq.begin(); iter != dq.end(); iter++){
            int i = *iter;
            if(i > y){
                continue;
            }
            
            s.insert(i + n);
            s.insert(i * 2);
            s.insert(i * 3);
        }
        
        if(s.find(y) != s.end()){
            return answer;
        }
        
        dq.clear();
        for(auto a : s){
            dq.push_back(a);
        }
	}

	return -1;
}