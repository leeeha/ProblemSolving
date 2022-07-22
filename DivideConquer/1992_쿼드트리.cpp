#include <iostream>
#include <string> 
using namespace std;

const int MAX = 64;
int arr[MAX][MAX];

void divide(int size, int r, int c){	
	// 현재 단위 사각형 내의 모든 칸들이 같은 값인지 확인 
	int cur = arr[r][c];
	
	for(int i = r; i < r + size; i++){ 
		for(int j = c; j < c + size; j++){
			if(cur != arr[i][j]){ 
				// 모두 0이나 1로 이루어질 때까지, 재귀적으로 4등분 (시계 방향) 
				cout << "(";
				divide(size / 2, r, c); // 2사분면 
				divide(size / 2, r, c + size / 2); // 1사분면 
				divide(size / 2, r + size / 2, c); // 3사분면 
				divide(size / 2, r + size / 2, c + size / 2); // 4사분면 
				cout << ")"; 
				return; 
			}
		}
	}
	
	// 모두 0이거나 1이면 그대로 출력 
	cout << cur; 
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	int n; 
	cin >> n;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s; 

		// 길이가 n인 문자열의 문자 하나하나를 정수로 변환해서 저장 
		for(int j = 0; j < n; j++){
			arr[i][j] = s[j] - '0'; 
		}
	}

	divide(n, 0, 0); 
	
	return 0;
}
