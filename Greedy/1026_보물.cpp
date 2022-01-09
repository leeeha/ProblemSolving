#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	// A�� ��迭�� ����� ����� �ʰ� S�� �ּڰ��� ���ϸ� �Ǳ� ������
	// ��ǻ� A�� B�� ��� �����ص� �������. 

	int n;
	cin >> n;

	vector<int> a, b;
	int num;

	// �迭 a, b�� �ʱ�ȭ
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		cin >> num;
		b.push_back(num);
	}

	// a�� ��������, b�� ������������ ����
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end());

	int result = 0;
	for (int i = 0; i < n; i++) {
		result += a[i] * b[i];
	}
	cout << result << "\n";

	return 0;
}