#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isVPS(string str) {
    stack<char> s;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (ch == '(') { // ���� ��ȣ�� push
            s.push(str[i]);
        }
        else { // �ݴ� ��ȣ�� ���ÿ� ���� �� 
            if (s.empty()) { // ������ ��������� 
                return false; // not VPS
            }
            else { // ������ ��� ���� ������
                s.pop(); // top�� �ִ� ���� ��ȣ pop!
            }
        }
    }

    // �ݺ����� ������ ���ÿ� ���� ��ȣ�� ������ true
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
