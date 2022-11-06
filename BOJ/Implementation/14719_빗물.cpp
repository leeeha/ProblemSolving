#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 1 �� H, W �� 500
	int h, w;
	cin >> h >> w;

	// 2���� �迭 ����
	int** m = new int* [h]; // h��
	for (int i = 0; i < h; i++) {
		m[i] = new int[w] {}; // w�� (0���� �ʱ�ȭ)
	}

	for (int c = 0; c < w; c++) {
		int tmp;
		cin >> tmp;

		// ���� ����, ���� �Ʒ����� ���� �̵�
		int r = h - 1;
		while (tmp--) {
			m[r][c] = 1; // 1�� �ʱ�ȭ
			r--;
		}
	}

	int sum = 0, cur = 0;
	for (int i = 0; i < h; i++) {
		int cnt = 0; // �� �ึ�� ������ ���� �� �ִ� ĭ�� �� ī���� 
		 
		for (int j = 0; j < w; j++) {

			if (m[i][j] == 1) {
				int partialCnt = 0; // 1�� 1 ���̿� �ִ� 0�� ���� ī���� 

				cur = j + 1; // 1�� ������ �ٷ� ���� ������ �˻� 
				while (m[i][cur] == 0 && cur < w) {
					partialCnt++; // 0�� ���� ����
					cur++; // Ŀ�� �̵� 
				}

				if (cur >= w) { // �ε��� ������ ���� ��� 
					if (m[i][cur - 1] == 1) { // ������ ���� 1�̾�� 
						cnt += partialCnt; // ������ ���� �� ����.
					}
				}
				else {
					// cur < w�ε� while ������ ����Ǹ�, 1�� �ٽ� ������ ��! 
					cnt += partialCnt;
				}

				// �˻縦 �ٽ� ������ �ε����� ���� 
				j = cur - 1; // j�� �� ++�Ǳ� ������ cur�� �ƴ϶� cur-1�� �����ؾ� ��.
			}
		}

		//cout << i << "��: " << cnt << "\n";
		sum += cnt;
	}

	cout << sum << endl;

	return 0;
}