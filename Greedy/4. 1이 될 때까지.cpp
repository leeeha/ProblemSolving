#include<iostream>
using namespace std;

// n�� 1�� �� �������� ���� Ƚ���� �ּ�ȭ ��Ű����
// 1�� ���� �ͺ��� k�� ������ Ƚ���� �ִ��� �÷��� �Ѵ�.
// ��, n�� k�� ����� �� ������ 1�� ���� n�� k�� ������ ������ �ݺ��Ѵ�.

int main() {
	int n, k;
	cin >> n >> k;

	int count = 0;
	while (n > 1) {
		if (n % k == 0) {
			n /= k;
			count++;
		}
		else {
			n -= 1;
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}