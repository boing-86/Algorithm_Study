#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = yellow + brown;

    int i = 1;
    while(1){
        int j = 1;
        while( i >= j){

            if(i*j == yellow){
                if((i+2)*(j+2) == total){
                    answer.push_back(i+2);
                    answer.push_back(j+2);
                    return answer;
                }
            } j++;
        }
        i++;
    }
}