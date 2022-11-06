#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // �׽�Ʈ ���̽��� ��
    int test;
    cin >> test;

    for (int i = 0; i < test; i++) {
        // n: ������ ��
        // m: ���°�� �μ�Ǿ����� �ñ��� ������ ���� ť������ ��ġ
        int n, m;
        cin >> n >> m;

        // �ε����� m�� ������ ���°�� �μ�Ǿ����� ī�����ϴ� ����
        int cnt = 0; // �� �׽�Ʈ ���̽����� 0���� �ʱ�ȭ!!!

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        int ipt; // �� ������ �߿䵵
        for (int j = 0; j < n; j++) {
            cin >> ipt;

            // �� ������ �ε����� �߿䵵�� ��� ť�� push
            q.push({ j, ipt });

            // �켱���� ť�� �߿䵵�� ���� �������� ����
            pq.push(ipt);
        }

        while (!q.empty()) {
            // ť�� front ���Ҹ� ������
            int idx = q.front().first;
            int val = q.front().second;
            q.pop();

            // �켱���� ť�� top�� �߿䵵�� ��ġ�ϸ�
            if (pq.top() == val) {
                pq.pop();
                cnt++; // ���� �ϳ� �μ��� ������ ����

                // ���� ������ �ε����� m�� ���
                if (idx == m) {
                    // ���°�� �μ�Ǿ����� ���
                    cout << cnt << '\n';
                    break; // �� ���� �׽�Ʈ ���̽��� �Ѿ��
                }
            }
            else { // �߿䵵�� ���� ������ ť�� rear�� �ٽ� push
                q.push({ idx, val });
            }
        }
    }

    return 0;
}