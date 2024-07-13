#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	queue<pair<long long, long long>> q;

	q.push({ a, 1 });

	while (!q.empty()) {
		auto node = q.front();
		q.pop();

		if (node.first > b)
			continue;
		if (node.first == b) {
			cout << node.second;
			return 0;
		}

		q.push({ node.first * 10 + 1, node.second + 1 });
		q.push({ node.first * 2, node.second + 1 });
	}
	cout << "-1";
}