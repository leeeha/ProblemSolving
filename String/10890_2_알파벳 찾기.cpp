#include <iostream>
#include <string>
using namespace std;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    string str;
    cin >> str;

    for (int i = 0; i < alphabet.length(); i++) {
        // str���� i��° ���ĺ��� �߰��ϸ�, �߰��� �� ��ġ�� ����ϱ�
        // �� �ܾ ���� ���ڰ� ���� �� ��������
        // find �Լ��� �տ������� Ž���� �ϴϱ� ���ڸ� ó�� �߰��� ��ġ�� ����Ѵ�.
        cout << (int)str.find(alphabet[i]) << " ";
    }

    return 0;
}