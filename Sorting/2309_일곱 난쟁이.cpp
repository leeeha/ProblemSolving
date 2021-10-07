// 2309번. 일곱 난쟁이
#include <iostream>
#include <algorithm> // std::sort
using namespace std;

int main()
{
	int arr[9]{};
	int sum = 0;

	// 난쟁이 9명의 키를 입력 받는다.
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	int gap = sum - 100;

	/* 어느 두개를 더해야 40이 나오는가?
		20
		7
		23
		19
		10
		15  <- i=5
		25  <- j=6
		8
		13
	*/

	bool found = false;
	int i = 0;
	while (!found) { // not found라면 반복
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == gap) {
				// 가짜 난쟁이의 키는 0으로 만들기
				arr[i] = 0, arr[j] = 0;
				found = true;
				break;
			}
		}
		i++;
	}

	// 오름차순 정렬
	std::sort(arr, arr + 9);

	// 0을 제외하고 7명의 난쟁이 키 출력
	for (int i = 2; i < 9; i++)
		printf("%d\n", arr[i]);

	return 0;
}