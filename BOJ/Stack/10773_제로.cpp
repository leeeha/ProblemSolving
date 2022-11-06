#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> s;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;

        if (num == 0)
            s.pop(); // top ���� ����
        else
            s.push(num);
    }

    int sum = 0;
    while (!s.empty()) {
        sum += s.top();
        s.pop(); // ���� ���� ����!!!!
    }

    cout << sum;

    return 0;
}