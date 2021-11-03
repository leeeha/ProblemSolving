#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isVPS(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '(') { // 여는 괄호는 push
            s.push(str[i]);
        }
        else { // 닫는 괄호가 스택에 들어올 때 
            if (s.empty()) { // 스택이 비어있으면 
                return false; // not VPS
            }
            else { // 스택이 비어 있지 않으면
                s.pop(); // top에 있는 여는 괄호 pop!
            }
        }
    }

    // 반복문이 끝나고 스택에 남은 괄호가 없으면 true
    return s.empty();
}

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (isVPS(str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
