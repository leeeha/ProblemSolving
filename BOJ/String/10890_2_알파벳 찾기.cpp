#include <iostream>
#include <string>
using namespace std;

int main() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    string str;
    cin >> str;

    for (int i = 0; i < alphabet.length(); i++) {
        // str에서 i번째 알파벳을 발견하면, 발견한 그 위치를 출력하기
        // 한 단어에 같은 문자가 여러 번 나오더라도
        // find 함수는 앞에서부터 탐색을 하니까 문자를 처음 발견한 위치를 출력한다.
        cout << (int)str.find(alphabet[i]) << " ";
    }

    return 0;
}