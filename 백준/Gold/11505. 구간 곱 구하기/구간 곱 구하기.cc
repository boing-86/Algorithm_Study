#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

long long tree[4000001];
long long arr[1000001];

void init(int n, int start, int end){
    if(start == end){
        tree[n] = arr[start];
    }

    else{
        int m = (start + end) / 2;
        init(n*2, start, m);
        init(n*2+1, m+1, end);
        tree[n] = tree[n*2] * tree[n*2+1] % 1000000007;
    }
}

void update(int i, long long x, int n, int start, int end){
    
    if(i < start || end < i ){
        return ;
    }

    if(start == end){
        tree[n] = x;
        return ;
    }

    int m = (start + end) / 2;
    update(i, x, 2*n, start, m);
    update(i, x, 2*n+1, m+1, end);
    tree[n] = tree[n*2] * tree[n*2+1]% 1000000007;
}

long long query(int qs, int qe, int n, int start, int end){
    if(qe < start || end < qs){
        return 1;
    }

    if(qs <= start && end <= qe){
        return tree[n];
    }

    int m = (start + end) / 2;
    long long lval = query(qs, qe, n * 2, start, m);
    long long rval = query(qs, qe, n * 2 + 1, m+1, end);

    return lval * rval % 1000000007;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    init(1, 0, n-1);

    for(int i = 0; i<m+k; i++){
        int a;
        long long b, c;
        cin>>a>>b>>c;

        if(a == 1){
            update(b-1, c, 1, 0, n-1);
        }

        if(a == 2){
            cout<<query(b-1, c-1, 1, 0, n-1)<<"\n";

        }
    }

    return 0;
}
