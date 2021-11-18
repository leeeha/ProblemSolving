#include <iostream>
#include <queue>
#include <functional> // greater, less
using namespace std;

// x�� �ڿ������ �迭�� x �߰�
// x�� 0�̶�� �迭���� ���� ���� ���� �����ϸ鼭 �� ���� ��� (pop)

// �Է��� 0 �Ǵ� 2^31���� ���� ���� ����
// 0�� �־��� Ƚ����ŭ ���, �迭�� ��� �ִµ� 0�� �ԷµǸ� 0 ���

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	// ���� ���� ���� top�� ������
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