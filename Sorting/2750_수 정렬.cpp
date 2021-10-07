// 2750번. 수 정렬 (기본 정렬: 버블, 선택, 삽입)
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// 선택 정렬
void selectionSort(int* arr, const int n) {
	for (int i = 0; i < n - 1; ++i) {
		int minIdx = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[minIdx] > arr[j]) {
				minIdx = j; // 최솟값을 갖는 인덱스를 선택해서
			}
		}
		swap(arr[minIdx], arr[i]); // 외부 루프의 시작점과 스왑한다.
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	selectionSort(arr, n);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	return 0;
}