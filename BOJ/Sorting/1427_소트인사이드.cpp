// 1427��. ��Ʈ�λ��̵�
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// �Է�: 1,000,000,000���� �۰ų� ���� �ڿ���
	string s;
	cin >> s;
	int n = s.length();

	// �������� ����
	for (int i = 0; i < n - 1; ++i) {
		int max = i;
		for (int j = i + 1; j < n; ++j) {
			if (s[j] > s[max]) {
				max = j; // �ִ��� ���� �ε����� �����ؼ�
			}
		}
		swap(s[max], s[i]); // �ܺ� ������ �������� �����Ѵ�.
	}

	cout << s;

	return 0;
}