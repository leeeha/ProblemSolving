#include<iostream>
#include<cmath>
using namespace std;

// M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ��� �̵� �Ҽ��� �հ� �ּڰ��� ã�ƶ�. 
// M�� N�� 10,000������ �ڿ����̸�, M�� N���� �۰ų� ����.
// ��, M�̻� N������ �ڿ��� �� �Ҽ��� ���� ���� ù° �ٿ� -1�� ����Ѵ�.

bool isPrimeNumber(int x) {
    if (x < 2) // ������ �Էµ� ���� ������ ���� ó��
        return false;

    // 2���� x�� �����ٱ��� ��� ���� Ȯ���ϸ�
    for (int i = 2; i <= (int)sqrt(x); i++) {
        // x�� �ش� ���� ������ �������ٸ� 
        if (x % i == 0) {
            // i�� �׿� ��Ī�� ���� ��� x�� ����̰�, x�� �Ҽ��� �ƴ�.
            return false;
        }
    }

    return true;
}

int main() {
    int m, n;
    cin >> m >> n;

    int sum = 0, min = -1;
    for (int i = m; i <= n; i++) {
        if (isPrimeNumber(i)) {
            sum += i;
            if (min == -1) // not updated
                min = i;
        }
    }

    if (sum == 0)
        cout << "-1";
    else {
        cout << sum << "\n" << min;
    }

    return 0;
}
