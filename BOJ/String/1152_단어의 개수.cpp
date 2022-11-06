// 1152번. 단어의 개수
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str); // 공백을 포함해서 문자열 입력 받기

	int cnt = 0;
	int n = str.length();

	// i=0     i=1
	// 공백    영문자
	// 영문자  공백
	// 영문자  영문자

	// 공백 공백 이렇게 연속될 수 없는 상황에서 
	// "공백이 나왔다"는 것은 첫번째 원소를 제외하고는 
	// "바로 앞에 영문자가 있었다"는 거니까 단어 개수 증가시키기!
	// 영문자를 만날 때 카운트를 증가시키면 단어 개수보다 많아지니까
	// 공백을 기준으로 카운트를 증가시킨다.

	for (int i = 1; i < n; i++) {
		// 다시 공백이 나오면 cnt++ 
		if (str[i] == ' ') {
			cnt++;
		}
	}

	// 마지막이 영문자로 끝나면 cnt++ (공백으로 끝난 경우 이미 cnt++한 상태)
	if (str[n - 1] != ' ')
		cnt++;

	cout << cnt;

	return 0;
}