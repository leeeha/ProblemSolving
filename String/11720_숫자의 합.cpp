#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n; // ������ ����

	string str;
	cin >> str; // ���ڿ��� �Է� �ޱ�

	int sum = 0;
	for (int i = 0; i < n; i++) { // n�������� ���ϱ�
		sum += str.at(i) - 48; // at() �Լ��� �ε��� ���� üũ������, �ӵ� ����.
		//sum += str[i] - 48; // [] �����ڴ� �ε��� ���� üũ���� ������, �ӵ� ����.
	}

	cout << sum;

	return 0;
}