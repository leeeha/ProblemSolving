#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
using namespace std;

int t, n;
int answer = 0;

void dfs(int sum){
	// 1 or 2 or 3을 더해서 n이 되면 결과 처리 후 
	// 더 이상 깊이 들어가지 않고 다음 경우의 수 탐색
	if(sum == n){
		answer++;
		return;
	}

	if(sum > n) return;

	// 중복 순열 (인덱스 1부터 시작)
	for(int i = 1; i <= 3; i++){ 
		dfs(sum + i); 
	}
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	cin >> t; 

	while(t--){
		cin >> n;
		
		dfs(0);
		cout << answer << endl;
		answer = 0; 
	}
	
	return 0;
}