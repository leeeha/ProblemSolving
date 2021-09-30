// 1157��. �ܾ� ����
#include <iostream>
#include <string>
#include <cctype> // tolower, toupper
using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt[26] = { 0 }; // 0���� �ʱ�ȭ

	for (int i = 0; i < str.length(); i++) {
		// ��ҹ��� ���� ���ֱ� ���� ��� �빮�ڷ� ��ȯ
		str[i] = toupper(str[i]);

		// ���ڿ����� "�� ���ڰ� ������ Ƚ��"�� ��� ����?
		// �빮�� ���ĺ����� 'A'�� ���ָ�, �� ��ü�� ���ĺ� ������ ���� �ε����� �ȴ�!
		// A�� 0, Z�� 25 (�ε����� 'A'�� ���ϸ� �ٽ� ���ĺ��� ���´�)
		cnt[str[i] - 'A']++;
	}

	// ���� ���� ������ ���ĺ��� �ε��� ����ϱ�
	int maxCount = cnt[0];
	int idx = 0;
	for (int i = 1; i < 26; i++) {
		if (maxCount < cnt[i]) {
			maxCount = cnt[i];
			idx = i;
		}
	}

	int tmp = 0;
	for (int i = 0; i < 26; i++) {
		// �ִ��� �ߺ����� �ʴ��� �˻��ϱ�
		if (maxCount == cnt[i])
			tmp++;
	}

	// �ִ��� 2�� �̻� ������ '?' ���
	if (tmp > 1) cout << "?";
	// �׷��� ������ ���� ���� ������ ���ĺ� ����ϱ�
	else cout << (char)(idx + 'A');

	return 0;
}