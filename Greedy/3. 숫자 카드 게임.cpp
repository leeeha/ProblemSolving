#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));

	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			v[i][j] = num;
		}
	}

	// �� �࿡�� ���� ���� ���� �̱�
	vector<int> minArr;
	for (int i = 0; i < n; i++) {
		int min = 10001;
		for (int j = 0; j < m; j++) {
			if (v[i][j] < min) {
				min = v[i][j];
			}
		}
		minArr.push_back(min);
	}

	sort(minArr.begin(), minArr.end());
	cout << minArr[n - 1] << '\n'; // �� �߿��� �ִ� ���

	return 0;
}

/* �� ȿ������ Ǯ�̰��� (2���� �迭�� ������ �ʰ� �Է��� �����鼭 �ٷ� ó��)

	int main() {
		int n, m;
		cin >> n >> m;

		int result = -1;

		// �� �پ� �Է� �޾� Ȯ���ϱ�
		for (int i = 0; i < n; i++) {
			// ���� �ٿ��� '���� ���� ��' ã��
			int min_value = 10001;
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				min_value = min(min_value, x);
			}
			// '���� ���� ��'�� �߿��� ���� ū �� ã��
			result = max(result, min_value);

			// ���� ������ �Ѿ ������ result ����
		}

		cout << result << '\n'; // ���� ��� ���
	}

*/