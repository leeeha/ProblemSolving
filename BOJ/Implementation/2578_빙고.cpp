#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std; 

const int n = 5;
vector<vector<int>> board(n, vector<int>(n, 0));
pair<int, int> pos[25]; 

void input() {
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> board[i][j]; 
			
			// 보드판 숫자의 위치 저장 
			pos[board[i][j]] = { i, j }; 
		}
	}
}

bool checkThreeBingo() {
	int bingo = 0; 

	int diagonalLR = 0; // 왼쪽에서 오른쪽으로 가는 대각선 
	int diagonalRL = 0; // 오른쪽에서 왼쪽으로 가는 대각선 

	for(int i = 0; i < n; i++){
		int row = 0, col = 0; 
		for(int j = 0; j < n; j++){
			if(board[i][j] == 0){
				row++; 
			}
			if(board[j][i] == 0){
				col++; 
			}
		}
		if(row == 5) bingo++; 
		if(col == 5) bingo++; 

		if(board[i][i] == 0){
			diagonalLR++; 
		}

		if(board[i][n-i-1] == 0){
			diagonalRL++; 
		}
	}

	if(diagonalLR == 5) bingo++; 
	if(diagonalRL == 5) bingo++; 

	if(bingo >= 3){
		return true; 
	}

	return false; 
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); 

	input();

	int cnt = 0; 

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){ 
			int num; 
			cin >> num; 

			// num이라는 숫자가 저장된 위치를 0으로 초기화 
			board[pos[num].first][pos[num].second] = 0; 
			cnt++; 

			// 최소 10개의 숫자를 부른 뒤에 3 빙고 검사 
			if(i >= 2){
				if(checkThreeBingo()){
					cout << cnt << endl; 
					return 0; 
				}
			}
		}
	}
	
	return 0; 
}