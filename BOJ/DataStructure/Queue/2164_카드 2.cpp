#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n; // 최대 50만개

    queue<int> q;

    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size() != 1) {
        // 1. 맨 앞에 있는 카드 pop
        q.pop();

        // 2. 그 다음 맨 앞에 있는 카드를 맨 뒤로 push
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    cout << q.front();

    return 0;
}