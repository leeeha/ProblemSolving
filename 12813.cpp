#include <iostream>
#include <cstring>
using namespace std;

char a[100'001];
char b[100'001];

int main()
{
	// char 배열로 이진수 입력 받기
	cin >> a >> b;

	// & (AND)
	for (unsigned int i = 0; i < strlen(a); i++) {
		(a[i] == '1' && b[i] == '1') ? cout << '1' : cout << '0';
	}
	cout << '\n';

	// | (OR)
	for (unsigned int i = 0; i < strlen(a); i++) {
		(a[i] == '1' || b[i] == '1') ? cout << '1' : cout << '0';
	}
	cout << '\n';

	// ^ (XOR)
	for (unsigned int i = 0; i < strlen(a); i++) {
		(a[i] != b[i]) ? cout << '1' : cout << '0';
	}
	cout << '\n';

	// ~ (NOT)
	for (unsigned int i = 0; i < strlen(a); i++) {
		(a[i] == '1') ? cout << '0' : cout << '1';
	}
	cout << '\n';

	// ~ (NOT)
	for (unsigned int i = 0; i < strlen(b); i++) {
		(b[i] == '1') ? cout << '0' : cout << '1';
	}
	cout << '\n';

	return 0;

}