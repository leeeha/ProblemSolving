#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 테스트 케이스의 개수
	int n;
	cin >> n;

	// n개의 문자열 입력 받기
	string* s = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	for (int i = 0; i < n; i++) {
		// 각 문자열마다 계산 시작할 때는 0으로 초기화
		int sum = 0, score = 0;

		// 문자열의 길이만큼 점수 계산하기
		for (int j = 0; j < s[i].length(); j++) {
			if (s[i].at(j) == 'O') {
				score++; // O가 나올 때마다 점수를 증가시키고
				sum += score; // sum에 더하다가
			}
			else { // X가 나오면
				score = 0; // 점수 초기화!!!
			}
			// 다시 O가 나오면 score 0부터 카운트하기
		}

		cout << sum << endl;
	}

	return 0;
}