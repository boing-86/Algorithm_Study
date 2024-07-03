#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> postorder;
vector<int> inorder;


void recursive(int instart, int inend, int poststart, int postend){

    if(instart > inend || poststart > postend){
        return ;
    }
    
    int root = postorder[postend];
    int rootindex = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    int left_size = rootindex - instart;
    int right_size = inend - rootindex;

    cout<<root<<" ";

    recursive(instart, rootindex-1, poststart, poststart+left_size-1);
    recursive(rootindex+1, inend, poststart+left_size, postend - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        inorder.push_back(tmp);
    }

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        postorder.push_back(tmp);
    }

    recursive(0, n-1, 0, n-1);


}