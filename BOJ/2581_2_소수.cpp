#include<iostream>
using namespace std;

bool isPrimeNumber(int x) {
    if (x < 2)
        return false;

    // 2���� x�� �����ٱ��� ��� ���� Ȯ���ϸ� 
    for (int i = 2; i * i <= x; i++) {
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