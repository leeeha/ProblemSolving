#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 

int dp[21][21][21]; 

// top-down (하향식, 재귀함수, 메모이제이션) 
int w(int a, int b, int c){
	// a, b, c 중에 적어도 하나가 0이거나 음수인 경우 
	if(a <= 0 || b <= 0 || c <= 0){
		return 1; 
	}

	// a, b, c 중에 적어도 하나가 20보다 큰 경우 
	if(a > 20 || b > 20 || c > 20){
		return w(20, 20, 20); 
	}

	// a, b, c는 0보다 크면서 20보다 작거나 같다. 
	// dp 테이블에 저장된 값이 있으면 그대로 사용한다. 
	if(dp[a][b][c] != 0){ 
		return dp[a][b][c]; 
	}

	// 메모이제이션 
	if(a < b && b < c){
		dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c); 
		return dp[a][b][c]; 
	}

	dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1); 
	return dp[a][b][c]; 
}

int main()
{
	while(true){
		int a, b, c; 
		cin >> a >> b >> c; 
		
		if(a == -1 && b == -1 && c == -1){ 
			break; 
		}

		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c)); 
	}

	return 0; 
}