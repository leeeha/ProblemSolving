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
			// str[i]는 고정된 상태에서, alpha[j].ch는 a~z까지 변화
			// 해당하는 알파벳을 발견하면 그 알파벳의 -1을 str[i]의 i로 변경하기
			if (str[i] == alpha[j].ch) {
				// 단, -1이 아닌 경우는 이미 등장했던 문자이므로 
				// 인덱스 업데이트 없이 넘어가기
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