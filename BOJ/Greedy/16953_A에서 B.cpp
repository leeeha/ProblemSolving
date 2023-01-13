#include <iostream>
#include <algorithm>
using namespace std; 

int A, B; // �ִ� 1�� 
int ans = 1e9; 

void dfs(long long num, int depth) { 
	if(num > B) return; 
	if(num == B) {
		ans = min(ans, depth);
		return; 
	}
	dfs(num * 2, depth + 1);
	dfs(num * 10 + 1, depth + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B; 
	dfs(A, 1); // ������ ����, ������ Ƚ�� 

	if(ans == 1e9) cout << "-1";
	else cout << ans; 

	return 0; 
}
