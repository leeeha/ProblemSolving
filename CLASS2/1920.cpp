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

	// left > right�� ���, key�� �߰����� �������Ƿ� 0 ���
	printf("0\n");
	return;
}

int main() {
	int n;
	scanf("%d", &n);

	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	// ���� Ž���� ���� �迭 �����ϱ�
	sort(arr, arr + n);

	int m;
	scanf("%d", &m);

	int tmp;
	for (int i = 0; i < m; i++) {
		scanf("%d", &tmp);

		// �迭 a�� tmp�� �ִ��� ����Ž������ Ȯ���ϱ�
		binarySearch(arr, n, tmp);
	}

	return 0;
}