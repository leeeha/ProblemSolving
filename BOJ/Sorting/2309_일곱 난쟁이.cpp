// 2309��. �ϰ� ������
#include <iostream>
#include <algorithm> // std::sort
using namespace std;

int main()
{
	int arr[9]{};
	int sum = 0;

	// ������ 9���� Ű�� �Է� �޴´�.
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	int gap = sum - 100;

	/* ��� �ΰ��� ���ؾ� 40�� �����°�?
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
	while (!found) { // not found��� �ݺ�
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == gap) {
				// ��¥ �������� Ű�� 0���� �����
				arr[i] = 0, arr[j] = 0;
				found = true;
				break;
			}
		}
		i++;
	}

	// �������� ����
	std::sort(arr, arr + 9);

	// 0�� �����ϰ� 7���� ������ Ű ���
	for (int i = 2; i < 9; i++)
		printf("%d\n", arr[i]);

	return 0;
}