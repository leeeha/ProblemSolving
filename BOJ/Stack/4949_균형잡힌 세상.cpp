#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isCouple(char a, char b) {
    if (a == '(' && b == ')')
        return true;
    else if (a == '[' && b == ']')
        return true;
    else
        return false;
}

bool isBalance(string str) {
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        // 여는 괄호는 스택에 push
        if (ch == '(' || ch == '[') {
            s.push(ch);
        }
        // 닫는 괄호가 들어왔을 때
        else if (ch == ')' || ch == ']') {
            if (!s.empty()) {
                // 스택의 top에 있는 열린 괄호와 짝이 맞으면
                if (isCouple(s.top(), ch)) {
                    s.pop(); // 열린 괄호 pop
                }
                else { // 짝이 안 맞으면 false
                    return false;
                }
            }
            else { // 스택이 비어있으면 false
                return false;
            }
        }
    }

    // 반복문이 끝난 뒤 스택에 남은 괄호가 없으면 true
    return s.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    while (true) {
        // 엔터를 기준으로 한줄씩 입력 받기
        getline(cin, str, '\n');

        // 점 하나만 입력된 경우 프로그램 종료
        if (str.size() == 1 && str[0] == '.')
            break;

        if (isBalance(str)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}