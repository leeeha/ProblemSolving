#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
	// ���ڿ��� ���̰� ������ ���� ������ ����
	if (a.length() == b.length())
		return a < b; // a�� b���� ���� ������ �տ� ���� true

	// �⺻�����δ� ���ڿ� ���� ������ ����
	return a.length() < b.length(); // a�� b���� ª���� true
}

int main()
{
	// �ܾ��� ���� �Է� �ޱ�
	int n;
	cin >> n;

	// n���� ���ڿ��� �̷���� �迭
	string* arr = new string[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// ����� ���� �Լ��� �����ϱ�
	sort(arr, arr + n, compare);

	cout << arr[0] << "\n";
	for (int i = 1; i < n; i++) {
		// ���� ���ڿ��� ������ ���� �ε����� �Ѿ��
		if (arr[i - 1] == arr[i])
			continue;
		else // ���� ���ڿ��� �ٸ��ٸ� ����ϱ�
			cout << arr[i] << "\n";
	}

	return 0;
}