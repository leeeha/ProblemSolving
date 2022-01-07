/*
	 N���� �迭 ���ҵ��� 'M�� ���Ͽ�' ���� �� �ִ� ���� ū ���� ���Ͽ���.
	 ��, �ϳ��� ���Ҵ� 'K�������� ��������' ���� �� �ִ�.
	 (2 <= N <= 1000, 1<= M <= 10,000, 1<= K <= 10,000)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> v;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	int first = v[n - 1];
	int second = v[n - 2];

	int result = 0;

	/* Sol1. m�� 10,000������ ��
	while (true) {
		// ���� ū �� k�� ���ϱ�
		for (int i = 0; i < k; i++) {
			if (m == 0)
				break;
			result += first;
			m -= 1; // ���� ������ 1�� ����
		}

		if (m == 0)
			break;

		// �ι�°�� ū �� 1�� ���ϱ�
		result += second;
		m -= 1;
	}
	cout << result << '\n';
	*/

	// Sol2. m�� ũ�Ⱑ 10,000���� �ξ� �� Ŀ���ٸ�, ù��° ������δ� �ð� �ʰ� ����
	// �� ȿ������ ��� ����ϱ� -> (k + 1) ������ ������ �ݺ��ؼ� �������� ����
	// ���� ū ���� �������� Ƚ�� -> (m / (k + 1)) * k + m % (k + 1)
	int cnt = (m / (k + 1)) * k;
	cnt += m % (k + 1);

	result += cnt * first;
	result += (m - cnt) * second;

	cout << result << '\n';

	return 0;
}