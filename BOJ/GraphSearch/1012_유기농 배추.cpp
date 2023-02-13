#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
using namespace std;

const int MAX = 51;
int graph[MAX][MAX]; 
bool visited[MAX][MAX];

int n, m, k;  
int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 

void dfs(int x, int y){
	visited[x][y] = true;

	// 현재 위치와 연결된 상하좌우 탐색 
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 

		if(graph[nx][ny] == 1 && !visited[nx][ny]){ 
			dfs(nx, ny); 
		}
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 

	int t; 
	cin >> t; 

	while(t--){
		// 가로 m, 세로 n 
		cin >> m >> n >> k; 

		while(k--){
			int x, y; 
			cin >> x >> y; // 가로 x, 세로 y 
			graph[y][x] = 1; // y는 행, x는 열 
		}

		int cnt = 0; 
		// 칼럼 m, 행 n 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(graph[i][j] == 1 && !visited[i][j]){
					cnt++; // 필요한 지렁이의 수 업데이트 
					dfs(i, j); 
				}
			}
		} 
		cout << cnt << "\n"; 

		memset(graph, 0, sizeof(graph));
		memset(visited, 0, sizeof(visited));
	}

    return 0;
}
