#include <iostream>
using namespace std;

int arr[9][9];

bool promising(int r, int c, int a){ 
	for(int i = 0; i < 9; i++){
		// 현재 행에 겹치는 숫자가 있으면 
		if(arr[r][i] == a) return false; 
		// 현재 열에 겹치는 숫자가 있으면 
		if(arr[i][c] == a) return false;
	}

	// 3x3 사각형 내에 겹치는 숫자가 있으면 
	for(int i = (r/3) * 3; i < (r/3) * 3 + 3; i++){
		for(int j = (c/3) * 3; j < (c/3) * 3 + 3; j++){
			if(arr[i][j] == a) return false; 
		}
	}

	// 모든 조건을 충족하면 true 
	return true; 
}

void dfs(int r, int c){ 
	// 행의 끝까지 오면 결과 출력 
	if(r == 9){ 
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}

	// 열의 끝까지 오면, 다음 행의 첫번째 열로 이동 
	if(c == 9) dfs(r + 1, 0); 

	// 빈칸에 1~9까지 넣어본다. 
	if(arr[r][c] == 0){ 
		for(int i = 1; i <= 9; i++){
			// 유망성 판단 
			if(promising(r, c, i)){ 
				arr[r][c] = i; // 상태 변화 
				dfs(r, c + 1); // 재귀 호출 (다음 열로 이동) 
				arr[r][c] = 0; // 상태 복구 
			}
		}
	}else{
		// 다음 열로 이동 
		dfs(r, c + 1); 
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> arr[i][j]; 
		}
	}

	dfs(0, 0); 
	
	return 0;
}