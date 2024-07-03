#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n;
vector<int> preorder;
vector<int> inorder;


void recursive(int pre_start, int pre_end, int in_start, int in_end){

    if(pre_start > pre_end || in_start > in_end){
        return;
    }



    int root = preorder[pre_start];
    int root_index = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    int left_size = root_index - in_start;
    int right_size = in_end - root_index;


    recursive(pre_start + 1, pre_start + left_size, in_start, root_index- 1);
    recursive(pre_start + left_size + 1, pre_end, root_index+1, in_end);

    cout<<root<<" ";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>t;

    while(t--){

        preorder.clear();
        inorder.clear();

        cin>>n;
        for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        preorder.push_back(tmp);
        }

        for(int i = 0; i<n; i++){
            int tmp;
            cin>>tmp;
            inorder.push_back(tmp);
        }

        recursive(0, n-1, 0, n-1);
        cout<<"\n";
    }

}