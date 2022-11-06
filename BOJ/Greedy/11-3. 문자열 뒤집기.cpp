// 백준 1439번. 뒤집기 
#include<iostream>
#include<string>
using namespace std;

int main() {
	// 0과 1의 묶음 수를 각각 구해서 
	// 더 적은 묶음 수를 갖는 숫자를 뒤집는다. (묶음 수 자체가 뒤집는 횟수)
	// 0001100 -> 2:1 -> 1 뒤집기
	// 0111010 -> 3:2 -> 1 뒤집기
	// 1101101 -> 2:3 -> 0 뒤집기

	string s;
	cin >> s; // 100만보다 작은 길이
	
	int zero = 0, one = 0; // 0과 1의 묶음 수 카운트
	int cur = -1; // 현재 어떤 숫자인지 알려주는 플래그

	for (int i = 0; i < s.length(); ++i) {
		// 0이 아니다가 0이 나오면 묶음 수 증가
		if (cur != 0 && s[i] == '0') {
			cur = 0;
			++zero;
		}
		// 1이 아니다가 1이 나오면 묶음 수 증가
		else if (cur != 1 && s[i] == '1') {
			cur = 1;
			++one;
		}
	}

	// 둘 중에 더 적은 묶음 수만큼 숫자 뒤집기
	cout << min(zero, one) << endl;

	return 0;
}