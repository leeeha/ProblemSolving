#include <iostream>
#include <string>
using namespace std;

struct Alphabet {
	char ch;
	int idx;
};

int main() {
	Alphabet alpha[26];

	for (int i = 0; i < 26; i++) {
		alpha[i].ch = 'a' + i;
		alpha[i].idx = -1;
	}

	string str;
	cin >> str;

	for (unsigned int i = 0; i < str.length(); i++) {
		for (int j = 0; j < 26; j++) {
			// str[i]�� ������ ���¿���, alpha[j].ch�� a~z���� ��ȭ
			// �ش��ϴ� ���ĺ��� �߰��ϸ� �� ���ĺ��� -1�� str[i]�� i�� �����ϱ�
			if (str[i] == alpha[j].ch) {
				// ��, -1�� �ƴ� ���� �̹� �����ߴ� �����̹Ƿ� 
				// �ε��� ������Ʈ ���� �Ѿ��
				if (alpha[j].idx == -1) {
					alpha[j].idx = i;
				}
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << alpha[i].idx << " ";
	}

	return 0;
}