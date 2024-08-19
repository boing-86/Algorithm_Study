#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;

	cin >> t;

	while(t--){
		int cnt = 0;
		int n, m;
		cin >> n >> m;
		vector <int> A(n);
		vector <int> B(m);

		for (int j = 0; j < n; j++) {
			cin >> A[j];
		}

		for (int k = 0; k < m; k++) {
			cin >> B[k];
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());


		for (int i = 0; i < A.size(); i++) {
			for (int j = 0; j < B.size(); j++) {
				if (A[i] > B[j]) {
					cnt++;
				}
				else {
					break;
				}
			}
		}

		cout << cnt << endl;
	}

}