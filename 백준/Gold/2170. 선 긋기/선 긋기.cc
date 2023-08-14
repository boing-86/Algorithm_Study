#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;

    vector< pair<int, int>> lines(n);
    for (auto& line : lines) {
         cin >> line.first >> line.second;
    }

     sort(lines.begin(), lines.end());

    int totalLength = 0;
    int currentStart = lines[0].first;
    int currentEnd = lines[0].second;

    for (int i = 1; i < n; ++i) {
        if (lines[i].first > currentEnd) {
            totalLength += currentEnd - currentStart;
            currentStart = lines[i].first;
            currentEnd = lines[i].second;
        } else {
            currentEnd =  max(currentEnd, lines[i].second);
        }
    }

    totalLength += currentEnd - currentStart;

     cout << totalLength;

    return 0;
}
