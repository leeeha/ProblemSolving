/*
	 N개의 배열 원소들을 'M번 더하여' 만들 수 있는 가장 큰 수를 구하여라.
	 단, 하나의 원소는 'K번까지만 연속으로' 더할 수 있다.
	 (2 <= N <= 1000, 1<= M <= 10,000, 1<= K <= 10,000)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	int first = v[n - 1];
	int second = v[n - 2];

	int result = 0;

	/* Sol1. m이 10,000이하일 때
	while (true) {
		// 가장 큰 수 k번 더하기
		for (int i = 0; i < k; i++) {
			if (m == 0)
				break;
			result += first;
			m -= 1; // 더할 때마다 1씩 감소
		}

		if (m == 0)
			break;

		// 두번째로 큰 수 1번 더하기
		result += second;
		m -= 1;
	}
	cout << result << '\n';
	*/

	// Sol2. m의 크기가 10,000보다 훨씬 더 커진다면, 첫번째 방법으로는 시간 초과 판정
	// 더 효율적인 방법 고려하기 -> (k + 1) 길이의 수열이 반복해서 더해지는 패턴
	// 가장 큰 수가 더해지는 횟수 -> (m / (k + 1)) * k + m % (k + 1)
	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);

	result += cnt * first;
	result += (m - cnt) * second;

	cout << result << '\n';

	return 0;
}