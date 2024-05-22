#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> A;
int n, k;
int answer = 0;

void merge(int p, int q, int r){
    int i = p; int j = q + 1;
    int t = 0;
    vector<int> tmp;

    while(i <= q && j <= r){
        if(A[i] <= A[j]){
            tmp.push_back(A[i++]);
        }
        else{
            tmp.push_back(A[j++]);
        }
    }

    while(i <= q){
        tmp.push_back(A[i++]);
    }

    while(j <= r){
        tmp.push_back(A[j++]);
    }

    i = p; t = 0;
    while(i <= r){
        answer++;
        if(answer == k){
            cout<<tmp[t];
        }
        A[i++] = tmp[t++];
    }
}

void merge_sort(int p, int r){

    if(p < r){
        int q = floor(float(p + r) / 2.0);
        merge_sort(p, q);
        merge_sort(q+1, r);
        merge(p, q, r);
    }
}

int main(){
    cin>>n>>k;

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        A.push_back(tmp);
    }

    merge_sort(0, n-1);

    if(answer < k){
        cout<<-1;
    }
}