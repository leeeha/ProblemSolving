#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> v;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i] - '0'); // char to int
	}

	int result = v[0]; // 첫번째 수로 초기화 
	// 최종 연산 결과는 20억 이하의 정수 (int 범위)

	// 두번째 수부터 곱하기 또는 더하기 연산
	for (int i = 1; i < v.size(); i++) {
		// 자기 자신이 0 또는 1이면 '더하기'
		if (v[i] == 0 || v[i] == 1) {
			result += v[i];
		}
		else { // 2~9
		   // 본인은 2~9이지만, 바로 이전 수가 0 또는 1이면 '더하기'
			if (result == 0 || result == 1)
				result += v[i];
			else // 자기 자신도, 이전의 수도 모두 2~9이면 '곱하기'
				result *= v[i];
		}
	}

	cout << result << '\n';

	return 0;
}

/* 더 효율적인 코드

	int main() {
		string str;
		cin >> str;

		// 첫 번째 문자를 숫자로 변경한 값을 대입
		int result = str[0] - '0';

		for (int i = 1; i < str.size(); i++) {
			// 두 수 중에서 하나라도 '0' 혹은 '1'인 경우, 더하기 수행
			int num = str[i] - '0';
			if (num <= 1 || result <= 1) {
				result += num;
			}
			else { // 그 외에는 곱하기 수행
				result *= num;
			}
		}

		cout << result << '\n';
	}
*/