// Sol2. string�� find �Լ��� 666 ���� ���� Ȯ���ϱ�

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// ���° ������ ���� ������ �Է� �ޱ�
	int N;
	cin >> N;

	int num = 665;
	int cnt = 0;

	// N��° ������ ���� ���� ������ �ݺ�
	while (cnt != N) {
		num++; // 666���� �˻� ����

		// 666�� ���Ե� ������ ���� �߰��ϸ�
		if (to_string(num).find("666") != string::npos) {
			cnt++; // cnt == N�� �Ǹ� ���� Ż���ؼ� ��� ���
		}
		// ������ ���� �ƴ� ���, num++�ϸ鼭 �˻� �ݺ��ϱ�
	}

	// N��° ������ �� ����ϱ�
	cout << num;

	return 0;
}