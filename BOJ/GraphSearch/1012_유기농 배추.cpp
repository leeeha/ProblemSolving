#include <iostream>
#include <cstring> 
#define MAX 51	
using namespace std;

int n, m, k; 
int graph[MAX][MAX]; // 0으로 초기화 
bool visited[MAX][MAX]; // false로 초기화 

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y){
	visited[x][y] = true;

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
		cin >> n >> m >> k; 

		while(k--){ 
			int x, y; 
			cin >> x >> y; 
			graph[x][y] = 1; 
		}

		int count = 0; // 필요한 지렁이의 최소 개수 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				// 방문하지 않은 칸을 발견하면  
				if(graph[i][j] == 1 && !visited[i][j]){
					count++; 
					dfs(i, j); 
				}
			}
		}

		// 개행 문자 잊지 말자! 
		cout << count << endl; 

		// 각 테스트 케이스마다 배열 초기화 시켜줘야 한다! 
		memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
	}
	
	return 0; 
}