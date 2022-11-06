#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// �� ���� �ڿ��� N�� K�� �־����� ��, N�� ����� �� K��°�� ���� ���� ���
// N�� 1 �̻� 10,000 �����̴�. K�� 1 �̻� N ����
// ���� N�� ����� ������ K������ ��� K��° ����� �������� ���� ��쿡�� 0�� ���

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			v.push_back(i);

			// i�� �������� ��� ���� ���� 2�� �߰��� �� ������ ���� ó��
			if (i != n / i) {
				v.push_back(n / i);
			}
		}
	}

	sort(v.begin(), v.end()); // �������� ���� 
	// for(auto e: v)
	// 	cout << e << ' ';
	// cout << '\n';

	// n�� ����� k������ ������ 0 ��� 
	if (v.size() < k)
		cout << "0\n";
	else
		cout << v[k - 1] << "\n";

	return 0;
}