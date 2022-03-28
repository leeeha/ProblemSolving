#include<iostream>
#include<cmath>
using namespace std;

// M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾아라. 
// M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.
// 단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.

bool isPrimeNumber(int x) {
    if (x < 2) // 음수가 입력될 수도 있으니 예외 처리
        return false;

    // 2부터 x의 제곱근까지 모든 수를 확인하며
    for (int i = 2; i <= (int)sqrt(x); i++) {
        // x가 해당 수로 나누어 떨어진다면 
        if (x % i == 0) {
            // i와 그에 대칭인 수는 모두 x의 약수이고, x는 소수가 아님.
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
