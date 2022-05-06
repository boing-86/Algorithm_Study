#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

deque <char> dq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num;
	int n, k;

	cin >> n>>k;
	cin >> num;

	for (int i = 0; i < n; i++) {
		while (k > 0 && !dq.empty() && dq.back() < num[i]) {
			dq.pop_back();
			k--;
		}
		dq.push_back(num[i]);
	}

	for (int i = 0; i < dq.size()-k; i++) {
		cout << dq[i];
	}
}

//틀린이유 : 순서 바꾸면 안됨
//ex : 1492 -> 49