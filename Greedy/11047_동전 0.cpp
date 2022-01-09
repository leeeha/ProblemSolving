#include<iostream>
#include<vector>
using namespace std;

// n개의 동전으로 k원을 만드는데 필요한 최소 동전의 개수 구하기
// 1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000
// n개의 동전 단위는 오름차순으로 주어지니까 정렬할 필요 없음.

// 1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수
// 모든 동전의 단위가 서로 배수 관계이므로 그리디로 최적해를 구할 수 있음.
// 배수 관계가 아닐 때는 거스름돈을 1부터 k까지 늘려가면서 DP로 최적해를 구해야 함.

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v;
	int coin;
	for (int i = 0; i < n; i++) {
		cin >> coin;
		v.push_back(coin); // 오름차순으로 입력
	}

	int cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] <= k) {
			cnt += k / v[i];
			k %= v[i];

			// 1원까지 필요하더라도 1은 모든 수의 약수니까 나머지는 항상 0이다.
			if (k == 0) break;
		}
	}

	cout << cnt << "\n";

	return 0;
}