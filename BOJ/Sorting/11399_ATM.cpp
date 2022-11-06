// 11399��. ATM
/*
	Input
	����� �� N��
	�� ����� ���� �����ϴ� �� �ɸ��� �ð� Pi

	Output
	�� ����� ���� �����ϴ� �� �ʿ��� �ð��� ���� �ּڰ�
*/

#include <iostream>
#include <algorithm> // std::sort
using namespace std;

int main()
{
	int n;
	cin >> n;

	int* time = new int[n];
	for (int i = 0; i < n; i++)
		cin >> time[i];

	// Pi: 3 1 4 3 2 -> 1 2 3 3 4
	// �ּ� �ð�: 1*5 + 2*4 + 3*3 + 3*2 + 4*1
	// �ð��� ���� �ɸ��� ����ϼ��� ���ʿ� ���� ���� �Ѵ�!

	std::sort(time, time + n);

	int total = 0;
	for (int i = 0; i < n; i++) {
		total += time[i] * (n - i);
	}

	cout << total;

	return 0;
}