#include <iostream>
#define MAX 200
using namespace std;

int r, c, n; // 1 ≤ R, C, N ≤ 200
int bombTime[MAX][MAX];
char mat[MAX][MAX];

// 상하좌우
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 짝수 초일 때 폭탄 설치 
void installBomb(int time){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(mat[i][j] == 'O') 
				continue;
				
			// 폭탄이 설치되지 않은 곳에만 새로 설치
			mat[i][j] = 'O';

			// 현재 시간으로부터 3초 뒤에 터진다. (2->5, 4->7)
			bombTime[i][j] = time + 3; 
		}
	}
}

// 홀수 초일 때 폭탄 파괴 
void deleteBomb(int time){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(bombTime[i][j] == time){
				mat[i][j] = '.'; // 자신의 칸 파괴
				
				// 상하좌우 파괴 
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];

					if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if(mat[nx][ny] == '.') continue;

					mat[nx][ny] = '.';
				}

				// 현재 칸의 폭탄 터지는 시간 업데이트  
				bombTime[i][j] = 0; 
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	cin >> r >> c >> n;

	// 초기 상태 입력 받기 
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> mat[i][j];

			// (i, j)에  있는 폭탄이 3초 뒤에 터진다.
			if(mat[i][j] == 'O'){
				bombTime[i][j] = 3;
			}
		}
	}

	int time = 2; 
	while(1){
		// n초가 지났을 때 루프 종료 
		if(time == n + 1) break; 

		// 짝수 초일 때 폭탄 설치 
		if(time % 2 == 0){
			installBomb(time);
		}else{ 
			// 홀수 초일 때 폭탄 파괴 
			deleteBomb(time);
		}

		time++;
	}

	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cout << mat[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}