#include <iostream>
#include <queue>
#include <functional> // greater, less
using namespace std;

// x가 자연수라면 배열에 x 추가
// x가 0이라면 배열에서 가장 작은 값을 제거하면서 그 값을 출력 (pop)

// 입력은 0 또는 2^31보다 작은 양의 정수
// 0이 주어진 횟수만큼 출력, 배열이 비어 있는데 0이 입력되면 0 출력

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	// 가장 작은 값이 top에 오도록
	priority_queue<int, vector<int>, greater<int>> pq;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(x);
	}

	return 0;
}