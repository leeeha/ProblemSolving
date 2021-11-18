#include <iostream>
#include <queue>
using namespace std;

// 매우 많은 숫자 카드 묶음이 책상 위에 놓여 있다. 
// 이들을 두 묶음씩 골라 서로 합쳐나간다면, 고르는 순서에 따라서 비교 횟수가 매우 달라진다. 
// N개의 숫자 카드 묶음의 크기가 주어질 때, 최소 비교 횟수를 구하여라.

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n; // 최대 10만개의 묶음

	// 개수가 가장 작은 두 묶음을 먼저 합친다.
	// 우선순위 큐를 사용하면, 벡터를 정렬할 필요가 없어진다.
	priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}

	int sum = 0;
	while (pq.size() >= 2) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		sum += (a + b);

		// 카드 비교 횟수의 누적합인 sum이 아니라,
		// 가장 작은 두 노드를 합친 (a + b)를 push해야 함.
		pq.push(a + b);
	}

	cout << sum;

	return 0;
}