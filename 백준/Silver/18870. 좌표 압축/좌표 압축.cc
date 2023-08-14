#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {

    int n;
    int tmp;
    cin>>n;
    std::vector<int> coordsToCompress;
    for(int i =0; i<n; i++){
        cin >> tmp;
        coordsToCompress.push_back(tmp);
    }

    std::set<int> sortedCoordsSet(coordsToCompress.begin(), coordsToCompress.end());
    std::vector<int> sortedCoords(sortedCoordsSet.begin(), sortedCoordsSet.end());

    for (auto coord : coordsToCompress) {
       cout << lower_bound(sortedCoords.begin(), sortedCoords.end(), coord) - sortedCoords.begin() << ' ';
    }

    return 0;
}




