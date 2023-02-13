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

	// ���� ��ġ�� ����� �����¿� Ž�� 
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
		// ���� m, ���� n 
		cin >> m >> n >> k; 

		while(k--){
			int x, y; 
			cin >> x >> y; // ���� x, ���� y 
			graph[y][x] = 1; // y�� ��, x�� �� 
		}

		int cnt = 0; 
		// Į�� m, �� n 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(graph[i][j] == 1 && !visited[i][j]){
					cnt++; // �ʿ��� �������� �� ������Ʈ 
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
