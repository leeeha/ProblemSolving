#include <iostream>
#include <algorithm> // std::reverse
using namespace std;

int main()
{
	string str;
	while (true) {
		cin >> str;

		// 입력이 0이면 루프 종료
		if (str == "0") break;

		// 원본 문자열 임시 저장
		string tmp = str;

		// 문자열 뒤집기
		reverse(str.begin(), str.end());

		// 문자열 비교
		// if(tmp == str) ...
		if (tmp.compare(str) == 0) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}