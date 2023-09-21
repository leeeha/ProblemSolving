#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // pair�� first�� ��������, ������ ���� ���� ���Ұ� �켱���� ť�� top�� ��ġ��.
    // ����� ���� ������ �ƴ� ���� ������ ���
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
            // ������ �������� top�� ��ġ�ϵ���
            pq.push({ abs(x), x });
        }
    }

    return 0;
}
