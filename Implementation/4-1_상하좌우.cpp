#include<iostream>
#include<string>
using namespace std;

int x = 1, y = 1; // �ʱ� ��ġ

// L, R, U, D�� ���� �̵� ����
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char moveTypes[4] = {'L', 'R', 'U', 'D'};

int main() {
	int n;
	cin >> n; // ���簢����� ũ��

	// cin���� �Է� ������ ���Ͱ� ���ۿ� �����ֱ� ������,
	// ���� �Է��� �ޱ� ���ؼ��� �ݵ�� ���۸� ������ �Ѵ�.
	cin.ignore(); 

	// ��� ���ڸ� �Է����� �𸣱� ������ ���ڿ� �� �� ��ü�� �Է� �޴´�.
	string plans;
	getline(cin, plans);

	// �̵� ��ȹ�� �ϳ��� Ȯ��
    for (int i = 0; i < plans.size(); i++) {
        char plan = plans[i];

        // �̵� �� ��ǥ ���ϱ� 
        int nx = -1, ny = -1;
        for (int j = 0; j < 4; j++) {
            if (plan == moveTypes[j]) {
                nx = x + dx[j];
                ny = y + dy[j];
            }
        }

        // ������ ����� ��� ���� 
        if (nx < 1 || ny < 1 || nx > n || ny > n) 
			continue;

        // ������ ����� ���� ���� �̵� ���� 
        x = nx;
        y = ny;
    }

    cout << x << ' ' << y << '\n';

    return 0;
}