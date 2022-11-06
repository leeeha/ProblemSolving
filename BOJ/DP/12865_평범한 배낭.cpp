#include <iostream>
using namespace std;

int DP[101][100001];
int w[101];
int v[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // n: ������ ��, k: �賶�� �뷮
    int n, k;
    cin >> n >> k;

    // �� ������ ���Կ� ��ġ 
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++) { // ���� 1~n
        for (int j = 1; j <= k; j++) { // �賶�� �ӽ� �뷮 1~k
            // ���� i�� ���԰� �賶�� �ӽ� �뷮�� �ʰ��ϸ�
            if (w[i] > j)
                DP[i][j] = DP[i - 1][j]; // ���� i-1������ ��´�.
            else
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
        }
    }

    cout << DP[n][k];

    return 0;
}