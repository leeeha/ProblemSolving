#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n; // 숫자의 개수

	string str;
	cin >> str; // 문자열로 입력 받기

	int sum = 0;
	for (int i = 0; i < n; i++) { // n개까지만 더하기
		sum += str.at(i) - 48; // at() 함수는 인덱스 범위 체크하지만, 속도 느림.
		//sum += str[i] - 48; // [] 연산자는 인덱스 범위 체크하지 않지만, 속도 빠름.
	}

	cout << sum;

	return 0;
}