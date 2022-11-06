#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 두 개의 자연수 N과 K가 주어졌을 때, N의 약수들 중 K번째로 작은 수를 출력
// N은 1 이상 10,000 이하이다. K는 1 이상 N 이하
// 만일 N의 약수의 개수가 K개보다 적어서 K번째 약수가 존재하지 않을 경우에는 0을 출력

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);

			// i가 제곱수인 경우 같은 수가 2번 추가될 수 있으니 예외 처리
			if (i != n / i) {
				v.push_back(n / i);
			}
		}
	}

	sort(v.begin(), v.end()); // 오름차순 정렬 
	// for(auto e: v)
	// 	cout << e << ' ';
	// cout << '\n';

	// n의 약수가 k개보다 적으면 0 출력 
	if (v.size() < k)
		cout << "0\n";
	else
		cout << v[k - 1] << "\n";

	return 0;
}