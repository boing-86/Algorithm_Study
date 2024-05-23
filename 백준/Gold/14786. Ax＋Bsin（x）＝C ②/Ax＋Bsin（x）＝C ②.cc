#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
#include <sstream>
using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    double a, b, c;
    double x = 0;
    double dx;

    cin>>a>>b>>c;

    while(fabs(a * x + b * sin(x) - c) > 0.000000001){
        dx = x - (a * x + b * sin(x) - c) / (a + b * cos(x));
        x = dx;
    }

    cout<<fixed;
    cout.precision(9);
    cout<<x;


    return 0;
}