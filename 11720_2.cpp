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
		sum += str.at(i) - 48; // at() 함수는 인덱스 범위 체크O but 속도 느림
		//sum += str[i] - 48; // [] 연산자는 인덱스 범위 체크X but 속도 빠름
	}
	/*
	str.at()은 입력의 범위를 확인해서 문자열의 범위를 벗어나는 인덱스를 접근하려 들면 out of range 예외를 발생시킵니다.
	str[]은 범위 체크가 없습니다. 범위를 벗어나는 인덱스에 접근은 가능하지만 undefined behaviour이며 어떤 값이 들어있을지 알 수 없습니다.
	*/

	cout << sum;

	return 0;
}