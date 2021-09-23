// Sol2. string의 find 함수로 666 포함 여부 확인하기

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 몇번째 종말의 수를 구할지 입력 받기
	int N;
	cin >> N;

	int num = 665;
	int cnt = 0;

	// N번째 종말의 수를 구할 때까지 반복
	while (cnt != N) {
		num++; // 666부터 검색 시작

		// 666이 포함된 종말의 수를 발견하면
		if (to_string(num).find("666") != string::npos) {
			cnt++; // cnt == N이 되면 루프 탈출해서 결과 출력
		}
		// 종말의 수가 아닐 경우, num++하면서 검색 반복하기
	}

	// N번째 종말의 수 출력하기
	cout << num;

	return 0;
}