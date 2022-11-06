#include <iostream>
using namespace std;

int n, white, blue;
int arr[128][128];

void dfs(int r, int c, int size){
	bool zero, one;
	zero = one = true;

	for(int i = r; i < r + size; i++){
		for(int j = c; j < c + size; j++){
			if(arr[i][j] == 1) zero = false;
			if(arr[i][j] == 0) one = false; 
		}
	}
	
	if(zero == true) {
		white++;
		return;
	}

	if(one == true){
		blue++;
		return; 
	}

	// 정사각형 내부가 모두 0이거나 모두 1이 아니면 
	// "현재 길이 / 2"로 사각형을 쪼개서 탐색 진행 
	dfs(r, c, size / 2); // 왼쪽 위 
	dfs(r, c + size / 2, size / 2); // 오른쪽 위 
	dfs(r + size / 2, c, size / 2); // 왼쪽 아래 
	dfs(r + size / 2, c + size / 2, size / 2); // 오른쪽 아래 
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> arr[i][j]; 
		}
	}

	dfs(0, 0, n); 

	cout << white << "\n" << blue; 
	
	return 0;
}
