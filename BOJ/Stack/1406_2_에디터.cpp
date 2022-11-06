#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> l;
    stack<char> r;

    // 왼쪽 스택에 입력된 모든 문자를 push
    for (int i = 0; i < s.size(); i++) {
        l.push(s[i]);
    }

    int num;
    cin >> num;
    while (num--) { // num == 0이면 종료
        char cmd;
        cin >> cmd;

        // P: 왼쪽 스택의 top에 추가
        if (cmd == 'P') {
            char c;
            cin >> c;
            l.push(c);
        }
        // B: 왼쪽 스택이 비어있지 않다면, 왼쪽의 top 삭제
        else if (cmd == 'B') {
            if (l.empty()) continue;
            else l.pop();
        }
        // L: 왼쪽 스택이 비어있지 않다면, 왼쪽의 top을 오른쪽에 push
        else if (cmd == 'L') {
            if (l.empty()) continue;
            else {
                r.push(l.top());
                l.pop();
            }
        }
        // D: 오른쪽 스택에 비어있지 않다면, 오른쪽의 top을 왼쪽에 push
        else if (cmd == 'D') {
            if (r.empty()) continue;
            else {
                l.push(r.top());
                r.pop();
            }
        }
    }

    // 왼쪽 스택 전체를 오른쪽 스택에 push 
    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }

    // 오른쪽 스택 전체 출력
    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }

    return 0;
}