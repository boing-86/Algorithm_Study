#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int i = 0;
    int j = 0;
    int sum = sequence[i];
    
    while(i < sequence.size() && j < sequence.size()){
        if(sum == k){
            if(answer.size() == 0){
                answer.push_back(i);
                answer.push_back(j);
            }
            
            else{
                int t1 = answer[1] - answer[0];
                int t2 = j-i;
                if(t1 > t2){
                    answer[0] = i;
                    answer[1] = j;
                }
            }
            sum -= sequence[i];
            i++; j++;
            sum += sequence[j];
        }
        
        else if(sum < k){
            sum += sequence[++j];
        }
        
        else{ // sum > k
            sum -= sequence[i++];
        }
    }
    
    return answer;
}