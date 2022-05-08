#include <iostream>
#define MAX 200
using namespace std;

int r, c, n; // 1 �� R, C, N �� 200
int bombTime[MAX][MAX];
char mat[MAX][MAX];

// �����¿�
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// ¦�� ���� �� ��ź ��ġ 
void installBomb(int time){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(mat[i][j] == 'O') 
				continue;
				
			// ��ź�� ��ġ���� ���� ������ ���� ��ġ
			mat[i][j] = 'O';

			// ���� �ð����κ��� 3�� �ڿ� ������. (2->5, 4->7)
			bombTime[i][j] = time + 3; 
		}
	}
}

// Ȧ�� ���� �� ��ź �ı� 
void deleteBomb(int time){
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(bombTime[i][j] == time){
				mat[i][j] = '.'; // �ڽ��� ĭ �ı�
				
				// �����¿� �ı� 
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k];
					int ny = j + dy[k];

					if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if(mat[nx][ny] == '.') continue;

					mat[nx][ny] = '.';
				}

				// ���� ĭ�� ��ź ������ �ð� ������Ʈ  
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

	// �ʱ� ���� �Է� �ޱ� 
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> mat[i][j];

			// (i, j)��  �ִ� ��ź�� 3�� �ڿ� ������.
			if(mat[i][j] == 'O'){
				bombTime[i][j] = 3;
			}
		}
	}

	int time = 2; 
	while(1){
		// n�ʰ� ������ �� ���� ���� 
		if(time == n + 1) break; 

		// ¦�� ���� �� ��ź ��ġ 
		if(time % 2 == 0){
			installBomb(time);
		}else{ 
			// Ȧ�� ���� �� ��ź �ı� 
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