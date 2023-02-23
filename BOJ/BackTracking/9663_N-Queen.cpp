#include <iostream>
using namespace std;

int n; 
int queen_col[15]; // 퀸이 놓일 열의 위치를 저장 
int cnt = 0; 

// 유망한지 판단하는 함수 
bool promising(int row) { 
	// 같은 열과 대각선 상에 있으면 안 된다. 
	// 두 퀸이 대각선상에 놓이면 행과 열의 거리 차이가 같다. 
	for(int i = 0; i < row; i++){
		if(queen_col[row] == queen_col[i] || 
			row - i == abs(queen_col[row] - queen_col[i])){ 
			return false;
		}
	}
	
	return true; 
}


// nqueen 알고리즘 수행
void nqueen(int row) {
	// n번째 행까지 n개의 퀸을 놓는 경우의 수를 하나 찾았다면 
	if(row == n){ 
		cnt++;  // 개수 갱신하고 
		return; // 현재 열에 대한 재귀 호출 종료 
    }
   
    for(int col = 0; col < n; col++){
        // 현재 행에서 모든 열 검사 
        queen_col[row] = col; // (row, col)에 퀸을 놓아본다. 
        
        // 유망하다면 서브 트리로 이동 
        // 아니면 더이상 재귀 호출하지 않고 바로 다음 열로 백트래킹 (가지치기)
        if(promising(row)){  // 유망하다면 
            nqueen(row + 1); // 그 다음 행에 퀸을 놓아본다. (재귀 호출) 
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	nqueen(0); // 0번째 행부터 시작
	cout << cnt; 
	
	return 0;
}