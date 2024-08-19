#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin>>n;

    vector<int> v(n, 0);

    for(int i = 0; i<n; i++){
        cin>>v[i];
    }

    if(n == 2){
        cout<<v[0]<<" "<<v[1]<<endl;
        return 0;
    }

    int i = 0, j = n-1;
    int min_i = 0, min_j = 0;
    int min_diff = 2000000000;

    while(i < j){
        int tmp_diff = v[i] + v[j];
        
        // cout<<tmp_diff<<" : "<<v[i]<<" , "<<v[j]<<endl;

        if(abs(tmp_diff) < min_diff){
            // cout<<"####### "<<tmp_diff<<" : "<<v[i]<<" , "<<v[j]<<endl;
            min_diff = abs(tmp_diff);
            min_i = v[i]; min_j = v[j];

            if(tmp_diff == 0){
                break;
            }
        }
    
        if(tmp_diff < 0){
            i++;
        }

        else if(tmp_diff > 0){
            j--;
        }
    }

    cout<<min_i<<" "<<min_j;
}