// 1157번. 단어 공부
#include <iostream>
#include <string>
#include <cctype> // tolower, toupper
using namespace std;

int main() {
	string str;
	cin >> str;

	int cnt[26] = { 0 }; // 0으로 초기화

	for (int i = 0; i < str.length(); i++) {
		// 대소문자 구분 없애기 위해 모두 대문자로 변환
		str[i] = toupper(str[i]);

		// 문자열에서 "각 문자가 등장한 횟수"를 어떻게 셀까?
		// 대문자 알파벳에서 'A'를 빼주면, 그 자체가 알파벳 순서에 따른 인덱스가 된다!
		// A는 0, Z는 25 (인덱스에 'A'를 더하면 다시 알파벳이 나온다)
		cnt[str[i] - 'A']++;
	}

	// 가장 많이 등장한 알파벳의 인덱스 기억하기
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
		// 최댓값이 중복되지 않는지 검사하기
		if (maxCount == cnt[i])
			tmp++;
	}

	// 최댓값이 2번 이상 나오면 '?' 출력
	if (tmp > 1) cout << "?";
	// 그렇지 않으면 가장 많이 등장한 알파벳 출력하기
	else cout << (char)(idx + 'A');

	return 0;
}