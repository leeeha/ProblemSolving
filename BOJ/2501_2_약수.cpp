#include<iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int cnt = 0; // k번째 약수를 찾기 위한 변수 
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			cnt++;
			if (cnt == k) {
				cout << i << "\n";
			}
		}
	}

	if (cnt < k)
		cout << "0\n";

	return 0;
}