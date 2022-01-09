#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// A를 재배열한 결과는 물어보지 않고 S의 최솟값만 구하면 되기 때문에
	// 사실상 A와 B를 모두 정렬해도 상관없다. 

	int n;
	cin >> n;

	vector<int> a, b;
	int num;

	// 배열 a, b의 초기화
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		b.push_back(num);
	}

	// a는 내림차순, b는 오름차순으로 정렬
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());

	int result = 0;
	for (int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}
	cout << result << "\n";

	return 0;
}