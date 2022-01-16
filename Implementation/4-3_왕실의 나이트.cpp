#include<iostream>
using namespace std;

int dx[] = {-1, 1, -1, 1, -2, -2, 2, 2};
int dy[] = {2, 2, -2, -2, 1, -1, 1, -1};

int main(){
    char cy, cx;
    cin >> cy >> cx;

    int y, x; // 현위치 초기화
    y = cy - 'a' + 1;
    x = cx - '0';

	// 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
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