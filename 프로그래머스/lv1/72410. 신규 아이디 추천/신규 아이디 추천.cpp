#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string test = "";

    int i = 0;
    for(i = 0; i<new_id.length(); i++){
        if(new_id[i] >= 'A' && new_id[i]<='Z'){
            new_id[i] = tolower(new_id[i]);
        }
    }


    for(i = 0; i<new_id.length(); i++){
        if(((new_id[i]>='a') && (new_id[i]<='z')) || ((new_id[i]>='0') && (new_id[i]<='9')) || (new_id[i] == '-') || (new_id[i] == '_') || (new_id[i] == '.')){
            test.push_back(new_id[i]);
        }
    }

    
    i = 0;
    while(i<test.length()){
        if(test[i] == '.' && test[i-1] == '.'){
            test.erase(test.begin()+i-1);
        }
        else{
            i++;
        }
    }



    if(test[0] == '.'){
        test.erase(test.begin());
    }

    if(test[test.length()-1] == '.'){
        test.erase(test.begin() + test.length()-1);
    }


    if(test.empty()){
        test = "a";
    }


    if(test.length() >= 16){
        test.erase(test.begin()+15, test.end());

        if(test[14] == '.'){
            test.erase(test.begin()+14);
        }
    }


    if(test.length() <= 2){
        char last_c = test[test.length()-1];
        while(test.length()<3){
            test.push_back(last_c);
        }
    }
    
    answer = test;
    
    return answer;
}