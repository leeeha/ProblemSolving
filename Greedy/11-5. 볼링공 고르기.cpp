/* 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; // �������� ���� n, ���� �ִ� ���� m

	int x;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end()); // �������� ����

	// ���� �ٸ� n������ 2���� �����ϴ� ����� ��
	int result = n * (n - 1) / 2;

	// �������� ���� ��� �ߺ��Ǵ��� ī��Ʈ
	vector<int> arr;
	int cnt = 1;

	for (int i = 0; i < n - 1; i++) {
		if (v[i] == v[i + 1]) {
			cnt++;

			// �迭�� ������ �߻��� �ߺ����� ���� ó�����ֱ�
			if (i == n - 2 && cnt > 1) {
				arr.push_back(cnt);
			}
		}
		else { // �ߺ��� ���� �����ٰ� �ٸ� ���� ������
			if (cnt > 1) {
				arr.push_back(cnt);
				cnt = 1; // ���� �ʱ�ȭ
			}
		}
	}

	// ���õ� �� ���� �������� ���� ������ ��� ����
	for (int i = 0; i < arr.size(); i++) {
		result -= arr[i] * (arr[i] - 1) / 2;
	}

	cout << result << '\n';

	return 0;
}
*/

#include<iostream>
using namespace std;

// 1���� 10������ ���Ը� ���� �� �ִ� �迭
int arr[11];

int main() {
	int n, m;
	cin >> n >> m; // �������� ���� n, ���� �ִ� ���� m

	// �� ���Կ� �ش��ϴ� �������� ���� ī��Ʈ
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}

	int result = 0;
	for (int i = 1; i <= m; i++) { // ���� 1~m������ ���ؼ�
		// A�� ������ �� �ִ�, ���԰� i�� �������� ������ arr[i]
		// B�� ������ �� �ִ� ����� ���� n -= arr[i]
		n -= arr[i];
		result += arr[i] * n;
	}

	// �� ����� ���� �ٸ� ������ �������� �����ϴ� ����� �� ���
	cout << result << "\n";

	return 0;
}