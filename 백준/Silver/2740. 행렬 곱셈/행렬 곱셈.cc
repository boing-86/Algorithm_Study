#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multi_matrices(vector<vector<int>>& A, vector<vector<int>>& B){

    int n = A.size();
    int m = A[0].size();
    int k = B[0].size();

    vector<vector<int>> result(n, vector<int>(k, 0));

    for (int i = 0; i<n; ++i){
        for (int j = 0; j<k; ++j){
            for (int k = 0; k<m; ++k){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    return result;
}


// 결과를 출력하는 함수
void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    
    int n, m, k;

    cin>>n>>m;

    vector<vector<int>> A(n, vector<int>(m));

    for (int i = 0; i<n; ++i){
        for (int j = 0; j<m; ++j){
            cin>>A[i][j];
        }
    }
    cin>>m>>k;

    vector<vector<int>> B(m, vector<int>(k));

    for (int i = 0; i<m; ++i){
        for (int j = 0; j<k; ++j){
            cin>>B[i][j];
        }
    }

    vector<vector<int>>C = multi_matrices(A, B);
    

    for (auto row : C) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

}