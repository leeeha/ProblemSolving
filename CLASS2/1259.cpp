#include <iostream>
#include <algorithm> // std::reverse
using namespace std;

int main()
{
	string str;
	while (true) {
		cin >> str;

		// �Է��� 0�̸� ���� ����
		if (str == "0") break;

		// ���� ���ڿ� �ӽ� ����
		string tmp = str;

		// ���ڿ� ������
		reverse(str.begin(), str.end());

		// ���ڿ� ��
		// if(tmp == str) ...
		if (tmp.compare(str) == 0) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}