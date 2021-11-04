#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; // �ִ� 50����

    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size() != 1) {
        // 1. �� �տ� �ִ� ī�� pop
        q.pop();

        // 2. �� ���� �� �տ� �ִ� ī�带 �� �ڷ� push
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    cout << q.front();

    return 0;
}