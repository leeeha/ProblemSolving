#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n; // ���� ������ ���� ����

	stack<int> s;
	vector<char> op; // push, pop ���� ���

	int x; // ���� ������ �� �ϳ��� �Է� �ޱ�
	int num = 1; // 1~n������ ����

	for (int i = 0; i < n; i++) {
		cin >> x;

		// ������ ���� �׺��� �۰ų� ���� �������� push
		while (num <= x) {
			s.push(num);
			num++;
			op.push_back('+');
		}

		// ������ top�� ������ ���� ������ pop!
		if (s.top() == x) {
			s.pop();
			op.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (char ch : op)
		cout << ch << '\n';

	return 0;
}