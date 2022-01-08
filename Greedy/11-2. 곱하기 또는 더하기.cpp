#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string s;
	cin >> s;

	vector<int> v;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i] - '0'); // char to int
	}

	int result = v[0]; // ù��° ���� �ʱ�ȭ 
	// ���� ���� ����� 20�� ������ ���� (int ����)

	// �ι�° ������ ���ϱ� �Ǵ� ���ϱ� ����
	for (int i = 1; i < v.size(); i++) {
		// �ڱ� �ڽ��� 0 �Ǵ� 1�̸� '���ϱ�'
		if (v[i] == 0 || v[i] == 1) {
			result += v[i];
		}
		else { // 2~9
		   // ������ 2~9������, �ٷ� ���� ���� 0 �Ǵ� 1�̸� '���ϱ�'
			if (result == 0 || result == 1)
				result += v[i];
			else // �ڱ� �ڽŵ�, ������ ���� ��� 2~9�̸� '���ϱ�'
				result *= v[i];
		}
	}

	cout << result << '\n';

	return 0;
}

/* �� ȿ������ �ڵ�

	int main() {
		string str;
		cin >> str;

		// ù ��° ���ڸ� ���ڷ� ������ ���� ����
		int result = str[0] - '0';

		for (int i = 1; i < str.size(); i++) {
			// �� �� �߿��� �ϳ��� '0' Ȥ�� '1'�� ���, ���ϱ� ����
			int num = str[i] - '0';
			if (num <= 1 || result <= 1) {
				result += num;
			}
			else { // �� �ܿ��� ���ϱ� ����
				result *= num;
			}
		}

		cout << result << '\n';
	}
*/