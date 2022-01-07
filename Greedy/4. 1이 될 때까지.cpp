#include<iostream>
using namespace std;

// n이 1이 될 때까지의 연산 횟수를 최소화 시키려면
// 1씩 빼는 것보다 k로 나누는 횟수를 최대한 늘려야 한다.
// 즉, n이 k의 배수가 될 때까지 1씩 빼고 n을 k로 나누는 과정을 반복한다.

int main() {
	int n, k;
	cin >> n >> k;

	int count = 0;
	while (n > 1) {
		if (n % k == 0) {
			n /= k;
			count++;
		}
		else {
			n -= 1;
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}