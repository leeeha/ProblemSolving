#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    cout << "<";
    int count = 1;
    while (!q.empty()) {
        // k��° ���� ����
        if (count % K == 0) {
            int ans = q.front();
            q.pop();

            // ���� ���� ���Ұ� ������ �޸�
            if (!q.empty()) cout << ans << ", ";
            else {
                cout << ans << ">";
                break;
            }
        }
        else { // k��° ���Ұ� �ƴϸ� pop�ؼ� �� �ڿ� �ٽ� push
            int num = q.front();
            q.pop();
            q.push(num);
        }
        count++;
    }
}