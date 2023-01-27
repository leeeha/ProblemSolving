#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include <utility>
using namespace std;

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

string board[50];

int countWB(int x, int y){
	int cnt = 0; 
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(board[x+i][y+j] != WB[i][j])
				cnt++; 
		}
	}
	return cnt; 
}

int countBW(int x, int y){
	int cnt = 0; 
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(board[x+i][y+j] != BW[i][j])
				cnt++; 
		}
	}
	return cnt; 
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m, n; 
	cin >> m >> n; 

	for(int i = 0; i < m; i++){ 
		cin >> board[i]; 
	}

	int minValue = 1e9; 
	for(int i = 0; i + 8 <= m; i++){ 
		for(int j = 0; j + 8 <= n; j++){ 
			int temp = min(countWB(i, j), countBW(i, j));
			if(minValue > temp){
				minValue = temp; 
			}
		}
	}

	cout << minValue; 
	
	return 0;
}