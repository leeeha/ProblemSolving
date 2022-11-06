// 2750��. �� ���� (�⺻ ����: ����, ����, ����)
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// ���� ����
void selectionSort(int* arr, const int n) {
	for (int i = 0; i < n - 1; ++i) {
		int minIdx = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[minIdx] > arr[j]) {
				minIdx = j; // �ּڰ��� ���� �ε����� �����ؼ�
			}
		}
		swap(arr[minIdx], arr[i]); // �ܺ� ������ �������� �����Ѵ�.
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