#include<iostream>
using namespace std;

int dx[] = {-1, 1, -1, 1, -2, -2, 2, 2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};

int main(){
    char cy, cx;
    cin >> cy >> cx;

    int y, x; // ����ġ �ʱ�ȭ
    y = cy - 'a' + 1;
    x = cx - '0';

	// 8���� ���⿡ ���Ͽ� �� ��ġ�� �̵��� �������� Ȯ��
    int count = 0;
    for(int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if((nx >= 1 && nx <= 8) && (ny >= 1 && ny <= 8))
            count++;
    }

    cout << count << '\n';

    return 0;
}