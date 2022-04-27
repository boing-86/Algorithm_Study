#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, num, mmin;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    //입력
	cin >> n; //팀의 개수
	vector<int>v;
	for (int i = 0; i < 2*n; i++) { //학생 수는 팀 개수*2
		cin >> a;
		v.push_back(a);
	}
    
    //문제 해결
	sort(v.begin(), v.end()); //정렬

	mmin = 1e9;
	for (int i = 0; i < n; i++) {
    	//양쪽 끝에서 같은 위치에 있는 값을 더함 (같은 팀)
		num = v[i] + v[2 * n - i - 1]; 
		mmin = min(mmin, num); //최소값 계산
	}

	//결과 출력
	cout << mmin << '\n';	
}