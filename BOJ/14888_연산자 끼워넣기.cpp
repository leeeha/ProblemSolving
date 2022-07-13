#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1e9; // 10억 
int n;
int arr[11]; // 2 ≤ N ≤ 11 
int op[4]; // 각 연산자의 개수를 저장 
int maxVal = -MAX, minVal = MAX;

// cnt는 현재까지 사용한 연산자의 개수이자, arr 배열의 인덱스로 사용됨. 
// sum은 연산 결과를 저장함. 
void dfs(int plus, int minus, int mul, int div, int cnt, int result){
	// 연산자를 모두 사용했을 때
	if(cnt == n){
		maxVal = max(maxVal, result);
		minVal = min(minVal, result);
	}

	// 모든 경우의 수 탐색 
	if(plus > 0){
		dfs(plus - 1, minus, mul, div, cnt + 1, result + arr[cnt]);
	} 

	if(minus > 0){
		dfs(plus, minus - 1, mul, div, cnt + 1, result - arr[cnt]);
	}

	if(mul > 0){
		dfs(plus, minus, mul - 1, div, cnt + 1, result * arr[cnt]);
	}
	
	if(div > 0){
		dfs(plus, minus, mul, div - 1, cnt + 1, result / arr[cnt]);
	}
}

int main()
{ 
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < 4; i++){
		cin >> op[i];
	}

	dfs(op[0], op[1], op[2], op[3], 1, arr[0]);

	cout << maxVal << "\n";
	cout << minVal << "\n";
	
	return 0;
}
