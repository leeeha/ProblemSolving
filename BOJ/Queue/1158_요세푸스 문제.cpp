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
        // k번째 원소 삭제
        if (count % K == 0) {
            int ans = q.front();
            q.pop();

            // 아직 남은 원소가 있으면 콤마
            if (!q.empty()) cout << ans << ", ";
            else {
                cout << ans << ">";
                break;
            }
        }
        else { // k번째 원소가 아니면 pop해서 맨 뒤에 다시 push
            int num = q.front();
            q.pop();
            q.push(num);
        }
        count++;
    }
}