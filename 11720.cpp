#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	char* arr = new char[n];

	int sum = 0;
	for (int i = 0; i < n; i++) {
		// char���� �� �� ���ھ��� �Է� �޴´�!
		cin >> arr[i];
		sum += arr[i] - 48; // char�� '0' == ������ 48
	}
	cout << sum;

	delete[] arr;

	return 0;
}