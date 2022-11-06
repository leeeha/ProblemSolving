#include<iostream>
using namespace std;

int visited[50][50]; // 방문 처리를 위한 배열
int arr[50][50]; // 전체 맵 정보를 저장 (육지, 바다)

// 북0, 동3, 남2, 서1 (반시계 방향으로 돌 때마다 -1)
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int direction;

void turnLeft(){
    direction -= 1; // 왼쪽으로 회전
    if(direction == -1)
        direction = 3;
}

int main(){
    int n, m;
	cin >> n >> m;

    int x, y;
    cin >> x >> y >> direction;
    visited[x][y] = 1; // 현재 위치 방문 처리

    // 전체 맵 정보 입력 받기
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
           int x;
           cin >> x;
           arr[i][j] = x; 
        }
    }
    
    // 시뮬레이션 시작
    int cnt = 1; // 방문한 칸의 수 초기화
    int turn_time = 0; // 회전 수 초기화
    while(true){
        // 왼쪽으로 회전
        turnLeft();
        int nx = x + dx[direction];
        int ny = y + dy[direction];

         // 방문하지 않은 칸이거나 육지인 경우
        if (visited[nx][ny] == 0 && arr[nx][ny] == 0) {
            visited[nx][ny] = 1; // 방문 처리
            x = nx; // 전진
            y = ny;
            cnt += 1; // 방문한 칸의 수 갱신
            turn_time = 0; // 회전 수 초기화
            continue;
        }
        // 이미 방문한 칸이거나 바다인 경우, 다시 왼쪽으로 회전
        else turn_time += 1;

        // 네 번이나 회전했지만 갈 수 있는 방향이 없는 경우
        if (turn_time == 4) {
            // 원래 위치 (x, y)에서 후진 시도
            nx = x - dx[direction];
            ny = y - dy[direction];

            // 육지여서 갈 수 있다면 그대로 후진
            if (arr[nx][ny] == 0) {
                x = nx;
                y = ny;
            }
            // 바다로 막혀있는 경우, 게임 종료
            else break;

            // 회전 수 초기화
            turn_time = 0;
        }
    }

    cout << cnt << '\n';

    return 0;
}