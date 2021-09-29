#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	char* arr = new char[n];

	int sum = 0;
	for (int i = 0; i < n; i++) {
		// char형은 딱 한 문자씩만 입력 받는다!
		cin >> arr[i];
		sum += arr[i] - 48; // char형 '0' == 십진수 48
	}
	cout << sum;

	delete[] arr;

	return 0;
}