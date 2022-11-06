#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // pair의 first를 기준으로, 절댓값이 가장 작은 원소가 우선순위 큐의 top에 위치함.
    // 출력할 때는 절댓값이 아닌 원래 값으로 출력
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x == 0) {
            if (pq.empty())
                cout << "0\n";
            else {
                cout << pq.top().second << "\n";
                pq.pop();
            }
        }
        else {
            // 절댓값이 작을수록 top에 위치하도록
            pq.push({ abs(x), x });
        }
    }

    return 0;
}
