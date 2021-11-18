#include <iostream>
#include <queue>
using namespace std;

// �ſ� ���� ���� ī�� ������ å�� ���� ���� �ִ�. 
// �̵��� �� ������ ��� ���� ���ĳ����ٸ�, ���� ������ ���� �� Ƚ���� �ſ� �޶�����. 
// N���� ���� ī�� ������ ũ�Ⱑ �־��� ��, �ּ� �� Ƚ���� ���Ͽ���.

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n; // �ִ� 10������ ����

	// ������ ���� ���� �� ������ ���� ��ģ��.
	// �켱���� ť�� ����ϸ�, ���͸� ������ �ʿ䰡 ��������.
	priority_queue<int, vector<int>, greater<int>> pq; // �ּ� ��

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

		// ī�� �� Ƚ���� �������� sum�� �ƴ϶�,
		// ���� ���� �� ��带 ��ģ (a + b)�� push�ؾ� ��.
		pq.push(a + b);
	}

	cout << sum;

	return 0;
}