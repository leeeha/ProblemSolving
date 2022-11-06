#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    string s;
    cin >> s;

    // ���� �ϳ��� ���Ḯ��Ʈ�� �߰�
    list<char> l(s.begin(), s.end());

    //list<char>::iterator now = l.end();
    auto cur = l.end();
    // end()�� ������ ���� �ٷ� ���� ��ġ�� ����Ŵ.

    int n;
    cin >> n;

    while (n--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cur != l.begin()) {
                cur--; // ���� �̵�
            }
        }
        else if (cmd == 'D') {
            if (cur != l.end()) {
                cur++; // ������ �̵�
            }
        }
        else if (cmd == 'B') {
            if (cur != l.begin()) {
                cur = l.erase(--cur);
                // Ŀ���� ���� ���� ����
            }
        }
        else if (cmd == 'P') {
            char c;
            cin >> c;
            l.insert(cur, c);
            // Ŀ���� �ٷ� �պκп� ����
        }
    }

    /*for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }*/
    for (auto& e : l) { // ���� ��� for��
        cout << e;
    }

    return 0;
}