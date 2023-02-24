#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 

int dp[21][21][21]; 

// top-down (�����, ����Լ�, �޸������̼�) 
int w(int a, int b, int c){
	// a, b, c �߿� ��� �ϳ��� 0�̰ų� ������ ��� 
	if(a <= 0 || b <= 0 || c <= 0){
		return 1; 
	}

	// a, b, c �߿� ��� �ϳ��� 20���� ū ��� 
	if(a > 20 || b > 20 || c > 20){
		return w(20, 20, 20); 
	}

	// a, b, c�� 0���� ũ�鼭 20���� �۰ų� ����. 
	// dp ���̺� ����� ���� ������ �״�� ����Ѵ�. 
	if(dp[a][b][c] != 0){ 
		return dp[a][b][c]; 
	}

	// �޸������̼� 
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