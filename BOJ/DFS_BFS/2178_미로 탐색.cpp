#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> 
#include <cstring> 
#include <queue>
using namespace std;

const int MAX = 101; 
int graph[MAX][MAX]; 
bool visited[MAX][MAX]; 

int n, m; 
int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1}; 

int bfs(int x, int y){ 
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = true;

	while(!q.empty()){ 
		int row = q.front().first; 
		int col = q.front().second;
		q.pop(); 

		// 현재 노드와 상하좌우로 연결된 노드 탐색 
		for(int i = 0; i < 4; i++){ 
			int nx = row + dx[i]; 
			int ny = col + dy[i]; 
	
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
	
			if(graph[nx][ny] == 1 && !visited[nx][ny]){ 
				graph[nx][ny] = graph[row][col] + 1; 
				q.push({nx, ny}); 
				visited[nx][ny] = true; 
			}
		}
	}
	
	return graph[n - 1][m - 1]; 
}

int main() {
	//ios::sync_with_stdio(0); 
	cin.tie(0); 

	cin >> n >> m;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%1d", &graph[i][j]); 
		}
	}

	cout << bfs(0, 0);

    return 0;
}