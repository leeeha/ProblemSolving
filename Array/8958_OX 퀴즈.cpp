#include <iostream>
#include <string>
using namespace std;

int main()
{
	// �׽�Ʈ ���̽��� ����
	int n;
	cin >> n;

	// n���� ���ڿ� �Է� �ޱ�
	string* s = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		// �� ���ڿ����� ��� ������ ���� 0���� �ʱ�ȭ
		int sum = 0, score = 0;

		// ���ڿ��� ���̸�ŭ ���� ����ϱ�
		for (int j = 0; j < s[i].length(); j++) {
			if (s[i].at(j) == 'O') {
				score++; // O�� ���� ������ ������ ������Ű��
				sum += score; // sum�� ���ϴٰ�
			}
			else { // X�� ������
				score = 0; // ���� �ʱ�ȭ!!!
			}
			// �ٽ� O�� ������ score 0���� ī��Ʈ�ϱ�
		}

		cout << sum << endl;
	}

	return 0;
}