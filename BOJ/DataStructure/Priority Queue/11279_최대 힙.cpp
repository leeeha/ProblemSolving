#include <iostream>
#include <queue>
#include <functional> // greater, less
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	// ���� ū ���� top�� ������ (����Ʈ)
	//priority_queue<int, vector<int>, less<int>> pq;
	priority_queue<int> pq;

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