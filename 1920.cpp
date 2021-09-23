#include <iostream>
#include <algorithm> // std::sort
using namespace std;

void binarySearch(int* arr, int n, int key) {
	int left = 0, right = n - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (arr[mid] == key) {
			printf("1\n");
			return;
		}
		else if (arr[mid] > key) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	// left > right인 경우, key를 발견하지 못했으므로 0 출력
	printf("0\n");
	return;
}

int main() {
	int n;
	scanf("%d", &n);

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	// 이진 탐색을 위해 배열 정렬하기
	sort(arr, arr + n);

	int m;
	scanf("%d", &m);

	int tmp;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);

		// 배열 a에 tmp가 있는지 이진탐색으로 확인하기
		binarySearch(arr, n, tmp);
	}

	return 0;
}