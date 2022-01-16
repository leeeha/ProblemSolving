#include<iostream>
using namespace std;

int visited[50][50]; // �湮 ó���� ���� �迭
int arr[50][50]; // ��ü �� ������ ���� (����, �ٴ�)

// ��0, ��3, ��2, ��1 (�ݽð� �������� �� ������ -1)
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int direction;

void turnLeft(){
    direction -= 1; // �������� ȸ��
    if(direction == -1)
        direction = 3;
}

int main(){
    int n, m;
	cin >> n >> m;

    int x, y;
    cin >> x >> y >> direction;
    visited[x][y] = 1; // ���� ��ġ �湮 ó��

    // ��ü �� ���� �Է� �ޱ�
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
           int x;
           cin >> x;
           arr[i][j] = x; 
        }
    }
    
    // �ùķ��̼� ����
    int cnt = 1; // �湮�� ĭ�� �� �ʱ�ȭ
    int turn_time = 0; // ȸ�� �� �ʱ�ȭ
    while(true){
        // �������� ȸ��
        turnLeft();
        int nx = x + dx[direction];
        int ny = y + dy[direction];

         // �湮���� ���� ĭ�̰ų� ������ ���
        if (visited[nx][ny] == 0 && arr[nx][ny] == 0) {
            visited[nx][ny] = 1; // �湮 ó��
            x = nx; // ����
            y = ny;
            cnt += 1; // �湮�� ĭ�� �� ����
            turn_time = 0; // ȸ�� �� �ʱ�ȭ
            continue;
        }
        // �̹� �湮�� ĭ�̰ų� �ٴ��� ���, �ٽ� �������� ȸ��
        else turn_time += 1;

        // �� ���̳� ȸ�������� �� �� �ִ� ������ ���� ���
        if (turn_time == 4) {
            // ���� ��ġ (x, y)���� ���� �õ�
            nx = x - dx[direction];
            ny = y - dy[direction];

            // �������� �� �� �ִٸ� �״�� ����
            if (arr[nx][ny] == 0) {
                x = nx;
                y = ny;
            }
            // �ٴٷ� �����ִ� ���, ���� ����
            else break;

            // ȸ�� �� �ʱ�ȭ
            turn_time = 0;
        }
    }

    cout << cnt << '\n';

    return 0;
}