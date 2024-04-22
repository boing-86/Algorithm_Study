#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> records) {
    vector<string> answer;
    vector<pair<char, string>> iom;
    map<string, string> idname;
    
    for(auto a : records){
        istringstream ss(a);
        string buffer;
        vector <string> record;
        
        while(getline(ss, buffer, ' ')){
            record.push_back(buffer);
        }
        
        switch(record[0][0]){
            case 'E' :
                iom.push_back({'E', record[1]});
                
                if(idname.find(record[1]) != idname.end()){
                    idname[record[1]] = record[2];
                }
                else{
                    idname.insert({record[1], record[2]});
                }
                break;
            
            case 'L' :
                iom.push_back({'L', record[1]});
                break;
                
            case 'C' :
                idname[record[1]] = record[2];
                break;
        }
    }
    
    for(auto a : iom){
        string cmd = "";
        cmd.append(idname[a.second]);

        switch(a.first){
            case 'E' :
                cmd.append("님이 들어왔습니다.");
                break;
            
            case 'L' :
                cmd.append("님이 나갔습니다.");
                break;
        }
        answer.push_back(cmd);
    }

    return answer;
}