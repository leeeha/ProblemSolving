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

        // ���� ��ȣ�� ���ÿ� push
        if (ch == '(' || ch == '[') {
            s.push(ch);
        }
        // �ݴ� ��ȣ�� ������ ��
        else if (ch == ')' || ch == ']') {
            if (!s.empty()) {
                // ������ top�� �ִ� ���� ��ȣ�� ¦�� ������
                if (isCouple(s.top(), ch)) {
                    s.pop(); // ���� ��ȣ pop
                }
                else { // ¦�� �� ������ false
                    return false;
                }
            }
            else { // ������ ��������� false
                return false;
            }
        }
    }

    // �ݺ����� ���� �� ���ÿ� ���� ��ȣ�� ������ true
    return s.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;

    while (true) {
        // ���͸� �������� ���پ� �Է� �ޱ�
        getline(cin, str, '\n');

        // �� �ϳ��� �Էµ� ��� ���α׷� ����
        if (str.size() == 1 && str[0] == '.')
            break;

        if (isBalance(str)) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}