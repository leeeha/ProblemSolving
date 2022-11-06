#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    string s;
    cin >> s;

    // 문자 하나씩 연결리스트에 추가
    list<char> l(s.begin(), s.end());

    //list<char>::iterator now = l.end();
    auto cur = l.end();
    // end()는 마지막 원소 바로 다음 위치를 가리킴.

    int n;
    cin >> n;

    while (n--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (cur != l.begin()) {
                cur--; // 왼쪽 이동
            }
        }
        else if (cmd == 'D') {
            if (cur != l.end()) {
                cur++; // 오른쪽 이동
            }
        }
        else if (cmd == 'B') {
            if (cur != l.begin()) {
                cur = l.erase(--cur);
                // 커서의 왼쪽 원소 삭제
            }
        }
        else if (cmd == 'P') {
            char c;
            cin >> c;
            l.insert(cur, c);
            // 커서의 바로 앞부분에 삽입
        }
    }

    /*for (auto it = l.begin(); it != l.end(); it++) {
        cout << *it;
    }*/
    for (auto& e : l) { // 범위 기반 for문
        cout << e;
    }

    return 0;
}