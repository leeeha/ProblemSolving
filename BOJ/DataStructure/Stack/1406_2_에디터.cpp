#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> l;
    stack<char> r;

    // ���� ���ÿ� �Էµ� ��� ���ڸ� push
    for (int i = 0; i < s.size(); i++) {
        l.push(s[i]);
    }

    int num;
    cin >> num;
    while (num--) { // num == 0�̸� ����
        char cmd;
        cin >> cmd;

        // P: ���� ������ top�� �߰�
        if (cmd == 'P') {
            char c;
            cin >> c;
            l.push(c);
        }
        // B: ���� ������ ������� �ʴٸ�, ������ top ����
        else if (cmd == 'B') {
            if (l.empty()) continue;
            else l.pop();
        }
        // L: ���� ������ ������� �ʴٸ�, ������ top�� �����ʿ� push
        else if (cmd == 'L') {
            if (l.empty()) continue;
            else {
                r.push(l.top());
                l.pop();
            }
        }
        // D: ������ ���ÿ� ������� �ʴٸ�, �������� top�� ���ʿ� push
        else if (cmd == 'D') {
            if (r.empty()) continue;
            else {
                l.push(r.top());
                r.pop();
            }
        }
    }

    // ���� ���� ��ü�� ������ ���ÿ� push 
    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }

    // ������ ���� ��ü ���
    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }

    return 0;
}