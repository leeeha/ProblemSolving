#include <iostream> 
#include <vector> 
#include <string>
#include <algorithm>
#include <queue> 
using namespace std;

const int MAX = 501;
int height[MAX][MAX]; 
int dp[MAX][MAX];

int m, n;
int cnt = 0;
int dx[] = {0, 0, -1, 1}; 
int dy[] = {-1, 1, 0, 0}; 

void input() {
	cin >> m >> n; 

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> height[i][j]; 
			dp[i][j] = -1; 
		}
	}
}

int dfs(int x, int y){ 
	if(x == m - 1 && y == n - 1) return 1; // --- (a) 
	if(dp[x][y] != -1) return dp[x][y]; // --- (b) 

	dp[x][y] = 0;
	for(int i = 0; i < 4; i++){ 
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue; 

		if(height[x][y] > height[nx][ny]){
			dp[x][y] += dfs(nx, ny); 
		}
	}

	return dp[x][y]; // --- (c) 
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);

	input();

	cout << dfs(0, 0); 
	
	return 0;
}