#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a, b;
    cin>>a>>b;

    int x, y, z;
    x = b / 100;
    y = (b % 100) / 10;
    z = b % 10;

    cout<<a*z<<"\n"<<a*y<<"\n"<<a*x<<"\n"<<a*b;
}