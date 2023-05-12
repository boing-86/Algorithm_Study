#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
long long *tree;
long long arr[1000001];

long long init(int node, int start, int end){
   if(start ==  end){
    return tree[node] = arr[start];
   }

   else{
    int mid = (start + end) / 2;
    return tree[node] = init(node*2, start, mid) + init(node*2+1, mid+1, end);
    }
}

long long sum(int start, int end, int node, int left, int right){
    if(left > end || right < start){
        return 0;
    }

    if(left <= start && right >= end){
        return tree[node];
    }

    int mid = (start + end)/2;

    return sum(start, mid, node*2,left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int index, long long diff, int node){
    if(index < start || index > end){
        return;
    }

    tree[node] = tree[node] + diff;
    int mid = (start + end)/2;
    if(start != end){
        update(start, mid, index, diff, node*2);
        update(mid+1, end, index, diff, node*2+1);
    }
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m, k;

    cin>>n>>m>>k;
    
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }

    int depth = (int)ceil(log2(n));
    tree = new long long[1<<(depth+1)];

    init(1, 0, n-1);


    for(int i = 0; i<m+k; i++){
        int a, b;
        long long c;
        cin>>a>>b>>c;
        if(a == 1){
            update(0, n-1, b-1,  c-arr[b-1], 1);
            arr[b-1] = c;
        }
        else if(a==2){
            cout<<sum(0, n-1, 1, b-1, c-1)<<'\n';
        }
    }

    return 0;

}