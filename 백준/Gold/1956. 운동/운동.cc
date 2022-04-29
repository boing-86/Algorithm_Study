#include <iostream>

using namespace std;

int inf = 123456789;
int input[401][401] = {inf, };
int v, e;

int main(){
    cin>>v>>e;

    //init
    for(int i =0; i<=v; i++){
        for(int j = 0; j<=v; j++){
            if(i == j){
                input[i][j] = 0;
            }
            else{
                input[i][j] = inf;
            }
        }
    }

    //input
    for(int i = 0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        input[a][b] = c;
    }

    //floyd-warshall
    for(int i = 1; i<=v; i++){
        for(int j = 1; j<=v; j++){
            for(int k = 1; k<=v; k++){
                input[i][j] = min(input[i][j], input[i][k] + input[k][j]);
            }
        }
    }

    int ans = inf;

    for(int i = 1; i<=v; i++){
        for(int j = 1; j<=v; j++){
            if(i==j){
                continue;
            }
            else if((input[i][j] != inf)&&input[j][i] != inf){
                ans = min(ans, input[i][j] + input[j][i]);
            }
        }
    }

    if(ans == inf){
        cout<<"-1"<<endl;
    }
    else{
        cout<<ans<<endl;
    }

    return 0;

}
