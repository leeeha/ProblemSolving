#include <iostream>
using namespace std;

int DP[101][100001];
int w[101];
int v[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // n: 물건의 수, k: 배낭의 용량
    int n, k;
    cin >> n >> k;

    // 각 물건의 무게와 가치 
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) { // 물건 1~n
        for (int j = 1; j <= k; j++) { // 배낭의 임시 용량 1~k
            // 물건 i의 무게가 배낭의 임시 용량을 초과하면
            if (w[i] > j)
                DP[i][j] = DP[i - 1][j]; // 물건 i-1까지만 담는다.
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << DP[n][k];

    return 0;
}