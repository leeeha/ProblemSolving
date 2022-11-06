#include <iostream>
#include <vector>
using namespace std;

/*
	�Ϲ����� �迭�� ���Ҹ� �����ϸ� ��ĭ�� ������ ������ �ϴµ�
	�̰� �ڵ����� ���ִ� �� vector!! �̰� ������ ������ �ݺ������� ��ܾ� ��.
*/

int main() {
	int n, k;
	cin >> n >> k; // n�� �ִ� 1,000��

	vector<int> v;
	for (int i = 0; i < n; i++)
		v.push_back(i + 1); // 1~n���� �ʱ�ȭ

	cout << "<";

	int cnt = 1;
	//vector<int>::iterator iter = v.begin();
	auto it = v.begin();

	while (!v.empty()) {
		// k��° ���Ҹ� �߰��ϸ� ����
		if (cnt == k) {
			cout << *it;
			it = v.erase(it);
			if (it == v.end())
				it = v.begin();

			// ���� ���� ���Ұ� ������ �޸�
			if (!v.empty()) cout << ", ";
			else {
				cout << ">";
				break;
			}

			cnt = 1;
		}
		else {
			if (++it == v.end())
				it = v.begin();
			cnt++;
		}
	}

	return 0;
}