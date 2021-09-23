// Sol1. 나머지, 몫 연산으로 666 포함 여부 확인하기

#include<iostream>
using namespace std;

int main()
{
	// 몇번째 종말의 수를 구할지 입력 받기
	int N;
	cin >> N;

	int num = 665;
	int cnt = 0;
	int temp;

	// N번째 종말의 수를 구할 때까지 반복
	while (cnt != N) {
		num++; // 666부터 1씩 증가시키면서 종말의 수 찾기

		// 종말의 수를 찾아보자!
		temp = num;
		while (temp != 0) {
			// 종말의 수일 경우 cnt++
			if (temp % 1000 == 666) {
				cnt++;
				break;
			}
			else {
				temp /= 10;
			}
		}

		/*  내부 루프 탈출
		Case1. 종말의 수 발견해서 break한 경우
		1) cnt == N이라면, 외부 루프도 탈출하여 종말의 수 출력
		2) cnt != N이라면 'N번째에 맞는' 종말의 수를 구하기 위해 다시 num 증가시키기

		Case2. temp == 0이 된 경우
		cnt != N인 상태에서 종말의 수를 구할 때까지 num 증가시키기
		*/
	}

	// N번째에 해당하는 종말의 수 출력하기
	cout << num;

	return 0;
}